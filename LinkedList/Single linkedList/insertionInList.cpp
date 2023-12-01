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
    // insert node at specific location
    void insertAtPosition(int pos, int num)
    {
        // checking if there is already any node present or not
        if (head == NULL)
        {
            cout << "\nNothing in the list right now so adding this at head" << endl;
            insertAtHead(num);
        }
        else if (pos == 1)
        {
            insertAtHead(num);
        }
        else
        {
            Node *newNode = new Node(num);
            int count = 1;
            Node *temp = head;
            while (count < pos - 1 && temp != NULL)
            {
                temp = temp->next;
                count++;
            }

            // this will help to get rid from if user add a position greater than nodes
            if (temp != NULL)
            {
                newNode->next = temp->next;
                temp->next = newNode;
                if (newNode->next == NULL)
                {
                    tail = newNode;
                }
            }
            else
            {
                cout << "\nInvalid Position" << endl;
            }
        }
    }
};
int main()
{

    // making object of the class
    LinkedList l1;
    l1.insertAtPosition(5, 10);
    l1.display(); // 10
    l1.insertAtHead(10);
    l1.insertAtTail(20);
    l1.insertAtTail(30);
    l1.insertAtTail(40);
    l1.display(); // 10 10 20 30 40
    l1.insertAtPosition(4, 25);
    l1.insertAtPosition(6, 35);
    l1.insertAtPosition(8, 45);
    l1.insertAtPosition(15, 50); // Invalid Position
    // this display function will print 10 10 20 25 30 35 40 45
    l1.display();
    return 0;
}