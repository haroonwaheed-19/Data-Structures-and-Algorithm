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
    bool isCircular()
    {
        if (head != NULL)
        {
            if (tail->next == head)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        return false;
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
    bool isCircular()
    {
        if (head != NULL)
        {
            if (tail->next == head)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        return false;
    }
};
int main()
{
    CircularList c1;
    LinkedList l1;
    l1.insertAtHead(10);
    l1.insertAtHead(20);
    l1.insertAtTail(60);
    l1.insertAtTail(70);
    l1.insertAtTail(80);
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
    if (c1.isCircular())
    {
        cout << "\nC1 List is Circular" << endl;
    }
    else
    {
        cout << "\nC1 Not Circular" << endl;
    }
    if (l1.isCircular())
    {
        cout << "\nL1 List is Circular" << endl;
    }
    else
    {
        cout << "\nL1 Not Circular" << endl;
    }
    return 0;
}