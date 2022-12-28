#include<iostream>

#define MAX 100
using namespace std;
class Queue
{
    int arr[MAX];
    int front;
    int rear;
public:
    Queue()
    {
        front =-1;
        rear=-1;
    }
    void Enqueue(int x)
    {
        if(front==-1)
        {
            rear=front=0;
            arr[0]=x;
        }
        else if(rear==MAX-1)
        {
            cout<<"Queue Overflow."<<endl;
            return;
        }
        else
        {
            rear++;
            arr[rear]=x;
        }
    }
    void Dequeue()
    {
        if(rear==front==-1)
        {
            cout<<"Underflow"<<endl;
            return;
        }
        else
        {
            front++;
        }
    }
    void Display()
    {
        for(int i=front;i<=rear;i++)
        {
            cout<<arr[i]<<"  ";
        }
        cout<<endl;
    }
};
int main()
{
    Queue q;
    q.Enqueue(4);
    q.Enqueue(6);
    q.Enqueue(5);
    q.Display();
    q.Dequeue();
    q.Enqueue(89);
    q.Dequeue();
    q.Display();

    return 0;
}