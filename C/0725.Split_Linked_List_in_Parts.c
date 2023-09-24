/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct ListNode** splitListToParts(struct ListNode* head, int k, int* returnSize) {
    struct ListNode* curr = head;
    int len = 0;

    // 1. Determine o comprimento da lista ligada.
    while (curr) {
        len++;
        curr = curr->next;
    }

    int partSize = len / k; // Tamanho básico de cada parte.
    int extra = len % k;   // Número de partes que terão um nó extra.

    curr = head;
    struct ListNode** result = (struct ListNode**)malloc(k * sizeof(struct ListNode*));

    for (int i = 0; i < k; i++) {
        result[i] = curr;

        int currentPartSize = partSize + (i < extra ? 1 : 0);

        for (int j = 1; j < currentPartSize; j++) {
            if (curr) {
                curr = curr->next;
            }
        }

        if (curr) {
            struct ListNode* next = curr->next;
            curr->next = NULL;
            curr = next;
        }
    }

    *returnSize = k;
    return result;
}
