#include <stdio.h>
#include <stdbool.h>


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNodes {
    int val;
    struct ListNodes *next;
};


bool hasCycle(struct ListNode *head) {
    
    // Não existe ciclo se a lista estiver vazia ou se ela tiver apenas um único node
    if(head == NULL || head->next == NULL){
        return false;
    }
    
    struct ListNodes *tartaruga = head;
    struct ListNodes *coelho = head;
    
    // Utilizando o algoritmo Tortoise and Hare (Tartaruga e a Lebre) ou Floyd's cycle finding algorithm.
    while(coelho != NULL && coelho->next != NULL){
        
        tartaruga = tartaruga->next; // Movendo o a tartaruga uma vez
        coelho = coelho->next->next; // Movendo o coelho duas vezes
        
        // Se a tartaruga se encontra com o coelho eventualmente, existe um ciclo
        if(tartaruga == coelho){
            return true;
        }
    }
    
    return false;
}
    

/*
// https://www.geeksforgeeks.org/floyds-cycle-finding-algorithm/
While traversing the linked list one of these things will occur

    The Fast pointer may reach the end (NULL) this shows that there is no loop in the linked list.
    The Fast pointer again catches the slow pointer at some time therefore a loop exists in the linked list.
*/