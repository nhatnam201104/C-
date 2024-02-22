#include <iostream>
using namespace std;
const int MAX_SIZE = 100;
class Stack
{
private:
    int top;
    int array[MAX_SIZE];

public:
    Stack()
    {
        top = -1;
    }
    bool isEmpty()
    {
        return top == -1;
    }
    bool isFull()
    {
        return top == MAX_SIZE - 1;
    }
    void push(int value)
    {
        if (isFull())
        {
            std::cout << "Stack overflow!" << std::endl;
        }
        else
        {
            array[++top] = value;
        }
    }
    int topval ()
    {
        return array [top];
    }
    int pop()
    {
        if (isEmpty())
        {
            std::cout << "Stack underflow!" << std::endl;
            return -1;
        }
        else
        {
            return array[top--];
        }
    }
};

int main()
{
    Stack myStack;
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    while (!myStack.isEmpty())
    {
        cout<<myStack.topval()<<" ";
        myStack.pop();
    }
    
    return 0;
}
