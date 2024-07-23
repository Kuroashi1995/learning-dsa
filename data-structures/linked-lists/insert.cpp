#include <stdlib.h>
#include <stdio.h>
#include "./headers/already-done.h"

Node *head = NULL;

void insertNode(int value, int position)
{
    Node *inserted = new Node();
    inserted->data = value;
    inserted->next = NULL;
    if (position == 1)
    {
        inserted->next = head;
        head = inserted;
        return;
    }
    Node *ref = head;

    for (int i = 0; i < position - 2; i++)
    {
        ref = ref->next;
    }
    inserted->next = ref->next;
    ref->next = inserted;
    return;
};

int main()
{
    insertNode(1, 1);
    insertNode(2, 2);
    insertNode(3, 1);
    insertNode(4, 2);

    printLinkedList(head);
}