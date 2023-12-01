#include <iostream>
#include <string>
using namespace std;
class Node
{
public:
    int data;
    Node *next, *prev;
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
    // insertion at head
    void insertAtHead(int n)
    {
        // creating a new node
        Node *newNode = new Node(n);
        // checking if list is empty or not
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            // at least one node exists in the list
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    // insertion at tail
    void insertAtTail(int n)
    {
        // creating a new node
        Node *newNode = new Node(n);
        // checking if list is empty or not
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
    // dispaly the circular list
    void displayList()
    {
        // if list is not empty
        Node *temp = head;
        if (head != NULL)
        {
            cout << "\nElements in the list are : ";
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
        else
        {
            cout << "\nEmpty list" << endl;
        }
    }
    // insert at specified position
    void insertAtSpecific(int pos, int n)
    {
        Node *newNode = new Node(n);
        if (pos <= 0)
        {
            cout << "\nInvalid position" << endl;
        }
        else if (head == NULL || pos == 1)
        {
            insertAtHead(n);
        }
        else
        {
            int count = 1;
            Node *temp = head;
            while (count < pos - 1 && temp != NULL)
            {
                temp = temp->next;
                count++;
            }
            if (temp != NULL && temp->next != NULL)
            {
                newNode->next = temp->next;
                newNode->prev = temp;
                temp->next = newNode;
                if (newNode->next == NULL)
                {
                    tail = newNode;
                    tail->prev = temp;
                }
            }
            else
            {
                cout << "\n"
                     << pos << " is Invalid node so adding " << n << " in the tail" << endl;
                insertAtTail(n);
            }
        }
    }
};
int main()
{
    DoubleList d1, d2;
    // insertion at head
    d1.insertAtHead(20);
    d1.insertAtHead(10);
    d1.displayList(); // 10 20
    d1.insertAtTail(30);
    d1.insertAtTail(40);
    d1.insertAtSpecific(1, 5);
    d1.insertAtSpecific(5, 35);
    d1.displayList();            // 5 10 20 30 35 40
    d1.insertAtSpecific(7, 45);  // out of bound position
    d1.insertAtSpecific(50, 50); // out of bound position
    d1.displayList();            // 5 10 20 30 35 40 50
    return 0;
}