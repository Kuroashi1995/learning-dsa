#include <stdlib.h>
#include <stdio.h>

class Stack
{
public:
    void push(int x)
    {
        stack[++top] = x;
        return;
    };

    int pop()
    {
        return stack[top--];
    };

    int getTop()
    {
        return stack[top];
    };

    int isEmpty()
    {
        return top == -1;
    };

    void printStack()
    {
        for (int i = 0; i <= top; i++)
        {
            printf("%d", stack[i]);
        };
        printf("\n");
        return;
    }

    Stack(int Paramsize)
    {
        stack = new int[Paramsize];
        size = Paramsize;
    };

private:
    int size;
    int *stack;
    int top = -1;
};

int main()
{
    Stack *stackTest = new Stack(10);
    printf("Is the stack empty? %d\n", stackTest->isEmpty());
    stackTest->push(1);
    stackTest->printStack();
    stackTest->push(2);
    stackTest->printStack();
    stackTest->push(3);
    stackTest->printStack();
    int firstPop = stackTest->pop();
    printf("The value popped is: %d\n", firstPop);
    stackTest->push(4);
    stackTest->printStack();
    stackTest->push(5);
    stackTest->printStack();
    delete (stackTest);
}