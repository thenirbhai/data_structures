#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* Next;
}Node;

void push();
void display();
void pop();
void search();

Node* top_ptr = NULL;

void push() {
    Node* newNode_ptr = (Node*)malloc(sizeof(Node));
    printf("Enter Data: ");
    scanf("%d", &newNode_ptr -> data);
    newNode_ptr -> Next = NULL;
    printf("%d is pushed onto the stack\n",newNode_ptr -> data);
    newNode_ptr -> Next = top_ptr;
    top_ptr = newNode_ptr;
    display();
}

void display() {
    Node* temp_ptr;
    if (top_ptr == NULL) {
        printf("Stack is empty\n");
        return;
    }
    else {
        temp_ptr = top_ptr;
        printf("\nStack\nTop: ");
        while (temp_ptr != NULL){
            printf("%d\n", temp_ptr -> data);
            temp_ptr = temp_ptr -> Next;
        }
    }
}

void pop() {
    Node* temp_ptr = top_ptr;
    if(top_ptr == NULL) {
        printf("Stack Underflow\n");
    }
    else {
        printf("\n%d is Popped\n", top_ptr -> data);
        top_ptr = top_ptr -> Next;
        free(temp_ptr);
        display();
    }
}

void search(){
    Node* temp_ptr = top_ptr;
    int element,position=1,flag=0;
    printf("Enter the Element to be searched\n");
    scanf("%d",&element);
    while(temp_ptr != NULL)
    {
        if(element == temp_ptr -> data){
            printf("%d is found at position %d\n",element,position);
            break;
        }
        else{
            flag==1;
        }
        temp_ptr = temp_ptr->Next;
        position++;
    }
    if(flag==1){
        printf("Element is Not Found on the Stack\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nEnter Your Choice:\n1. Display  2. Push  3. Pop  4. Search  5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: 
                display();
                break;
            case 2: 
                push();
                break;
            case 3: 
                pop();
                break;
            case 4:
                search();
                break;
            case 5:
                exit(0);
            default : 
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}