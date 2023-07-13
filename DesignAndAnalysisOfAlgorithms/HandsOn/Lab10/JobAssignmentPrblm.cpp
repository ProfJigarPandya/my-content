#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

int **skillset=NULL;
int n;
int *result=NULL;
int assignJobs();
void display_result();
int findOverAllLowestBoundSumOfMinimums();
int findOverAllUpperBoundDiagonalSum();
int sumOfLowestAfterAssigned(int *assignments);

struct snode
{
	int *pdata;
	struct snode *next;
};

struct snode *result_head=NULL;
int insertLinearSLLRear(struct snode **phead, int data[]);
int traverseSLL(struct snode *head);
int removeLinearSLLFront(struct snode **phead);

//MinHeap binary
struct HeapData 
{
    int keyInfo;//based on which heap is constructed. priority. to be minimum first retrieved.
    int *assignments;
};
struct Heap
{
	struct Node *pHeapTreeRootListStart;
	struct Node *pListLast;
	int numberOfNodes;//This is to avoid calculating every time. But need to make sure updated correctly. It can be derived actually.
};
struct Node{
	struct HeapData data;
	struct Node *treeLeft, *treeRight, *treeParent, *listNext, *listPrev;
};
int isEmptyHeap(struct Heap* pHeap);
void displayHeapNodeData(struct HeapData *pheapdata);
void insertHeap(struct Heap* pHeap, struct HeapData data);
int removeElementFromHeap(struct Heap* pHeap,struct HeapData * pdata);
void traverseHeapLinkedListForward(struct Heap heap);
void traverseHeapLinkedListBackword(struct Heap heap);
void traverseTreeInOrder(struct Node *pRoot);
struct Node* addressOfNodeByNumber(struct Node *start, int position);
int sumOfActualAfterAssigned(int *assingments);
int main()
{
    ifstream fis;
    fis.open("C:\\Users\\jigar\\OneDrive\\Documents\\DAA\\prog\\DAA\\JobAssignmentP\\inputJobAssignment1.txt",std::ios_base::in);
    if(fis.fail())
    {
        cout<<"Data file could not be opened";
        return 1;
    }
	int exampleno=1;
    do
    {
	cout<<"\n Example # "<<exampleno++;
    fis>>n;
    cout<<"\n For n nodes "<<n;
    skillset=new int*[n+1];
    result=new int[n+1];
    int i;
    for(i=0;i<=n;i++)
    {
        skillset[i]=new int [n+1];
        result[i]=0;
    }
    for(int r=1;r<=n;r++)
    {
        for(int c=1;c<=n;c++)
        {
            fis>>skillset[r][c];
        }
    }


    cout<<"\nSkillSet data\n";
    for(int r=1;r<=n;r++)
    {
        for(int c=1;c<=n;c++)
        {
            cout<<skillset[r][c]<<"\t";
        }
        cout<<"\n";
    }


    cout<<"\nJob Assignment ....\n";
    int totalSolutoins=assignJobs();
    if(totalSolutoins)
    {
        cout<<"\nTotal solutoins found are "<<totalSolutoins;
		traverseSLL(result_head);
    }
    else
    {
        //cout<<"\nNo solution found";//You will always have solution.
    }
    //display_result();
	cout<<"\n\n";
    for(i=0;i<=n;i++)
    {
        delete [] skillset;
    }
    delete skillset;
	//discard previos results
	while(removeLinearSLLFront(&result_head));
    }while(!fis.eof());
    fis.close();
    cout<<"\n Have a nice day.";
    return(0);

}


void display_result()
{
	int totalcost=0;
    cout<<"\n";
	cout<<"\nPerson#   Task#\n";
    for(int i=1;i<=n;i++)
	{
        cout<<setw(5)<<i<<setw(10)<<result[i]<<"\n";
		totalcost+=skillset[i][result[i]];
	}
	cout<<"\nTotal cost is "<<totalcost;
}


