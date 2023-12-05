#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int n)
    {
        data = n;
        next = NULL;
    }
};
class Stack
{
private:
    Node *head;

public:
    Stack()
    {
        head = NULL;
    }
    // Destructor
    ~Stack()
    {
        Node *temp;
        while (head != NULL)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
    void peek()
    {
        if (head != NULL)
        {
            cout << "\npeek: " << head->data << endl;
        }
        else
        {
            cout << "\nEmpty List" << endl;
        }
    }
    void push(int n)
    {
        Node *newNode = new Node(n);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }
    void pop()
    {
        if (head != NULL)
        {
            Node *temp = head;
            if (head->next == NULL)
            {
                head = NULL;
            }
            else
            {
                head = head->next;
            }
            delete temp;
        }
        else
        {
            cout << "\nEmpty List" << endl;
        }
    }
    bool isEmpty()
    {
        if (head == NULL)
        {
            return true;
        }
        return false;
    }
    void display()
    {
        if (head != NULL)
        {
            Node *temp = head;
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        else
        {
            cout << "\nEmpty List" << endl;
        }
    }
};
int main()
{
    Stack s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.peek();
    s1.display();
    s1.pop();
    s1.display();
    return 0;
}