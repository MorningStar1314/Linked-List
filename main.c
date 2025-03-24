#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node *createNode(int value){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node** head, int value){
    Node *newNode = createNode(value);
    if (*head == NULL || (*head)->data >= value){
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node *current = *head;
    while (current->next != NULL && current->next->data <value){
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

int main(){

    Node *head = NULL;
    int n, num;

    printf("Enter the number of nodes; ");
    scanf("%d", &n);

    srand(time(NULL));

    struct node *head = NULL;



    return 0;
}