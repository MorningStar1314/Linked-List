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
    while (current->next != NULL && current->next->data < value){
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void DeleteNode(Node** head, int value){
    if (*head == NULL) return;

    Node *temp = *head;
    Node *prev = NULL;

    if (temp != NULL && temp->data == value){
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != value){
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

void PrintList(Node* head){
    while (head != NULL){
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}



int main(){

    Node *head = NULL;
    int n, num;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    srand(time(NULL));

    printf("產生的隨機數：\n");
    for (int i = 0; i < n; i++){
        num = rand() % 100 + 1;
        printf("%d ", num);
        insertNode(&head, num);
    }
    printf("\n");

    printf("排序後的鏈表：\n");
    PrintList(head);

    printf("\n");
    printf("請輸入要刪除的數字：\n");
    scanf("%d", &num);
    DeleteNode(&head, num);

    printf("刪除後的鏈表：\n");
    PrintList(head);



    return 0;
}