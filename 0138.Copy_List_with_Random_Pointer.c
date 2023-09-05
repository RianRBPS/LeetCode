#include <stdio.h>
#include<stdlib.h>

//Definition for a Node.
struct Node {
    int val;
    struct Node *next;
    struct Node *random;
};


struct Node* copyRandomList(struct Node* head) {
	
    // Caso o Node 
    if(head == NULL) return NULL;
    
    // Passo 1: Duplicar cada Node e inserir logo após o Node original 
    struct Node* current = head;
    while(current != NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->val = current->val;
        newNode->next = current->next;
        current->next = newNode;
        current = newNode->next;
    }
    
    // Passo 2: Atualizar os ponteiros aleatórios
    current = head;
    while(current != NULL) {
        if (current->random != NULL){
            current->next->random = current->random->next;
        }else {
            current->next->random = NULL;
        }
        current = current->next->next;
    }
    
    // Passo 3: Separar a linked list original da link list cópia
    current = head;
    struct Node* newHead = head->next;
    struct Node* newCurrent = newHead;
    while (current != NULL) {
        current->next = current->next->next;
        current = current->next;
        if ( current != NULL){
            newCurrent->next = newCurrent->next->next;
            newCurrent = newCurrent->next;
        }
    }
    
    return newHead;
}