//Implementing a circular queue
#include <stdio.h>

#define MAX 6

int queue[MAX];
int front = -1;
int rear = -1;

int isFull() {
  if ((front == rear + 1) || (front == 0 && rear == MAX - 1)) return 1;
  return 0;
}

int isEmpty() {
  if (front == -1) return 1;
  return 0;
}

void enQueue(int ele) {
  if (isFull())
    printf("\n Queue is full!! \n");
  else {
    if (front == -1) front = 0;
    rear = (rear + 1) % MAX;
    queue[rear] = ele;
    printf("\n Inserted %d", ele);
  }
}

int deQueue() {
  int ele;
  if (isEmpty()) {
    printf("\n Queue is empty!");
    return (-1);
  } 
  else {
    ele = queue[front];
    if (front == rear) {
      front = -1;
      rear = -1;
    }
    else   front = (front + 1) % MAX;
    printf("\n Deleted element is %d \n", ele);
    return ele;
  }
}

void display() {
  int i;
  if (isEmpty())
    printf(" \n Empty Queue");
  else {
    printf("\n Elements are:- \n");
    for (i = front; i != rear; i = (i + 1) % MAX) {
      printf(" %d ", queue[i]);
    }
    printf(" %d ", queue[i]);
  }
}



int main() {
  int c;
  do {
    printf("\n\n  1. Enqueue   2. Dequeue   3. Display   4. Exit\n Enter your choice: ");
    scanf("%d", &c);

    switch (c) {
      case 1:
        printf("Enter the data: ");
        int data;
        scanf("%d", &data);
        enQueue(data);
        break;
      case 2:
        printf("The data dequeued is: %d\n", deQueue());
        break;
      case 3:
        display();
        break;
      default:
        printf("Invalid choice.\n");
    }
  }while(c!=4);
  return 0;
}

