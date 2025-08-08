#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

enum boolean {false,true};
enum typenode {lefttype, roottype, righttype};
struct tnode
{
	int data;
	struct tnode *left, *right;
	enum typenode whatami;
};


enum boolean insert(int,struct tnode **);
struct tnode * create_node(int,enum typenode);
void inordert(struct tnode *);
enum boolean isempty(struct tnode *);
int searchoccurances(int,struct tnode *);
void draw(struct tnode *,enum boolean);
char* gettypeofnode(struct tnode * ptr);

int main()
{
	//int n;
	struct tnode *root=NULL;
	
	//Making a tree	
	//printf("\n Enter the values for binary tree\n(ENTER 9999 TO TERMINATE)\n\n");
	/*while(1)
	{
		scanf("%d",&n);
		if(n==9999)
			break;
		else if(insert(n,&root)==false)
			break;
	}*/
	insert(10,&root);
	insert(20,&root);
	insert(15,&root);
	insert(5,&root);
	insert(15,&root);
	insert(18,&root);
	insert(17,&root);
	insert(21,&root);
	insert(2,&root);
	insert(15,&root);
	insert(9,&root);
	insert(19,&root);
	insert(29,&root);
	insert(15,&root);
	insert(15,&root);
	insert(25,&root);

	/*if(isempty(root) != true)
	{	
		inordert(root);
		printf("Enter number to search ");
		scanf("%d",&n);
		printf("\nThe occurence of %d is %d\n",n,search(n,root));
	}*/
	printf("\n Traversing \n");
	inordert(root);
	printf("\n Drawing \n");
	draw(root,true);

	printf("\nThe occurence of %d is %d using searchoccurance\n",15,searchoccurances(15,root));

	return 1;
}

struct tnode * create_node(int n, enum typenode typen)
{
	struct tnode *node=(struct tnode *)malloc(sizeof(struct tnode));
	
	if(node==NULL)
	{
		printf("\n!!!!THERE IS NO MEMOERY LEFT FOR NEW NODES\n");
		return(NULL);
	}
	
	node->data=n;
	node->left=node->right=NULL;
	node->whatami = typen;

	return(node);
}


enum boolean insert(int n, struct tnode **root)
{
	if(*root==NULL)
	{
		*root=create_node(n,roottype);
		if(*root==NULL)
		{
			printf("\n!!!!THERE IS NO MEMOERY LEFT FOR NEW NODES\n");
			return(false);
		}
		return(true);
	}
	if(n >= (*root)->data)
	{
			if((*root)->right==NULL)
			{
				(*root)->right=create_node(n,righttype);
			
				if(*root==NULL)
				{
					printf("\n!!!!THERE IS NO MEMOERY LEFT FOR NEW NODES\n");
					return(false);
				}
				return(true);
			}
			else
			{
				insert(n,&((*root)->right));
				return(true);
			}
	}
	else if(n < (*root)->data)
	{
		if((*root)->left==NULL)
		{
			(*root)->left=create_node(n,lefttype);
		
			if(*root==NULL)
			{
				printf("\n!!!!THERE IS NO MEMOERY LEFT FOR NEW NODES\n");
				return(false);
			}
			return(true);
		}
		else
		{
			insert(n,&((*root)->left));
			return(true);
		}
		
	}
	return(false);
}


void inordert(struct tnode *root)
{
	if(root==NULL)
		return;
	
	inordert(root->left);
	printf("%d ",root->data);
	inordert(root->right);
}

enum boolean isempty(struct tnode *root)
{
	if(root==NULL)
	{
		printf("\nTREE IS EMPTY\n");
		return(true);
	}
	else
		return(false);
}


void draw(struct tnode *root,enum boolean lastsibling)
{
	static int level=0;
	int i;
	if(root==NULL)
	{
		return;
	}
	
	if(root->left == NULL && root->right==NULL && lastsibling) // if the lastsibling and has no kids
		printf("`-- (%d,%s))\n",root->data,gettypeofnode(root));
	else
		printf("|-- (%d,%s))\n",root->data,gettypeofnode(root));

	i=0;
	if(root->left != NULL)
	{
		level++;
		while(i<level)
		{
			printf("|    ");
			i++;
		}
		
		if(root->right==NULL)
			draw(root->left,true); //lastsibling in the level of current subtree
		else
			draw(root->left,false);

		level--;
	}
	i=0;
	if(root->right != NULL)
	{
		level++;
		while(i<level)
		{
			printf("|    ");
			i++;
		}

		draw(root->right,true); //rightmost is anyway last
		
		level--;
	}
	
	
}

int searchoccurances(int n,struct tnode *root)
{    
        if(root==NULL)
                return 0;

        int count=0;

        if(root->data == n)
                count++;

        count+=searchoccurances(n,root->right);
        count+=searchoccurances(n,root->left);
    
        return(count);
}

char* gettypeofnode(struct tnode * ptr)
{
	if(ptr->whatami == lefttype)
		return "left";
	else if(ptr->whatami == righttype)
		return "right";
	else
		return "root";
}
