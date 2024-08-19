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
		else {
			checkValue(data, root, 1);
		}
	};
	//void deleteValue();
	int findMax() {
		return findMaxRecursive(root);
	}
	int findMin() {
		return findMinRecursive(root);
	}
	int findHeight() {
		return findHeightRecursive(root);
	}

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
	int findMaxRecursive(Node *currentNode) {
		if (currentNode->right == NULL) {
			return currentNode->data;
		}
		else {
			return findMaxRecursive(currentNode->right);
		}
	}
	int findMinRecursive(Node *currentNode) {
		if (currentNode->left == NULL) {
			return currentNode->data;
		}
		else {
			return findMinRecursive(currentNode->left);
		}
	}
	int findHeightRecursive(Node *currentNode) {
		int heightLeft, heightRight;
		if (currentNode->left == NULL && currentNode->right == NULL) {
			return 0;
		}
		if (currentNode->left != NULL){
			heightLeft = findHeightRecursive(currentNode->left);
		}
		else {
			heightLeft = -1;
		}
		if (currentNode->right != NULL){
			heightRight = findHeightRecursive(currentNode->right);
		}
		else {
			heightRight= -1;
		}
		return (heightLeft > heightRight ? heightLeft : heightRight) + 1;
	}
};

int main()
{
	printf("running Binary Tree Implementation \n");
	BinaryTree *newTree = new BinaryTree();
	newTree->addValue(10);
	newTree->addValue(12);
	newTree->addValue(3);
	newTree->addValue(44);
	newTree->addValue(49);
	newTree->addValue(42);
	Node *searchResult = newTree->search(3);
	printf("If a value was found it should show a 3 here -> %d\n", searchResult->data);
	int max = newTree->findMax();
	int min = newTree->findMin();	
	printf("Max: %d, Min: %d\n", max, min);
	newTree->addValue(55);
	int height = newTree->findHeight();
	printf("The height of the tree is %d\n", height);
}