int assignJobs()
{
    int totalSolutions=0;
    int knownLowestBound, knownUpperBound;
    knownLowestBound=findOverAllLowestBoundSumOfMinimums();
    //cout<<"\nKnown Lowest Bound "<<knownLowestBound;
    knownUpperBound=findOverAllUpperBoundDiagonalSum();
    //cout<<"\nKnown Upper Bound (Diagonal) "<<knownUpperBound;

    //Get ready the min heap
	struct Heap heap;
	heap.pHeapTreeRootListStart=heap.pListLast=NULL;
	heap.numberOfNodes=0;

    int task, thisLB;
	
    //To person1, fix tasks from the list one after another and record costs into heap
    int person=1;
    for(task=1;task<=n;task++)
    {   
		int *assignments=new int[n+1];
        for(int ii=0;ii<=n;ii++)
            assignments[ii]=0;
        assignments[person]=task;
		
        thisLB=sumOfActualAfterAssigned(assignments)+sumOfLowestAfterAssigned(assignments);
        //cout<<"\n (person# "<<person<<" task# "<<task<<" at upper bound "<<thisLB<<")";

        //If this lower bound is higher than known upper bound, do not go forward with it. Else insert into heap.
        if(thisLB<=knownUpperBound)//Equal ??
        {
            //insert into minheap
            struct HeapData data;
            data.keyInfo=thisLB;
            data.assignments=new int[n+1];
            for(int ii=0;ii<=n;ii++)
                data.assignments[ii]=0;
            data.assignments[person]=task;
            insertHeap(&heap,data);
            //Traverse as part of debugging
            //cout<<"\n Call to traversal: ";
            //cout<<"\n Linked list forward : ";traverseHeapLinkedListForward(heap);
        }
        else
        {
            //cout<<"\nPerson# "<<person<<" Task# "<<task<<" : "<<thisLB<<" is higher than "<<knownUpperBound<<" hence discarded for further processing.";
        }
    }



    //What if heap is empty? Not possible. Atleast the first diagonal know solution has to match.
    
	do
	{
		//retrieve from the minheap; most promising route as of now.
		struct HeapData livenode;
		if(!removeElementFromHeap(&heap,&livenode))
		{
			//cout<<"Heap is empty. Branch and bound search ends now.";
			return totalSolutions;
		}
		
		if(livenode.keyInfo>knownUpperBound)
		{	
			//cout<<"\n Discarded node with "<<livenode.keyInfo<<" as "<<knownUpperBound;
			//displayHeapNodeData(&livenode);	
			continue;
		}

		//Assign next task and explore more
		int nextPerson, nextTask;
		int np=1;
		while(livenode.assignments[np])
		{
			np++;
		}
		int person = np;
		
		////
		for(task=1;task<=n;task++)
  	  	{   
			int np=1;
			while(livenode.assignments[np])
			{
				if(task==livenode.assignments[np])
					break;//Skip already assigned task exploration.
				np++;
			}
			if(task==livenode.assignments[np])
				continue;
				
			livenode.assignments[person]=task;
			
			thisLB=sumOfActualAfterAssigned(livenode.assignments)+sumOfLowestAfterAssigned(livenode.assignments);
			//cout<<"\n (person# "<<person<<" task# "<<task<<" at upper bound "<<thisLB<<")";

			if(person==(n-1))
			{
				if(thisLB<knownUpperBound)
				{
					knownUpperBound=thisLB;
					//cout<<"\n********* Update known upper bound ******\n";
					//cout<<knownUpperBound;
					//displayHeapNodeData(&livenode);
					//cout<<"\n*******************************************\n";
				}
			}
			if(person==n)
			{
				if(thisLB<knownUpperBound)
				{
					knownUpperBound=thisLB;
					totalSolutions=1;
					for(int dd=1;dd<=n;dd++)
					{
						result[dd]=livenode.assignments[dd];
					}		
					//discard previos results
					while(removeLinearSLLFront(&result_head));

					insertLinearSLLRear(&result_head,result);
		
				}
				else if((thisLB==knownUpperBound))// && (isEmptyHeap(&heap)))//multiple solutoins may be possible
				{
					totalSolutions++;
					for(int dd=1;dd<=n;dd++)
					{
						result[dd]=livenode.assignments[dd];
					}
					insertLinearSLLRear(&result_head,result);
					//cout<<"\nSolution # "<<totalSolutions;
					//display_result();
				}

				
			}

			//If this lower bound is higher than known upper bound, do not go forward with it. Else insert into heap.
			if(thisLB<=knownUpperBound)//Equal ??
			{
				//insert into minheap
				struct HeapData data;
				data.keyInfo=thisLB;
				data.assignments=new int[n+1];
				for(int ii=0;ii<=n;ii++)
					data.assignments[ii]=livenode.assignments[ii];
				
				insertHeap(&heap,data);
				//Traverse as part of debugging
				//cout<<"\n Call to traversal: ";
				//cout<<"\n Linked list forward : ";traverseHeapLinkedListForward(heap);
			}
			else
			{
				//cout<<"\nPerson# "<<person<<" Task# "<<task<<" : "<<thisLB<<" is higher than "<<knownUpperBound<<" hence discarded for further processing.";
			}
    	}
		////


		//cout<<"\nRetrieved from heap for further movement ";
		
		
	}while(1);
    return totalSolutions;
}

