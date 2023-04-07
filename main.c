#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

void addNode(struct Node** headRef, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = (*headRef);
    (*headRef) = newNode;
}

void listYazdir(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}
bool palindrom_mu(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }
    
    struct Node* slowPtr = head;
    struct Node* fastPtr = head;
    while (fastPtr->next != NULL && fastPtr->next->next != NULL) {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }

    struct Node* prev = NULL;
    struct Node* curr = slowPtr->next;
    struct Node* next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    

    struct Node* p1 = head;
    struct Node* p2 = prev;
    while (p2 != NULL) {
        if (p1->data != p2->data) {
            return false;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    
    return true;
}

int main() {
    struct Node* head = NULL;
    int boyut;
    int listElement;
    printf("bagli listenin boyutunu giriniz.\n");
    scanf("%d", &boyut);
    for (int i = 0; i < boyut; i++){
        printf("eleman giriniz.\n");
        scanf("%d", &listElement);
        addNode(&head, listElement);
    
        
    }
    

    printf("Linked list: ");
    listYazdir(head);
    
    if (palindrom_mu(head)){
        printf("fonksiyon true deger dondurdu, bu liste palindrom");
    }else{
     printf("fonksiyon false deger dondurdu, bu liste palindrom degil");
        
    }
    
    return 0;
}
