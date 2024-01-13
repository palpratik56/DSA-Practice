#include <stdio.h>

#define MAX_S 10

typedef struct {
  int data[MAX_S];
  int top;
} Stack;

Stack st[5];//considering max of 5 stacks

void initial() {
  for (int i = 0; i <5; i++) 
    st[i].top = -1;
}

void push(int stack_num, int data) {
  if (st[stack_num].top >= MAX_S - 1) {
    printf("Stack %d is full.\n", stack_num);
    return;
	}
  st[stack_num].top++;

  st[stack_num].data[st[stack_num].top] = data;
}

int pop(int stack_num) {
  if (st[stack_num].top == -1) {
    printf("Stack %d is empty.\n", stack_num);
    return -1;
  }

  int dat = st[stack_num].data[st[stack_num].top--];
  return dat;
}

int top(int stn){
	if(st[stn].top==-1) printf("\n Stack empty..");
	return st[stn].data[st[stn].top];
}

int main() {
  initial();
  int c,a,b;
  do{
  printf("\n 1. Push  2. Pop  3. See the top 4. Exit\n Give choice: ");
  scanf("%d",&c);
  	switch(c){
  		case 1:
  			printf("\n Give stack no: ");
		  	scanf("%d",&a);
		  	printf("\n Give element to push: ");
		  	scanf("%d",&b);
		  	push(a,b);
	  		break;
	  	case 2:
	  		printf("\n Give stack no: ");
		  	scanf("%d",&a);
			printf("\n %d has popped from stack", pop(a));
		    break;
		case 3:
			printf("\n Give stack no: ");
		  	scanf("%d",&a);
		    printf("\n Top of stack %d is %d", a,top(a));
		    break;
  		}
  	}while(c!=4);

  return 0;
}


