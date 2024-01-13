#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}TREE;

TREE* create();
void preorder(TREE*);
void inorder(TREE*);
void postorder(TREE*);

static int pre=0;
int main()
{
	TREE *root=NULL;
	int choice,data;
	do
	{
		printf("\n 1.Create a node  2.Preorder traversal  3.Inorder traversal  4.Postorder traversal\n 5.Exit   Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				root=create();
				printf("\n Binary tree created\n");
				break;
			case 2:
				if(root==NULL)
					printf("\n No tree exists\n");
				else
				{
					printf("\n Preorder traversal:  ");
					preorder(root);
					printf("\n Function is called %d times\n",pre);
				}
				break;
			case 3:
				if(root==NULL)
					printf("\n No tree existsee\n");
				else
				{
					printf("\n Inorder traversal:  ");
					inorder(root);
					printf("\n");
				}
				break;
			case 4:
				if(root==NULL)
					printf("\n No tree exists\n");
				else
				{
					printf("\n Postorder traversal:  ");
					postorder(root);
					printf("\n");
				}
				break;
			case 5:
				break;
			default:
				printf("\n Enter valid option between 0 to 5");
				break;
		}
	}while(choice!=5);
	return 12;
}

TREE * create()
{
	TREE *t;
	char ch;
	t=(TREE *)malloc(sizeof(TREE));
	printf("\n Enter the data : ");
	scanf("%d",&t->data);
	printf("\n Press l to add left child of %d , else Enter n : ",t->data);
	fflush(stdin);
	scanf("%c",&ch);
	if(ch=='l')
		t->left=create();
	else
		t->left=NULL;
	printf("\n Press r to add right child of %d , else Enter n : ",t->data);
	fflush(stdin);
	scanf("%c",&ch);
	if(ch=='r')
		t->right=create();
	else
		t->right=NULL;
	return t;
}

void preorder(TREE *p)
{
	if(p==NULL)
		return;
	printf(" |%d| ",p->data);
	pre++;
	preorder(p->left);
	preorder(p->right);
	return;
}

void inorder(TREE *p)
{
	if(p==NULL)
		return;
	inorder(p->left);
	printf(" |%d| ",p->data);
	inorder(p->right);
	return;
}

void postorder(TREE *p)
{
	if(p==NULL)
		return;
	postorder(p->left);
	postorder(p->right);
	printf(" |%d| ",p->data);
	return;
}

