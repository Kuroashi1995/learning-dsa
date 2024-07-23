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

int main()
{
    Node *a = new Node();
    Node *b = new Node();
    Node *c = new Node();
    Node *d = new Node();
    a->data = 1;
    a->next = b;
    b->data = 2;
    b->next = c;
    c->data = 3;
    c->next = d;
    d->data = 4;
    d->next = NULL;

    printLinkedList(a);

    delete (a);
    delete (b);
    delete (c);
    delete (d);
}