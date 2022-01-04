#include <stdio.h>

#include <stdlib.h>

#define SIZE 10

int circularQueueArray[SIZE];

int rear = -1;

int front = -1;

void enqueue(){

    int element;

    printf("Enter The Element Which You Want To Enter In The Circular Queue :: \n");

    scanf("%d",&element);

    if ((rear == SIZE - 1 && front == 0) || front == rear + 1){

        printf("Queue Overflow \n");

    } else if (rear == -1 && front == -1){

        rear = 0;

        front = 0;

        circularQueueArray[rear] = element;

        printf("Element Is Inserted In The Circular Queue \n");

    } else if (rear == SIZE - 1 && front != 0){

        rear = 0;

        circularQueueArray[rear] = element;

        printf("Element Is Inserted In The Circular Queue \n");

    } else{

        rear = rear + 1;

        circularQueueArray[rear] = element;

        printf("Element Is Inserted In The Circular Queue \n");

    }

}

void dequeue(){

    int variable;

    if (front == -1){

        printf("Queue Underflow \n");

        return;

    } else if (rear == front){

        variable = circularQueueArray[front];

        printf("Element %d Is Deleted From The Queue \n",variable);

        rear = -1;

        front = -1;

    } else{

        variable = circularQueueArray[front];

        printf("Element %d Is Deleted From The Queue \n",variable);

        if (rear == front){

            rear = -1;

            front = -1;

        }

        if (front == SIZE - 1){

            front = 0;

        } else{

            front = front + 1;

        }

    }

}

void display(){

    int i;

    if (front == -1){

        printf("Circular Queue Is Empty \n");

    }

    else if (front > rear){

        for (i = front; i <= SIZE - 1; i++){

            printf("%d \n",circularQueueArray[i]);

        }

        for (i = 0; i <= rear; i++){

            printf("%d \n",circularQueueArray[i]);

        }
    } else{

        for (i = front; i <= rear; i++){

            printf("%d \n",circularQueueArray[i]);

        }

    }

}

int main() {

    // printf("Hello, World!\n");

    int choice;

    do {

        printf("Enter \n");

        printf("1 To Insert An Element In The Circular Queue \n");

        printf("2 To Delete An Element From The Circular Queue \n");

        printf("3 To Display The Elements From The Circular Queue \n");

        printf("4 To Exit \n");

        scanf("%d",&choice);

        switch (choice) {

            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(1);

            default:
                printf("Invalid Entry \n");

        }

    } while (choice != 4);

    return 0;

}