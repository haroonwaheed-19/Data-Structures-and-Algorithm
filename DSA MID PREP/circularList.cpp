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
class Circular
{
private:
    Node *head, *tail;

public:
    Circular()
    {
        head = tail = NULL;
    }
    // Destructor
    ~Circular()
    {
        Node *temp;
        do
        {
            temp = head;
            head = head->next;
            delete temp;
        } while (head != head);
    }
    void insertAtHead(int n)
    {
        Node *newNode = new Node(n);
        if (head == NULL)
        {
            head = tail = newNode;
            head->next = tail->next = head;
        }
        else
        {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }
    void insertAtTail(int n)
    {
        Node *newNode = new Node(n);
        if (head == NULL)
        {
            head = tail = newNode;
            head->next = tail->next = head;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }
    void printList()
    {
        if (head != NULL)
        {
            Node *temp = head;
            do
            {
                cout << temp->data << " ";
                temp = temp->next;
            } while (temp != head);
        }
        else
        {
            cout << "\nEmpty Circular List" << endl;
        }
    }
    void searchInList(int key)
    {
        if (head != NULL)
        {
            Node *temp = head;
            bool found = false;
            do
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
            } while (temp != head);

            if (found == true)
            {
                cout << "\nPresent" << endl;
            }
            else
            {
                cout << "\nNot Present" << endl;
            }
        }
        else
        {
            cout << "\nEmpty" << endl;
        }
    }
};
int main()
{
    Circular l1;
    l1.insertAtHead(10);
    l1.insertAtHead(5);
    l1.insertAtHead(1);
    l1.insertAtTail(20);
    l1.insertAtTail(30);
    l1.insertAtTail(40);
    l1.insertAtTail(50);
    l1.printList();
    l1.searchInList(40);
    return 0;
}