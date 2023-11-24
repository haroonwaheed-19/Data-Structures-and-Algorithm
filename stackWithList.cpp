#include <iostream>
using namespace std;
class Node
{
public:
    // data members
    int data;
    Node *next;
    // constructor
    Node(int n)
    {
        data = n;
        next = NULL;
    }
};
class Stack
{
    // data members
private:
    Node *top;

public:
    // constructor
    Stack()
    {
        top = NULL;
    }
    // Destructor
    ~Stack()
    {
        Node *temp;
        while (top != NULL)
        {
            temp = top;
            top = top->next;
            delete temp;
        }
    }

    bool isEmpty()
    {
        if (top == NULL)
        {
            return true;
        }
        return false;
    }

    void pop()
    {
        if (!isEmpty())
        {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
        else
        {
            cout << "\nStack UnderFlow" << endl;
        }
    }

    void topElement()
    {
        if (!isEmpty())
        {
            cout << "\nTop element in the stack is : " << top->data << endl;
        }
        else
        {
            cout << "\nStack UnderFlow" << endl;
        }
    }
    // insertion or push function
    void push(int n)
    {
        // creating new Node and assigning value to them using Node class Constructor
        Node *newNode = new Node(n);
        // checking if there is already any node present or not if not pointing top to this new node
        if (top == NULL)
        {
            top = newNode;
        }
        else
        {
            // node is already present now i have to point the newNode to top and make this new a top
            newNode->next = top;
            top = newNode;
        }
    }
    // display function for stack
    void display()
    {
        // creating a temp pointer which is going to point at top
        Node *temp = top;
        // we cannot move the top pointer this is the point from where our whole list is connected

        // checking if there is node present or node
        if (isEmpty())
        {
            cout << "\nStack UnderFlow" << endl;
        }
        else
        {
            // traversing from top till NULL
            cout << "\nThe element in the stack are : ";
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    Stack s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.topElement(); // 30
    s1.display();    // 30 20 10
    s1.push(35);
    s1.push(40);
    s1.topElement(); // 40
    s1.pop();        // 40
    s1.topElement(); // 35
    s1.pop();        // 35
    s1.display();    // 30 20 10
    return 0;
}