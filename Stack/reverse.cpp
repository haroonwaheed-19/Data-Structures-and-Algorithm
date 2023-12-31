#include <iostream>
using namespace std;
class Stack
{
private:
    // data memebers
    int top, size;
    int *arr;

public:
    // constructor going to initialize element with default values
    Stack(int s)
    {
        top = -1;
        size = s;
        arr = new int[size]; // crearting dynamic array
    }

    // Destructor
    ~Stack()
    {
        delete[] arr;
        arr = NULL;
    }

    // function to check if Stack is empty or not
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }

    // function to check if Stack is full or not
    bool isFull()
    {
        if (top >= size - 1)
        {
            return true;
        }
        return false;
    }

    // insert or push
    void push(int n)
    {
        if (!isFull())
        {
            top++;
            arr[top] = n;
        }
        else
        {
            cout << "\nStack Overflow" << endl;
        }
    }

    // deletion or pop
    void pop()
    {
        if (!isEmpty())
        {
            top--;
        }
        else
        {
            cout << "\nStack underflow" << endl;
        }
    }
    // front element of the Stack
    int peek()
    {
        if (!isEmpty())
        {
            return arr[top];
        }
        else
        {
            cout << "\nStack Underflow" << endl;
        }
    }
    // print the Stack
    void displayStack()
    {
        if (!isEmpty())
        {
            cout << "\nThe element in the Stack are : ";
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "Stack UnderFlow" << endl;
        }
    }
};
void reverseStack(Stack &s1, Stack &s2)
{
    while (!s1.isEmpty())
    {
        s2.push(s1.peek());
        s1.pop();
    }
}

int main()
{
    int n = 6;
    Stack s1(n);
    Stack s2(n);
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.displayStack(); // 30 20 10
    s1.push(40);
    s1.peek();
    s1.push(50);
    s1.push(60);
    s1.peek();
    cout << "\n\t\tBefore reversing" << endl;
    s1.displayStack(); // 60 50 40 30 20 10
    reverseStack(s1, s2);
    cout << "\n\t\tAfter reversing" << endl;
    s2.displayStack(); // 10 20 30 40 50 60
    return 0;
}