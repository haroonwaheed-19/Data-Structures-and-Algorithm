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
    void NodeAtMid()
    {
        if (head != NULL)
        {
            Node *fast, *slow, *pre;
            fast = head;
            slow = head;
            pre = NULL;
            // this loop will help us to delete the element in odd case is (toatlNodes+1)/2 and in even case it will delete the (toatlNodes/2)
            while (fast->next != head && fast->next->next != head)
            {
                fast = fast->next->next; // this pointer will skip one node and point to the next
                pre = slow;              // poitning to slow
                slow = slow->next;       // slow will point to next node
            }
            // this case is going to handle if the the first node is the middle node in case of odd number of nodes
            cout << "\nMid is " << slow->data << endl;
        }
    }
};
int main()
{
    CircularList c1;
    c1.insertAtTail(60);
    c1.insertAtTail(70);
    c1.insertAtTail(80);
    c1.insertAtTail(90);
    c1.insertAtTail(100);
    c1.insertAtTail(110);
    c1.insertAtTail(120);
    c1.displayList(); // 50 40 30 20 10 60 70 80 90 100
    c1.NodeAtMid();
    return 0;
}