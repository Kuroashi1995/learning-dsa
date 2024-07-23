#include <stdlib.h>
#include <stdio.h>
struct Node
{
    int data;
    struct Node *next;
};

extern Node *head;

void printLinkedList(Node *head)
{
    Node *p = head;
    printf("%d", p->data);
    if (p->next == NULL)
    {
        return;
    }
    else
    {

        printLinkedList(p->next);
    }
}

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