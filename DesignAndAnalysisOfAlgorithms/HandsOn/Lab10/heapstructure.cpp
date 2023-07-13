#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
//MinHeap binary
struct Heap
{
	struct Node *pHeapTreeRootListStart;
	struct Node *pListLast;
	int numberOfNodes;//This is to avoid calculating every time. But need to make sure updated correctly. It can be derived actually.
};
struct Node{
	int data;
	struct Node *treeLeft, *treeRight, *treeParent, *listNext, *listPrev;
};
void insertHeap(struct Heap* pHeap, int data);
int removeElementFromHeap(struct Heap* pHeap,int * pdata);
void traverseHeapLinkedListForward(struct Heap heap);
void traverseHeapLinkedListBackword(struct Heap heap);
void traverseTreeInOrder(struct Node *pRoot);
struct Node* addressOfNodeByNumber(struct Node *start, int position);
int main()
{
	ifstream ifs;
	char command[4
	];
	int data;
	ifs.open("C:\\Users\\jigar\\OneDrive\\Documents\\DAA\\prog\\DAA\\heapInput.txt",std::ios_base::in);

	if(ifs.fail())
	{
		cout<<"\n Data file not found";
		return 1;	
	}
	
	struct Heap heap;
	heap.pHeapTreeRootListStart=heap.pListLast=NULL;
	heap.numberOfNodes=0;
	do
	{
		ifs>>command;
		if(ifs.eof())
			break;
		switch(command[0])
		{

			case 'i':
				ifs>>data;
				cout<<"\n Call to insertion: ";
				insertHeap(&heap,data);
				cout<<"\n\t Inserted data "<<data;
				break;	
			case 'r':
				cout<<"\n Call to removal: ";
				if(removeElementFromHeap(&heap, &data))
					cout<<"\n\t Removed data "<<data;
				else
					cout<<"\n\t Heap is empty.";
				break;
			case 't':
				cout<<"\n Call to traversal: ";
				cout<<"\n Linked list forward : ";traverseHeapLinkedListForward(heap);
				cout<<"\n Linked list backword : ";traverseHeapLinkedListBackword(heap);
				cout<<"\n Tree InOrder : ";traverseTreeInOrder(heap.pHeapTreeRootListStart);
				break;
			default:
				cout<<"\n Input option not supported: "<<command;
				exit(1);
		}
	}while(1);

	ifs.close();

}
void insertHeap(struct Heap* pHeap,int data)
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
		int dta=trav->data;
		while(trav->treeParent)//root node's parent is null which shall stop this loop.
		{
			if((trav->treeParent) && (dta<(trav->treeParent->data)))//check data. If child info is smaller than parent info, swap
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
int removeElementFromHeap(struct Heap* pHeap, int *pdata)
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
		int bufferData;
		//Temporarily, I am moving on to swap data itself. But better be arrangment of pointers in case record is containing so many fields.
		while(1)
		{
			
			if((trav->treeLeft) && ((trav->data)>(trav->treeLeft->data)))//check data. If child info is smaller than parent info, swap
			{
				bufferData=trav->data;
				trav->data=trav->treeLeft->data;
				trav->treeLeft->data=bufferData;
				trav=trav->treeLeft;
			}
			else if((trav->treeRight) && ((trav->data)>(trav->treeRight->data)))//check data. If child info is smaller than parent info, swap
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
		cout<<"(data:"<<trav->data<<") ";
		trav=trav->listNext;
	}
}

void traverseTreeInOrder(struct Node *pRoot)
//in order traversal. Just to know current status of heap.
{
	if(pRoot!=NULL)
	{
		traverseTreeInOrder(pRoot->treeLeft);
		cout<<"\t"<<"(data:"<<pRoot->data<<") ";
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
                cout<<"(data:"<<trav->data<<") ";
                trav=trav->listPrev;
        }
	
}
