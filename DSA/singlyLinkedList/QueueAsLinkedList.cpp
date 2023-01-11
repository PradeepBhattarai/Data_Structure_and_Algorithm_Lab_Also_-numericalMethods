#include<iostream>
using namespace std;
class Node{
public:
        int data;
        Node* next;
    Node()
    {
        this->data=0;
        this->next=NULL;
    }
    Node(int x)
    {
        this->data=x;
        this->next=NULL;
    }
};
class Queue{
    Node* front,*rear;
public:
    Queue()
    {
        front=NULL;
        rear=NULL;
    }
    //for  Enqueue operation we have to insert node from end
    void Enqueue(int x)
    {
        Node* temp=new Node(x);
        if(front==NULL && rear==NULL)
        {
            front=rear=temp;
            return;
        }
        rear->next=temp;
        rear=temp;
    }
    //for Dequeue we have to delete node from beginning
    void Dequeue()
    {
        if(front==NULL || rear==NULL)
        {
            cout<<"Queue is empty";
            return;
        }
        Node* temp=front;
        front=front->next;
        delete temp;
    }
    //Display the items in the Queue
    void Display()
    {
        Node* temp=front;
        if(front==NULL ||rear==NULL)
        {
            cout<<"Queue is empty"<<endl;
            return;
        }
        while(temp!=NULL)
        {
           
            cout<<temp->data<<"  ";
            temp=temp->next;
        }
        cout<<endl;
    }
    // ~Queue()
    // {
    //     Node* temp=front;
    //     while(temp!=NULL)
    //     {
    //         Node* next=temp->next;
    //         delete temp;
    //         temp=next;
    //     }
    //     delete temp;
    // }
};
int main()
{
    Queue q;
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    q.Enqueue(5);
    q.Enqueue(6);
    q.Display();
    q.Dequeue();
    q.Display();
    return 0;
}