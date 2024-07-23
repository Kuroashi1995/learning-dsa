#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    Node *next;
    Node *prev;
};
Node *head = NULL;
Node *tail = NULL;

Node *createNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtHead(int data)
{
    Node *temp = createNode(data);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
        return;
    }
    temp->next = head;
    head->prev = temp;
    head = temp;
    return;
}

void insertAtTail(int data)
{
    Node *temp = createNode(data);
    if (tail == NULL)
    {
        tail = temp;
        head = temp;
        return;
    }
    temp->prev = tail;
    tail->next = temp;
    tail = temp;
};

void printList(Node *node)
{
    printf("%d", node->data);
    if (node == tail)
    {
        return;
    }
    printList(node->next);
}

int main()
{
    insertAtHead(1);
    insertAtTail(2);
    insertAtTail(3);
    insertAtTail(4);

    printList(head);
}
