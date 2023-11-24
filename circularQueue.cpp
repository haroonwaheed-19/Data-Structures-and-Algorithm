#include <iostream>
using namespace std;
class Queue
{
private:
    // data memebers
    int qfront, rear, size;
    int *arr;

public:
    // constructor going to initialize element with default values
    Queue(int s)
    {
        qfront = rear = -1;
        size = s;
        arr = new int[size]; // crearting dynamic array
    }

    // Destructor
    ~Queue()
    {
        delete[] arr;
        arr = NULL;
    }

    // function to check if queue is empty or not
    bool isEmpty()
    {
        if (qfront == -1)
        {
            return true;
        }
        return false;
    }

    // function to check if queue is full or not
    bool isFull()
    {
        if ((qfront == 0 && rear == size - 1) || qfront == rear + 1)
        {
            return true;
        }
        return false;
    }

    // insert or enqueue
    void enQueue(int n)
    {
        if (!isFull())
        {
            if (qfront == -1)
            {
                qfront = rear = 0;
                arr[rear] = n;
            }
            else
            {
                rear = (rear + 1) % size;
                arr[rear] = n;
            }
        }
        else
        {
            cout << "\nQueue Overflow" << endl;
        }
    }
    // deletion or dequeue
    void deQueue()
    {
        if (!isEmpty())
        {
            qfront = (qfront + 1) % size;
        }
        else
        {
            cout << "\nQueue underflow" << endl;
        }
    }
    // front element of the queue
    void frontElement()
    {
        if (!isEmpty())
        {
            cout << "\nFront element of the queue is : " << arr[qfront] << endl;
        }
        else
        {
            cout << "\nQueue Underflow" << endl;
        }
    }
    // print the Queue
    void displayQueue()
    {
        if (!isEmpty())
        {
            cout << "\nThe element in the stack is ";
            int i = qfront;
            if (qfront <= rear)
            {
                for (int j = i; j <= rear; j++)
                {
                    cout << arr[j] << " ";
                }
            }
            else
            {
                for (int j = i; j < size; j++)
                {
                    cout << arr[j] << " ";
                }
                for (int j = 0; j <= rear; j++)
                {
                    cout << arr[j] << " ";
                }
            }
            cout << endl;
        }
        else
        {
            cout << "Queue UnderFlow" << endl;
        }
    }
};
int main()
{
    int n = 5;
    Queue q1(5);
    q1.enQueue(10);
    q1.enQueue(20);
    q1.enQueue(30);
    q1.displayQueue(); // 10 20 30
    q1.frontElement(); // 10
    q1.enQueue(40);
    q1.enQueue(50);
    q1.enQueue(60); // overflow situation
    q1.deQueue();   // 10
    q1.enQueue(60);
    q1.frontElement(); // 20
    q1.displayQueue(); // 20 30 40 50 60
    q1.deQueue();//20
    q1.displayQueue(); //30 40 50 60
    return 0;
}