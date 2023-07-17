
#include <stdio.h>
#include <conio.h>
#include <process.h>
#include <stdlib.h>
#include <iostream.h>

struct NODE{
  int info;
  struct NODE *left;
  struct NODE *right;
};

typedef struct NODE node;
node* getnode()
{
 node* tempnode;
 tempnode = (node*) malloc(sizeof(node));
 if(tempnode==NULL)
 {
  printf("\n memory allocation failure ");
  exit(0);
 }
 tempnode->left = NULL;
 tempnode->right = NULL;
 return tempnode;
}
node* maketree(int data)
{
	node* temp = getnode();
	temp->info = data;
	return temp;
}
void setleft(node *parent,int data)
{
	if(parent->left != NULL)
	{
		cout<<"\n left subtree not empty";
		return;
	}
	else
	{
		parent->left = maketree(data);
	}
}
void setright(node *parent,int data)
{
	if(parent->right != NULL)
	{
		cout<<"\n right subtree is not empty ";
		return;
	}
	else
	{
		parent->right = maketree(data);
	}

}
void in_tra(node* tptr)
{
 if(tptr==NULL)
   return;
 in_tra(tptr->left);
 printf(" %d ",(tptr)->info);
 in_tra(tptr->right);
}

void post_tra(node* tptr)
{
 if(tptr==NULL)
   return;
 post_tra(tptr->left);
 post_tra(tptr->right);
 printf(" %d ",(tptr)->info);
}

void pre_tra(node* tptr)
{
 if(tptr==NULL)
   return;
 printf(" %d ",(tptr)->info);
 pre_tra(tptr->left);
 pre_tra(tptr->right);
}

void insert(node** t,int tdata)
{
 if(( *t)!=NULL )
 {
   if( tdata< ( (*t)->info ) ) // set left
   {
    if( ( (*t)->left ) == NULL )
    {
	setleft(*t,tdata);
	return;
    }
    else
	insert( &( (*t)->left ),tdata);
   }
   else //set right
   {
    if( ( (*t)->right ) == NULL)
    {
	setright((*t),tdata);
	return;
    }
    else
	insert( &( (*t)->right ),tdata);
   } //end of else
  } //EN D O F IF
 else
 {
	*t=maketree(tdata);
 }
}



void main()
{

node *t,*temp;
t = NULL;
char ch;
int tdata;
clrscr();

while(1)
{
 cout<<"\n enter data";
 cin>>tdata;
 insert(&t,tdata);
 cout<<"\n want to enter more (y / n) ? ";
 cin>>ch;
 if(ch!='y')
	break;

}

in_tra(t);

getch();
}