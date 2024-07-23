#include <stdlib.h>
#include <stdio.h>
#include "./headers/already-done.h"

Node *head = NULL;

void reverseList(Node *curr)
{
    if (curr->next == NULL)
    {
        head = curr;
        return;
    }

    reverseList(curr->next);

    Node *next = curr->next;
    next->next = curr;
    curr->next = NULL;
}

int main()
{
    insertNode(1, 1);
    insertNode(2, 2);
    insertNode(3, 3);
    insertNode(4, 4);

    printLinkedList(head);
    printf("\n");

    reverseList(head);

    printLinkedList(head);
}