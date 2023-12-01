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
    // deleting middle node of the list
    void deleteAtMid()
    {
        if (head != NULL)
        {
            Node *fast, *slow, *pre;
            fast = head;
            slow = head;
            pre = NULL;
            // this loop will help us to delete the element in odd case is (toatlNodes+1)/2 and in even case it will delete the (toatlNodes/2)
            while (fast != NULL && fast->next != NULL && fast->next->next != NULL)
            {
                fast = fast->next->next; // this pointer will skip one node and point to the next
                pre = slow;              // poitning to slow
                slow = slow->next;       // slow will point to next node
            }
            // this case is going to handle if the the first node is the middle node in case of odd number of nodes
            if (pre == NULL)
            {
                head = head->next;
                delete slow;
            }
            // slow is pointing to middle node
            pre->next = slow->next;
            delete slow;
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
    l1.display();     // 10 20 30 40 50 60
    l1.deleteAtMid(); // even case delete the 30
    // this display function will print 10 20 40 50 60
    cout << "\nDeletion middle Node in case of Even Numbers of Nodes in Linked List " << endl;
    l1.display();
    LinkedList l2;
    l2.insertAtHead(10);
    l2.insertAtTail(20);
    l2.insertAtTail(30);
    l2.insertAtTail(40);
    l2.insertAtTail(50);
    l1.display();     // 10 20 30 40 50
    l2.deleteAtMid(); // odd case it will delete 30
    cout << "\nDeletion middle Node in case of ODD Numbers of Nodes in Linked List " << endl;
    // this display function will print 10 20 40 50
    l2.display();
    return 0;
}