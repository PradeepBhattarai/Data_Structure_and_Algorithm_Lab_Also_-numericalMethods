#include<iostream>
#define Max 100
using namespace std;
class cQueue
{
    int arr[Max];
    int front;
    int rear;
public:
    cQueue()
    {
        front=rear=-1;
    }
    void Enqueue(int x)
    {
        if((rear+1)%Max==front)
        {
            cout<<"Queue Overflow"<<endl;
        }
        else if(front==-1 && rear==-1)
        {
            front=rear=0;
        }
        else
        {
            rear=(rear+1)%Max;
        }
        arr[rear]=x;
    }
    void Deque()
    {
        if(front==rear==-1)
        {
            cout<<"Dequeue is Underflow"<<endl;
        }
        else if(front==rear)
        {
            front=rear=-1;
        }
        else
        {
            front=(front+1)%Max;
        }
    }
    void Display()
    {
        if (front <= rear)
        {
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << "  ";
            }
            cout<<endl;
        }
        else
        {
            for (int i = front; i < Max; i++)
                cout << arr[i] << "  ";
            for (int i = 0; i <= rear; i++)
                cout << arr[i] << "  ";
            cout << endl;
        }
    }
};
int main()
{
    cQueue cq;
    cq.Enqueue(5);
    cq.Enqueue(4);
    cq.Enqueue(6);
    cq.Display();
    cq.Deque();
    cq.Display();
    cq.Enqueue(5);
    cq.Display();
    return 0;
}