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
    // searching in the Stack
    void search(int key)
    {
        if (!isEmpty())
        {
            bool found = false;
            for (int i = 0; i < size - 1; i++)
            {
                if (key == arr[i])
                {
                    cout << "\n"
                         << key << " is present in the Stack" << endl;
                    found = true;
                }
            }
            if (found == false)
            {
                cout << "\n"
                     << key << " Not present in the Stack" << endl;
            }
        }
        else
        {
            cout << "\nStack UnderFlow" << endl;
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
    s1.displayStack(); // 10 20 30
    s1.pop();          // 10
    s1.push(40);
    s1.push(50);
    s1.push(60);       // overflow situation
    s1.pop();          // 10
    s1.peek();         // 20
    s1.displayStack(); // 20 30 40 50
    s1.search(60);     // Not present
    s1.search(100);    // Not present
    s1.search(40);     // present
    return 0;
}