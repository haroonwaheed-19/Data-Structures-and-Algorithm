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
class Queue
{
    // data members
private:
    Node *front, *rear;

public:
    // constructor
    Queue()
    {
        front = NULL;
        rear = NULL;
    }
    // Destructor
    ~Queue()
    {
        Node *temp;
        while (front != NULL)
        {
            temp = front;
            front = front->next;
            delete temp;
        }
    }

    bool isEmpty()
    {
        if (front == NULL)
        {
            return true;
        }
        return false;
    }

    // insertion or enQueue
    void enQueue(int n)
    {
        // creating a newNode and storing data into this node
        Node *newNode = new Node(n);

        // checking if there is any node present or not if not making this node a front and rear
        if (front == NULL)
        {
            // user called this function without making a front node so make this a front and rear
            front = rear = newNode;
        }
        else
        {
            // some nodes already present pointing rear->next to this node and making this node a new rear
            rear->next = newNode;
            rear = newNode;
        }
    }

    // deletion or dequeue
    void deQueue()
    {
        if (!isEmpty())
        {
            Node *temp = front;
            front = front->next;
            delete temp;
        }
        else
        {
            cout << "\nQueue UnderFlow" << endl;
        }
    }

    // front element in the Queue
    void Front()
    {
        if (!isEmpty())
        {
            cout << "\nThe element at front is : " << front->data << endl;
        }
        else
        {
            cout << "\nQueue UnderFlow" << endl;
        }
    }

    // display function for Queue
    void display()
    {
        // creating a temp pointer which is going to point at front
        Node *temp = front;
        // we cannot move the front pointer this is the point from where our whole list is connected

        // checking if there is node present or node
        if (front == NULL)
        {
            cout << "\nEmpty Queue" << endl;
        }
        else
        {
            // traversing from front till NULL
            cout << "\nThe element in the Queue are : ";
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};
int main()
{

    // making object of the class
    Queue q1;
    q1.enQueue(10);
    q1.enQueue(20);
    q1.enQueue(30);
    q1.Front(); // 10
    // this display function will print 10 20 30
    q1.display();
    q1.deQueue(); // 10
    q1.Front();   // 20
    q1.enQueue(35);
    q1.enQueue(40);
    q1.display(); // 20 30 35 40
    return 0;
}