int findOverAllLowestBoundSumOfMinimums()
{
    int sum=0;
    int min;
    for(int c=1;c<=n;c++)
    {
        min = skillset[1][c];
        for(int rr=2;rr<=n;rr++)
        {
            if(skillset[rr][c]<min)
            {
                min=skillset[rr][c];
            }
        }
        sum+=min;
    }
    return sum;
}
int findOverAllUpperBoundDiagonalSum()
{
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=skillset[i][i];
    }
    return sum;
}

int sumOfLowestAfterAssigned(int *assignments)
{
    int sum=0;
    int c;
    int min;
    int highestmin=findOverAllLowestBoundSumOfMinimums();
    for(c=1;c<=n;c++)
    {
        //skip the task values about which task has been assigned
        int te;
        for(te=1;te<=n;te++)
        {
            if(c==assignments[te])
                break;
        }
        if(te<=n)
        {
            continue;
        }
        min = highestmin;
        for(int rr=1;rr<=n;rr++)
        {
           if(assignments[rr])
		   	continue;
            
            if(skillset[rr][c]<min)
            {
                min=skillset[rr][c];
            }
        }
        sum+=min;
    }
    return sum;
}



void insertHeap(struct Heap* pHeap,struct HeapData data)
{
	
	//attach Node as per min heap property balanced next
	//if heap is empty, new Node is the first ever entry
	if((pHeap->pHeapTreeRootListStart)==NULL)
	{
		//Allocate memory for insertion of newNode
		struct Node *newNode = new struct Node;
		if(newNode==NULL)
		{
				cout<<"Memory allocation failed within insertHeap()";
				exit(1);
		}

		//Store data
		newNode->data = data;
		newNode->treeParent = NULL; //root node parent .. no one.
		newNode->treeLeft = newNode->treeRight =newNode->listNext = newNode->listPrev = NULL;
		pHeap->pHeapTreeRootListStart = pHeap->pListLast = newNode;
		pHeap->numberOfNodes=1;
		return;
	}
	else
	{
		//Allocate memory for insertion of newNode
		struct Node *newNode = new struct Node;
		if(newNode==NULL)
		{
				cout<<"Memory allocation failed within insertHeap()";
				exit(1);
		}

		//Store data
		newNode->data = data;
		
		//Take care of LL
		//As this is newly added as last node
		newNode->listNext = NULL;
		//the old last becomes prev of newnode
		newNode->listPrev = pHeap->pListLast;
		//newNode becomes the last to existing last
		if(pHeap->pListLast)
			pHeap->pListLast->listNext = newNode;
		//newNode will become the new last node
		pHeap->pListLast=newNode;
		
		//New node is going to be added. This makes later formula readable.	
		pHeap->numberOfNodes++;
	
		//Take care of Tree
		//newnode's will be a leaf node, hence no children.
		newNode->treeLeft = newNode->treeRight = NULL;
		//parent
		struct Node *lastNodeTreeParent=NULL;
		if((pHeap->numberOfNodes)%2)//Total Nodes so far including the new is odd. Hence new node will be in the right
		{
			lastNodeTreeParent = addressOfNodeByNumber(pHeap->pHeapTreeRootListStart, (((pHeap->numberOfNodes)-1)/2));		//thisNodeNumber=2*parent+1. Hence, parent = (thisNodeNumber -1 )/2
			//cout<<"\n parent having data. inserton to right "<<parent->data;
			if(lastNodeTreeParent->treeRight)
			{
				cout<<"\n Calculation error. right of parent must be empty.";
				exit(1);
			}
			lastNodeTreeParent->treeRight=newNode;
			//cout<<"\n parent having data. inserton to right "<<parent->data<<"\t inserted "<<parent->right->data;
		}
		else//Total Nodes so far including the new is even. Hence new node will be in the left
		{
			lastNodeTreeParent = addressOfNodeByNumber(pHeap->pHeapTreeRootListStart, ((pHeap->numberOfNodes)/2));		//thisNodeNumber=2*parent. Hence, parent = (thisNodeNumber)/2
			//cout<<"\n parent having data. inserton to left "<<parent->data;
			if(lastNodeTreeParent->treeLeft)
			{
				cout<<"\n Calculation error. left of parent must be empty.";
				exit(1);
			}
			lastNodeTreeParent->treeLeft=newNode;
			//cout<<"\n parent having data. inserton to left "<<parent->data<<"\t inserted "<<parent->left->data;
		}
		newNode->treeParent =  lastNodeTreeParent;

		//percolate up last node to meet minimum heap property
		struct Node *trav;
		trav=pHeap->pListLast;
		struct HeapData dta=trav->data;
		while(trav->treeParent)//root node's parent is null which shall stop this loop.
		{
			if((trav->treeParent) && (dta.keyInfo<((trav->treeParent->data).keyInfo)))//check data. If child info is smaller than parent info, swap
			{
				//Temporarily, I am moving on to swap data itself. But better be arrangment of pointers in case record is containing so many fields.
				trav->data=trav->treeParent->data;
				trav=trav->treeParent;
			}
			else if(trav->treeParent)
				break;
		}
		trav->data=dta;
	}

}
int removeElementFromHeap(struct Heap* pHeap, struct HeapData *pdata)
{
	if((pHeap->pHeapTreeRootListStart)==NULL)
	{
		return 0;//failure due to empty.
	} 
	if ( (((pHeap->pHeapTreeRootListStart)->treeLeft)==NULL) && (((pHeap->pHeapTreeRootListStart)->treeRight)==NULL))//heap has only one element as data
	{
		*pdata=pHeap->pHeapTreeRootListStart->data;
		delete (pHeap->pHeapTreeRootListStart);
		pHeap->pHeapTreeRootListStart=NULL;
		pHeap->pListLast=NULL;
		pHeap->numberOfNodes=0;
	}
	else//Heap has more than one element
	{
		// I would have a choice of moving data. But I chose to move pointers.
		// Backup
		struct Node *detachedTreeRootListStart= pHeap->pHeapTreeRootListStart;
		struct Node *detachedListLast= pHeap->pListLast;
		
		// if((detachedTreeRootListStart->treeLeft) && ((detachedTreeRootListStart->treeLeft)==detachedListLast) )
		// {
		// 	//Only two nodes exist
			
		// }
		
		//Take care of linked list links
		//Restore LL(prev, next) as per old root
		if((detachedListLast->listPrev) &&(detachedListLast->listPrev != detachedTreeRootListStart))//Second last node exists
		{
			detachedListLast->listPrev->listNext=NULL;//Make second last node now the last node
			pHeap->pListLast=detachedListLast->listPrev;
			detachedListLast->listPrev=NULL;
		}
		else if(detachedListLast->listPrev)//Second last node is root itself. And original root is to be deleted. 2nd node itself going to be new root now.
		{
			detachedListLast->listPrev=NULL;//New root prev nothing.
			pHeap->pListLast=detachedListLast;//Last node is same as first node.
		}
		

		//Last node going to be moved as root; which becomes prev of 2nd node now.
		if((detachedTreeRootListStart->listNext)&&(detachedTreeRootListStart->listNext!=detachedListLast))
		{
			detachedTreeRootListStart->listNext->listPrev=detachedListLast;
			detachedListLast->listNext=detachedTreeRootListStart->listNext;
		}
		else if(detachedTreeRootListStart->listNext)//2nd node itself going to be moved as new root.
		{
			detachedListLast->listNext=NULL;
			//pHeap->pListLast=detachedListLast; Already taken care in prev.
		}
 			

		//Take care of tree links
		//Restore Tree(left, right and parent) as per old root 
		//Below LHS must be NULL as it was last node. Now getting overwritten by second node if any.
		if(detachedTreeRootListStart->treeLeft==detachedListLast)
			detachedListLast->treeLeft=NULL;
		else
			detachedListLast->treeLeft=detachedTreeRootListStart->treeLeft;//LHS must be NULL being leaf last node
		if(detachedTreeRootListStart->treeRight==detachedListLast)
			detachedListLast->treeRight=NULL;
		else
			detachedListLast->treeRight=detachedTreeRootListStart->treeRight;//LHS must be NULL being leaf last node

		if(detachedListLast->treeParent)//parent of leaf last node exist
		{
			//update parent of last node to have it empty either left or right
			if((pHeap->numberOfNodes)%2)//Node to be delted was odd numbered, then it was left of its parent
				detachedListLast->treeParent->treeRight=NULL;
			else
				detachedListLast->treeParent->treeLeft=NULL;	
		}
		detachedListLast->treeParent=detachedTreeRootListStart->treeParent;//RHS must be NULL being root

		//update parents of left child and right child of to new root going to be .. lastnode
		if(detachedTreeRootListStart->treeLeft)
			detachedTreeRootListStart->treeLeft->treeParent=detachedListLast; 
		if(detachedTreeRootListStart->treeRight)
			detachedTreeRootListStart->treeRight->treeParent=detachedListLast; 

		//Make the last node to be new root node
		pHeap->pHeapTreeRootListStart=detachedListLast;

		//Reduce total count by 1
		pHeap->numberOfNodes--;			

		*pdata=detachedTreeRootListStart->data;
		delete detachedTreeRootListStart;

		//percolate down root information to meet minimum heap property
		struct Node *trav;
		trav=pHeap->pHeapTreeRootListStart;
		struct HeapData bufferData;
		//Temporarily, I am moving on to swap data itself. But better be arrangment of pointers in case record is containing so many fields.
		while(1)
		{
			
			if((trav->treeLeft) && (((trav->data).keyInfo)>((trav->treeLeft->data).keyInfo)))//check data. If child info is smaller than parent info, swap
			{
				bufferData=trav->data;
				trav->data=trav->treeLeft->data;
				trav->treeLeft->data=bufferData;
				trav=trav->treeLeft;
			}
			else if((trav->treeRight) && (((trav->data).keyInfo)>((trav->treeRight->data).keyInfo)))//check data. If child info is smaller than parent info, swap
			{
				bufferData=trav->data;
				trav->data=trav->treeRight->data;
				trav->treeRight->data=bufferData;
				trav=trav->treeRight;
			}
			else 
				break;
		}
	}	
	return 1;//success
}

