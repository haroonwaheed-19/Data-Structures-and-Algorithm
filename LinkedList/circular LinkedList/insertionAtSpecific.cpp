#include <iostream>
#include <string>
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
class CircularList
{
private:
    Node *head, *tail;

public:
    CircularList()
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
            head->next = tail->next = head; // mointing head and tail next to head
        }
        else
        {
            // at least one node exists in the list
            newNode->next = head;
            head = newNode;
            tail->next = head; // pointing last node to head
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
            head->next = tail->next = head; // mointing head and tail next to head
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }
    void insertAtSpecific(int pos, int n)
    {
        // creating a new node
        Node *newNode = new Node(n);
        // checking if list is empty or not
        if (pos <= 0)
        {
            cout << "\nInvalid position" << endl;
        }
        else if (head == NULL || pos == 1)
        {
            head = tail = newNode;
            head->next = tail->next = head; // mointing head and tail next to head
        }
        else
        {
            int count = 1;
            Node *temp = head;
            while (count < pos - 1 && temp->next != head)
            {
                temp = temp->next;
                count++;
            }
            if (temp->next != head)
            {
                newNode->next = temp->next;
                temp->next = newNode;
                if (newNode->next == NULL)
                {
                    tail = newNode;
                    tail->next = head;
                }
            }
            else
            {
                cout << "\n"
                     << pos << " is Invalid Node so adding " << n << " in the tail" << endl;
                insertAtTail(n);
            }
        }
    }
    // dispaly the circular list
    void displayList()
    {
        // if list is not empty
        if (head != NULL)
        {
            cout << "\nElements in the list are : ";
            Node *temp = head;
            while (temp->next != head)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            // printing the last node data because it is left behind
            cout << temp->data << " ";
            cout << endl;
        }
        else
        {
            cout << "\nEmpty list" << endl;
        }
    }
};
int main()
{
    CircularList c1;
    // insertion at head
    c1.insertAtHead(10);
    c1.insertAtTail(20);
    c1.insertAtTail(30);
    c1.insertAtTail(40);
    c1.insertAtTail(50);
    c1.displayList(); // 10 20 30 40 50
    c1.insertAtSpecific(4, 35);
    c1.insertAtSpecific(5, 38);
    c1.insertAtSpecific(7, 46);
    c1.displayList(); // 10 20 30 35 38 40 46 50
    c1.insertAtSpecific(9, 60);
    c1.displayList(); // 10 20 30 35 38 40 46 50 60
    c1.insertAtSpecific(10, 65);
    c1.insertAtSpecific(11, 85);
    c1.insertAtSpecific(11, 80);
    c1.displayList(); // 10 20 30 35 38 40 46 50 60 65 80 85

    return 0;
}