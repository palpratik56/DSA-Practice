#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int value;
	struct node *next;
}NODE;
NODE* head=NULL;

NODE *CreateNode();
void Insert();
void Insert_Aftervalue();
void Display();
void Search();
void Delete_Node();

int main(){
	int ch;
	NODE **head=NULL;
	do
	{
		printf("\n 1. Insert  2. Insert after Value  3. Display\n 4. Delete  5. Search a value  6. Exit\n Give choice: ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				Insert();
				break;
			case 2:
				Insert_Aftervalue();
				break;
			case 3:
				Display();
				break;
			case 4: 
				Delete_Node();
				break;
			case 5: 
				Search();
				break;
			case 6: break;
			default:
				printf("\n WRONG Choice !");
				break;
		}
	}while(ch!=6);
	return 12;
}

NODE *CreateNode()
{
	NODE *p;
	p=(NODE*)malloc(sizeof(NODE));
	printf("\n Enter Value: ");
	scanf("%d", &p->value);
	p->next=NULL;
	return p;
}

void Insert() {
  if (head== NULL) {
    head = CreateNode();
    return;
  }
  
  NODE* temp = CreateNode();
  //if the value is the smallest then it will be the new head
  if(temp->value<head->value){
  	temp->next=head;
  	head=temp;
  	return;
    }
  
  NODE *cur = head, *pre = head;
  // Find the correct node to insert the new node after
  while (cur!= NULL && cur->value < temp->value){
  		pre = cur;
        cur = cur->next;
    }
	temp->next = pre->next;
	pre->next = temp;
		
}

void Insert_Aftervalue()
{
	int val;
	printf("\n Enter the Value of the Node(After) to be Inserted: ");
	scanf("%d", &val);
	NODE *p, *q, *r;
	
	p=CreateNode();
	if(p->value<val)
		printf("\n Can't be inserted as it's less than given value");
	else
   {
		q=head;
		r=head; 
		while(q!=NULL && q->value < p->value){
			r=q;
			q=q->next;
		}
		p->next=r->next;
	    r->next=p;
	    printf("\n Node Inserted!\n");
	}
	
}

void Display()
{
	NODE *q;
	q=head;
	if(q==NULL)
		printf("\n LIST is Empty !\n");
	else
	{
		printf("\n The LIST is: ");
		while(q!=NULL)
		{
			printf("%d-->", q->value);
			q=q->next;
		}
		printf("NULL\n");
	}	
}

void Search()
{
	NODE *p;
	p=head;
	int val, c=0;
	printf("\n Enter the Value of the Node : ");
	scanf("%d", &val);
	while(p!=NULL)
	{	
		if(p->value==val)
		{
			printf("\n It is found at Position %d\n", c+1);
			return;
		}
		p=p->next;
		c++;
	}
	if(p==NULL)    
	printf("\n Such Node doesn't exist!\n");
		
}

void Delete_Node(){
	int val;
	if(!head){
		printf("\n LIST is Empty !\n");
		return;
	}
	printf("\n Enter the Value of the Node to be deleted : ");
	scanf("%d", &val);
	NODE *pre=head, *cur=head;
	NODE* t;
	if(val==head->value){
		t=head;
		head=head->next;
		free(t);
		printf("\n node deleted!!\n");
		return;
	}
	while(cur!=NULL && cur->value!=val){
		pre=cur;
		cur=cur->next;
	}
	if(!cur)
	printf("\n Such node not found!!\n");
	else{
		pre->next=cur->next;
		free(cur);
		printf("\n node deleted!!\n");
	}
}