void traverseHeapLinkedListForward(struct Heap heap)
//Forward linked list traversal. Just to know current status of heap.
{
	struct Node *trav=heap.pHeapTreeRootListStart;
	if(trav==NULL)
	{
		cout<<"\n Empty heap";
		return;
	}
	while(trav)
	{
		displayHeapNodeData(&(trav->data));
		trav=trav->listNext;
	}
}
void displayHeapNode(struct HeapData *pheapdata)
{
		cout<<"\n(KeyInfo:"<<pheapdata->keyInfo<<",\n\tAssignments:";
        int te=1;
        while( (te<=n) && (pheapdata->assignments[te]))
        {
         cout<<"(Person#"<<te<<"->Task#"<<pheapdata->assignments[te];
         te++;
         cout<<"\t";
        }
        cout<<") ";

}

void traverseTreeInOrder(struct Node *pRoot)
//in order traversal. Just to know current status of heap.
{
	if(pRoot!=NULL)
	{
		traverseTreeInOrder(pRoot->treeLeft);
		cout<<"\t"<<"(KeyInfo:"<<pRoot->data.keyInfo<<" : Others ) ";
		traverseTreeInOrder(pRoot->treeRight);
	}
}

struct Node* addressOfNodeByNumber(struct Node *start, int position)
{
	//cout<<"\n Called to return position of parent  at "<<position;
	if(position<=0)
		return NULL;

