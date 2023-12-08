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
    void reverseListUingNode()
    {
        if (head != NULL)
        {
            Node *current = head;
            Node *temp = NULL;

            while (current != NULL)
            {
                // Swap next and prev pointers
                temp = current->prev;
                current->prev = current->next;
                current->next = temp;

                // Move to the next node
                current = current->prev;
            }

            // Update head and tail after reversing
            temp = head;
            head = tail;
            tail = temp;
        }
        else
        {
            cout << "\nEmpty List" << endl;
        }
    }
    void reverseList()
    {
        if (head != NULL)
        {
            Node *start = head;
            Node *end = tail;
            while (start != end && start->prev != end)
            {
                int data = start->data;
                start->data = end->data;
                end->data = data;

                start = start->next;
                end = end->prev;
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
    DoubleList d1;
    // insertion at head
    d1.insertAtHead(10);
    d1.insertAtHead(20);
    d1.insertAtHead(30);
    d1.insertAtHead(40);
    d1.insertAtHead(50);
    d1.displayList(); // 50 40 30 20 10
    d1.insertAtTail(60);
    d1.insertAtTail(70);
    d1.insertAtTail(80);
    d1.insertAtTail(90);
    d1.insertAtTail(100);
    d1.displayList(); // 50 40 30 20 10 60 70 80 90 100
    cout << "\n\t\tBefore Reversing" << endl;
    d1.displayList();
    d1.reverseListUingNode();
    cout << "\n\t\tAfter Reversing" << endl;
    d1.displayList();
    return 0;
}