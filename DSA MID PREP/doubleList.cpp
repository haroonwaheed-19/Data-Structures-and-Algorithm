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
    void searchInList(int key)
    {
        if (head != NULL)
        {
            Node *temp = head;
            bool found = false;
            while (temp != NULL)
            {
                if (temp->data == key)
                {
                    found = true;
                    break;
                }
                else
                {
                    temp = temp->next;
                }
            }
            if (found == true)
            {
                cout << "\nPresent" << endl;
            }
            else
            {
                cout << "\nNot Present" << endl;
            }
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
    l1.printList();
    l1.printReverseList();
    l1.searchInList(100); // Not present
    l1.searchInList(30);  // present
    return 0;
}