	while(start)
	{
		position--;
		if(position==0)
		{
			//cout<<"\n Returning correct parent with value "<<start->data;
			return start;
		}
		start=start->listNext;
	}
	return NULL;
}
void traverseHeapLinkedListBackword(struct Heap heap)
{
   	struct Node *trav=heap.pListLast;
        if(trav==NULL)
        {
                cout<<"\n Empty heap";
                return;
        }
        while(trav)
        {
                cout<<"(KeyInfo:"<<trav->data.keyInfo<<" : Others ) ";
                trav=trav->listPrev;
        }
	
}


void displayHeapNodeData(struct HeapData *pheapdata)
{
	cout<<"\n("<<pheapdata->keyInfo<<"\t";
	for(int tt=1;tt<=n;tt++)
	{
		if(pheapdata->assignments[tt])
			cout<<"\tperson#"<<tt<<" is assigned task# "<<pheapdata->assignments[tt];
	}
	cout<<")";
}

int sumOfActualAfterAssigned(int *assignments)
{
	int sum=0;
	for(int ii=1;ii<=n;ii++)
	{
		if(assignments[ii])
		{
			sum+=skillset[ii][assignments[ii]];
		}
	}
	return sum;
}

int isEmptyHeap(struct Heap* pHeap)
{
	if(!(pHeap->numberOfNodes))
		return 1;//true means empty. YES.
	else
		return 0;//false means not empty. NO.
}

