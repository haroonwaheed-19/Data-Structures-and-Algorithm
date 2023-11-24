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
    void peek()
    {
        if (!isEmpty())
        {
            cout << "\nTop element of the Stack is : " << arr[top] << endl;
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
int main()
{
    int n = 5;
    Stack s1(5);
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.peek();
    s1.displayStack(); // 30 20 10
    s1.pop();          // 30
    s1.push(40);
    s1.push(50);
    s1.push(60);
    s1.pop();          // 60
    s1.peek();         // 50
    s1.displayStack(); // 50 40 20 10
    return 0;
}