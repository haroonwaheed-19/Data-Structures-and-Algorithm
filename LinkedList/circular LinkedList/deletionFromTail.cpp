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
            cout << "\nElements in the list are ";
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
    // deletion at head
    void deleteAtTail()
    {
        // if list is not empty
        if (head != NULL)
        {
            Node *temp = head;
            if (temp->next == head)
            {
                // only one node exist which is to delete
                head = tail = NULL;
                delete temp;
            }
            else
            {
                while (temp->next->next != head)
                {
                    temp = temp->next;
                }
                if (temp->next != head)
                {
                    Node *toDelete = temp->next;
                    tail = temp;
                    tail->next = head;
                    delete toDelete;
                }
            }
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
    // insertion
    c1.insertAtTail(10);
    c1.insertAtTail(20);
    c1.insertAtTail(30);
    c1.insertAtTail(40);
    c1.insertAtTail(50);
    c1.insertAtTail(60);
    cout << "\n\t\tBefore Deleting from Tail" << endl;
    c1.displayList(); // 10 20 30 40 50 60
    c1.deleteAtTail();
    cout << "\n\t\tAfter Deleting from Tail" << endl;
    c1.displayList(); // 10 20 30 40 50

    return 0;
}
