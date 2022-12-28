#include<iostream>
#define MAX 100
using namespace std;
class Dequeue
{
    int arr[MAX];
    int front ;
    int rear;
public:
    Dequeue()
    {
        front=-1;
        rear=-1;
    }
    void InsertFromFront(int x)
    {
        if(front==0)
        {
            cout<<"Cannot insert From Front\n";
            return;
        }
        else if(rear==MAX-1)
        {
            cout<<"Dqueue Overflow"<<endl;
            return;
        }
        else if(front ==-1 && rear==-1)
        {
            front++;
            rear++;
        }
        else
        {
            front--;
        }
        arr[front]=x;
        
    }
    void InsertFromRear(int x)
    {
        if(rear==MAX-1)
        {
            cout<<"Dqueue Overflow"<<endl;
            return;
        }
        else if(front ==-1 && rear==-1)
        {
            front++;
            rear++;
        }
        else
        {
            rear++;
        }
        arr[rear]=x;
    }
    void DeleteFromFront()
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
    void DeleteFromRear()
    {
        if(rear==front==-1)
        {
            cout<<"Underflow"<<endl;
            return;
        }
        else
        {
            rear--;
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
    Dequeue q;
    q.InsertFromRear(2);
    q.InsertFromRear(3);
    q.InsertFromRear(4);
    q.InsertFromRear(5);
    q.Display();
    q.DeleteFromFront();
    q.Display();
    q.InsertFromFront(10);
    q.Display();
    q.DeleteFromRear();
    q.Display();
    return 0;
}