int insertLinearSLLRear(struct snode **phead, int data[])
{
	struct snode *newptr,*trav;
	//printf("\n insertLinearSLLRear:");
	//newptr=(struct snode *) malloc(sizeof(struct snode));
	newptr = new struct snode;
	if(!newptr)
	{
		printf("\n Malloc-Memory allocation failed");
		return 0;//Failure
	}
	newptr->pdata=new int[n+1];
	for(int tt=0;tt<=n;tt++)
		newptr->pdata[tt] = data[tt];
	newptr->next = NULL;

	if((*phead)==NULL)
	{
		*phead = newptr;
		return 1;	
	}
	
	trav=(*phead);
	while( trav->next != NULL)
		trav=trav->next;

	trav->next = newptr;

	return 1;//Success
}
int traverseSLL(struct snode *head)
{
	//printf("\n traverseSLL: ");
	if(!head)
	{
		cout<<"\n Can't traverse as the list is empty. ";
		return 0;
	}
	int cost=0;
	int person=1;
	cout<<"\n";
		
	for(int tt=1;tt<=n;tt++)
	{
		cout<<head->pdata[tt]<<"\t";
		cost+=skillset[person++][head->pdata[tt]];
	}
		
	head=head->next;
	
	while(head)
	{
		

		cout<<"\n";
		
		for(int tt=1;tt<=n;tt++)
		{
			cout<<head->pdata[tt]<<"\t";
			
		}
		
		head=head->next;
	}
	cout<<"\n\n Total cost going to be "<<cost;
	return 1;
}
int removeLinearSLLFront(struct snode **phead)
{
	struct snode *temp;
	//printf("\n removeLinearSLLFront:");
	if((*phead)==NULL)//empty linked list
	{
		return 0;//Can not be deleted
	}
	
	if((*phead)->next == NULL)//single node in the list
	{
		//free((*phead)->pdata);
		//free(*phead);
		delete [] ((*phead)->pdata);
		delete (*phead);
		*phead=NULL;
	}
	else//more than one node
	{	
		temp=(*phead)->next;
		// free((*phead)->pdata);
		// free(*phead);
		delete [] ((*phead)->pdata);
		delete (*phead);
		*phead=temp;
	}
	return 1;
}

