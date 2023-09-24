// Link do Problema
// https://leetcode.com/problems/add-two-numbers/

#include <stdio.h>
#include <stdlib.h>


// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

void print_list(struct ListNode *p){

    while(p){
        printf("%d ->", p->val);
        p = p->next;
    }
    printf("NULL\n");
}
 
void create_node(struct ListNode **head, struct ListNode **last, int r){  

        struct ListNode *new = NULL;

        new = (struct ListNode*)malloc(sizeof(struct ListNode));  
        new->next = NULL;   
        new->val = r;

        if(*head == NULL){                       
            *head = new;                         
            *last = new;                         
        }else{                                  
            (*last)->next = new; 
            *last = new;                   
        }                                         
}                                            

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

    struct ListNode* head = NULL;
    struct ListNode* last = NULL;
    struct ListNode* temp = NULL;

    // Variável que vai receber a soma das células individuais 
    int sum = 0;

    // Variável que vai receber o resto da divisão por 10 de cada sum
    int rem = 0;

    // Enquando ambos os Nodes são != NULL
    while(l1 && l2){

        sum = sum + l1->val + l2->val;
        rem = sum % 10;
        sum = sum / 10;

        l1 = l1->next;
        l2 = l2->next;

        create_node(&head, &last, rem);
    }

    temp = (l1 == NULL ? l2 : l1);
    
    while(temp){
        sum = sum + temp->val;
        rem = sum % 10;
        sum = sum / 10;

        temp = temp->next;

        create_node(&head, &last, rem);
    }

    if(sum){
        create_node(&head, &last, sum);
    }

    return head;

}

int main(){

    struct  ListNode a, b;
    struct ListNode *res;

    a.val = 3;
    a.next = NULL;

    b.val = 9;
    b.next = NULL;

    res = addTwoNumbers(&a, &b);

    printf("A soma dos dois numeros e\n");

    print_list(res);

    return 0;
}