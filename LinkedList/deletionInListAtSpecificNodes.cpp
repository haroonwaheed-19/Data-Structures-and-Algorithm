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
    // Deleting Node at Tail
    void deleteAtTail()
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
                // this will stop the temp before the tail
                while (temp->next->next != NULL)
                {
                    temp = temp->next;
                }
                Node *toDelete = temp->next;
                temp->next = NULL;
                // pointing the tail at the temp
                tail = temp;
                delete toDelete;
            }
        }
        else
        {
            cout << "\nList is Empty" << endl;
        }
    }
    // Deletion at Specific Node
    void deleteAtSpecificNode(int pos)
    {
        if (head != NULL)
        {
            Node *temp = head;
            if (pos <= 0)
            {
                cout << "\nInvalid Position" << endl;
            }
            else if (pos == 1)
            {
                // Deleting the head
                if (head->next == NULL)
                {
                    head = tail = NULL;
                    delete temp;
                }
                else
                {
                    head = head->next;
                    delete temp;
                }
            }
            else
            {
                int count = 1;
                // To stop temp 1 node before the node to delete
                while (count < pos - 1 && temp != NULL && temp->next != NULL)
                {
                    temp = temp->next;
                    count++;
                }

                // Check if position is within the bounds of the list
                if (temp != NULL && temp->next != NULL)
                {
                    Node *toDelete = temp->next;
                    // Pointing temp to next of node to delete
                    temp->next = toDelete->next;
                    if (temp->next == NULL)
                    {
                        // temp is the last node so pointing tail to this
                        tail = temp;
                    }
                    delete toDelete;
                }
                else
                {
                    cout << "\nOut of Bound Position" << endl;
                }
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
    l1.insertAtTail(20);
    l1.insertAtTail(30);
    l1.insertAtTail(40);
    l1.insertAtTail(50);
    l1.insertAtTail(60);
    cout << "\n\t\tBefore Deleting" << endl;
    l1.display();               // 10 20 30 40 50 60
    l1.deleteAtSpecificNode(3); // 20
    l1.deleteAtSpecificNode(1); // 10
    cout << "\n\t\tAfter Deleting" << endl;
    l1.display(); // 20 40 50 60
    cout << "\n\t\t2nd Object" << endl;
    LinkedList l2;
    l2.insertAtHead(50);
    l2.insertAtHead(40);
    l2.insertAtHead(30);
    l2.insertAtTail(60);
    l2.insertAtTail(70);
    cout << "\n\t\tBefore Deleting" << endl;
    l2.display();               // 30 40 50 60 70
    l2.deleteAtSpecificNode(2); // 40
    l2.deleteAtSpecificNode(5); // error out of bound position
    cout << "\n\t\tAfter Deleting" << endl;
    l2.display(); // 30 50 60 70
    return 0;
}