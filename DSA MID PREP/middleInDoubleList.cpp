#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int n)
    {
        data = n;
        next = prev = NULL;
    }
};
class DoubleList
{
private:
    Node *head, *tail;

public:
    DoubleList()
    {
        head = tail = NULL;
    }
    // Destructor
    ~DoubleList()
    {
        Node *temp;
        while (head != NULL)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
    void insertAtHead(int n)
    {
        Node *newNode = new Node(n);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    void insertAtTail(int n)
    {
        Node *newNode = new Node(n);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void printList()
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
    void printReverseList()
    {
        if (head != NULL)
        {
            Node *temp = tail;
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->prev;
            }
            cout << endl;
        }
        else
        {
            cout << "\nEmpty List" << endl;
        }
    }
    void middleNode()
    {
        if (head != NULL)
        {
            Node *start, *end;
            start = head, end = tail;
            while (start != end && start->next != end)
            {
                start = start->next;
                end = end->prev;
            }
            cout << "\nMiddle Node element is : " << start->data << endl;
        }
        else
        {
            cout << "\nEmpty List" << endl;
        }
    }
};
int main()
{
    DoubleList l1;
    l1.insertAtHead(10);
    l1.insertAtHead(5);
    l1.insertAtHead(1);
    l1.insertAtTail(20);
    l1.insertAtTail(30);
    l1.insertAtTail(40);
    l1.insertAtTail(50);
    l1.insertAtTail(60);
    l1.printList();
    l1.middleNode();
    l1.printReverseList();
    return 0;
}