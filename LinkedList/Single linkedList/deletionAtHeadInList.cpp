#include <iostream>
using namespace std;
class Node
{
public:
    // data members
    int data;
    Node *next;
    // constructor
    Node(int n)
    {
        data = n;
        next = NULL;
    }
};
class LinkedList
{
    // data members
private:
    Node *head, *tail;

public:
    // constructor
    LinkedList()
    {
        head = NULL;
        tail = NULL;
    }
    // Destructor
    ~LinkedList()
    {
        Node *temp;
        while (head != NULL)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
    // insertion at head or prepend function
    void insertAtHead(int n)
    {
        // creating new Node and assigning value to them using Node class Constructor
        Node *newNode = new Node(n);
        // checking if there is already any node present or not if not pointing head and tail to this new node
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            // node is already present now i have to point the newNode to head and make this new a head
            newNode->next = head;
            head = newNode;
        }
    }

    // insertion at tail or prepend
    void insertAtTail(int n)
    {
        // creating a newNode and storing data into this node
        Node *newNode = new Node(n);

        // checking if there is any node present or not if not making this node a head and tail
        if (head == NULL)
        {
            // user called this function without making a head node so make this a head and tail
            head = tail = newNode;
        }
        else
        {
            // some nodes already present pointing tail->next to this node and making this node a new Tail
            tail->next = newNode;
            tail = newNode;
        }
    }
    // display function for linkedList
    void display()
    {
        // creating a temp pointer which is going to point at head
        Node *temp = head;
        // we cannot move the head pointer this is the point from where our whole list is connected

        // checking if there is node present or node
        if (head == NULL)
        {
            cout << "\nEmpty linkedList" << endl;
        }
        else
        {
            // traversing from head till NULL
            cout << "\nThe element in the list are : ";
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
    // Deleting Node at Head
    void deleteAtHead()
    {
        // checking if there is any node present or not
        if (head != NULL)
        {
            Node *temp = head;
            // if only one Node exist in the list
            if (head->next == NULL)
            {
                head = tail = NULL;
                delete temp;
            }
            else
            {
                // Moving head to next Node
                head = head->next;
                delete temp;
            }
        }
        else
        {
            cout << "\nList is Empty" << endl;
        }
    }
};
int main()
{

    // making object of the class
    LinkedList l1;
    l1.insertAtHead(10);
    l1.insertAtHead(5);
    l1.insertAtTail(20);
    l1.insertAtTail(30);
    l1.insertAtTail(40);
    l1.insertAtTail(50);
    l1.insertAtTail(60);
    cout << "\n\t\tBefore Deleting the Head" << endl;
    l1.display();      // 5 10 20 30 40 50 60
    l1.deleteAtHead(); // 5
    cout << "\n\t\tAfter Deleting the Head" << endl;
    l1.display(); // 10 20 30 40 50 60
    LinkedList l2;
    cout << "\n\t\t2nd Object" << endl;
    l2.insertAtHead(50);
    l2.display();      // 50
    l2.deleteAtHead(); // 50
    l2.display();      // empty list
    return 0;
}