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

    void deleteAtSpecific(int pos)
    {
        if (head != NULL)
        {
            Node *temp = head;
            Node *toDelete;
            int count = 1;
            while (count < pos - 1 && temp->next != NULL)
            {
                temp = temp->next;
                count++;
            }
            if (pos == 1)
            {
                head = head->next;
                if (head != NULL)
                {
                    head->prev = NULL;
                }
                delete temp;
                return;
            }
            if (temp->next != NULL)
            {
                toDelete = temp->next;
                temp->next = toDelete->next;
                if (toDelete->next != NULL)
                {
                    toDelete->next->prev = temp;
                }
                delete toDelete;
            }
            else
            {
                cout << "\nOut of Bound position" << endl;
                return;
            }
        }
        else
        {
            cout << "\nEmpty List" << endl;
        }
    }
};
int main()
{
    DoubleList d1, d2;
    // insertion at head
    d1.insertAtHead(10);
    d1.insertAtTail(20);
    d1.insertAtTail(30);
    d1.insertAtTail(40);
    d1.insertAtTail(50);
    d1.displayList(); // 10 20 30 40 50
    d1.deleteAtSpecific(1);
    d1.displayList();
    return 0;
}