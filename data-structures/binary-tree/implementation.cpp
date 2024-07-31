#include <stdio.h>
#include <stdlib.h>

class Node
{
public:
    Node *left;
    Node *right;
    int data;
};

class BinaryTree
{
public:
    Node *search(int data)
    {
        if (root == NULL)
        {
            printf("Tree is empty");
            return NULL;
        }
        return checkValue(data, root, 2);
    };
    void addValue(int data)
    {
        if (root == NULL)
        {
            root = new Node();
            root->data = data;
            root->left = NULL;
            root->right = NULL;
        }
        checkValue(data, root, 1);
    };
    void deleteValue();

private:
    Node *root;
    Node *checkValue(int valToCheck, Node *currentNode, int mode)
    // mode: 1: insert, 2: search, 3: delete (not implemented yet)
    {
        if (valToCheck > currentNode->data)
        {
            if (currentNode->right == NULL)
            {
                if (mode == 1)
                {
                    Node *newNode = new Node();
                    newNode->data = valToCheck;
                    currentNode->right = newNode;
                    return newNode;
                }
                else if (mode == 2)
                {
                    return NULL;
                }
            }
            else
            {
                return checkValue(valToCheck, currentNode->right, mode);
            }
        }
        else
        {
            if (currentNode->data == valToCheck && mode == 2)
            {
                return currentNode;
            }
            if (currentNode->left == NULL)
            {
                if (mode == 1)
                {
                    Node *newNode = new Node();
                    newNode->data = valToCheck;
                    currentNode->left = newNode;
                    return newNode;
                }
                else if (mode == 2)
                {
                    return NULL;
                }
            }
            else
            {
                return checkValue(valToCheck, currentNode->left, mode);
            }
        }
    };
};

int main()
{
    BinaryTree *newTree = new BinaryTree();
    newTree->addValue(1);
    newTree->addValue(2);
    newTree->addValue(3);
    newTree->addValue(4);
    newTree->addValue(4);
    Node *searchResult = newTree->search(3);
    printf("If a value was found it should show a 3 here -> %d", searchResult->data);
}