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
    // dispaly the circular list
    void displayList()
    {
        // if list is not empty
        if (head != NULL)
        {
            cout << "\n\t\tElements in the list are" << endl;
            Node *temp = head;
            while (temp->next != head)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            // printing the last node data because it is left behind
            cout << temp->data << " ";
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
    c1.insertAtHead(20);
    c1.insertAtHead(30);
    c1.insertAtHead(40);
    c1.insertAtHead(50);
    c1.displayList(); // 50 40 30 20 10
    c1.insertAtTail(60);
    c1.insertAtTail(70);
    c1.insertAtTail(80);
    c1.insertAtTail(90);
    c1.insertAtTail(100);
    c1.displayList(); // 50 40 30 20 10 60 70 80 90 100
    return 0;
}