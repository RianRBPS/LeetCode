/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    
    // Se left == right, nada eh alterado
    // Se head ou head->next sao NULL, nada pode ser alterado
    if(left == right || head == NULL || head->next == NULL) {
        return head;
    }
    
    struct ListNode dummy;
    //  In C, you should use the -> operator with pointers, not with structs. 
    //To access the next field of the dummy struct, you should use the . operator because dummy is not a pointer but a direct instance of the struct. 
    dummy.next = head;
    struct ListNode* prev = &dummy;
    
    // Mover prev para o node antecessor a posicao left
    for(int i = 1; i < left; i++) {
        prev = prev->next;
    }
    
    struct ListNode* atual = prev->next;
    struct ListNode* next = NULL;
    struct ListNode* tail = atual;
    
    // Revertendo os Nodes da esquerda para a direita
    for(int i = left; i <= right; i++) {
        next = atual->next;
        atual->next = prev->next;
        prev->next = atual;
        atual = next;
    }
    
    // Conectando a porcao invertida de volta a lista original
    tail->next = atual;
    
    return dummy.next;
    
}

