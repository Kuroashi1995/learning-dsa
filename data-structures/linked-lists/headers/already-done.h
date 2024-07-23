#include <stdlib.h>
#include <stdio.h>
struct Node
{
    int data;
    struct Node *next;
};

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
