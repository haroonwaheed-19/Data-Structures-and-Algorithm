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
        if (qfront == 0 && rear == size - 1)
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
                rear++;
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
            // add a check if front equal to rear that means end of the queue so assigning them a null value
            if (qfront == rear)
            {
                qfront = rear = -1;
            }
            else
            {
                qfront++;
            }
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
            cout << "\nThe element in the Queue are : ";
            for (int i = qfront; i <= rear; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "Queue UnderFlow" << endl;
        }
    }
    // sorting the elements in the Queue
    void sortQueueInDescending()
    {
        if (!isEmpty())
        {
            for (int i = 0; i < size; i++)
            {
                for (int j = i + 1; j <= size; j++)
                {
                    if (arr[i] < arr[j])
                    {
                        // Swap the elements to sort in ascending order
                        int temp = arr[j];
                        arr[j] = arr[i];
                        arr[i] = temp;
                    }
                }
            }
        }
        else
        {
            cout << "\nQueue Empty" << endl;
        }
    }
};
int main()
{
    int n = 5;
    Queue q1(5);
    q1.enQueue(10);
    q1.enQueue(30);
    q1.enQueue(20);
    q1.displayQueue(); // 10 20 30
    q1.frontElement(); // 10
    q1.enQueue(50);
    q1.enQueue(40);
    q1.enQueue(60);    // overflow situation
    q1.deQueue();      // 10
    q1.frontElement(); // 20
    cout << "\n\t\tBefore Sorting" << endl;
    q1.displayQueue(); // 30 20 50 40
    q1.sortQueueInDescending();
    cout << "\n\t\tAfter Sorting" << endl;
    q1.displayQueue(); // 50 40 30 20
    return 0;
}