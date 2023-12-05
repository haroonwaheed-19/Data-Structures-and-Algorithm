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
class List
{
private:
    Node *head, *tail;

public:
    List()
    {
        head = tail = NULL;
    }
    // Destructor
    ~List()
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
    void middleElement()
    {
        if (head != NULL)
        {
            Node *fast, *slow, *pre;
            fast = slow = head;
            pre = NULL;

            while (fast != NULL && fast->next != NULL && fast->next->next != NULL)
            {
                fast = fast->next->next;
                pre = slow;
                slow = slow->next;
            }
            cout << slow->data << " " << endl;
        }
        else
        {
            cout << "\nEmpty" << endl;
        }
    }
};
int main()
{
    List l1;
    l1.insertAtHead(10);
    l1.insertAtHead(5);
    l1.insertAtHead(1);
    l1.insertAtTail(20);
    l1.insertAtTail(30);
    l1.insertAtTail(40);
    l1.insertAtTail(50);
    l1.insertAtTail(60);
    l1.printList();
    l1.middleElement();
    return 0;
}