#include <stdlib.h>
#include <stdio.h>
#include "./headers/already-done.h"

Node *head = NULL;

void deleteNode(int position)
{
    Node *next = NULL;
    Node *prev = head;

    for (int i = 0; i < position - 2; i++)
    {
        prev = prev->next;
    }
    next = prev->next->next;
    prev->next = next;
    return;
};

int main()
{
    insertNode(1, 1);
    insertNode(2, 2);
    insertNode(3, 3);
    insertNode(4, 4);

    printLinkedList(head);
    printf("\n");

    deleteNode(3);

    printLinkedList(head);
}