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
class Stack{
    Node* top;
public:
    Stack()
    {
        top=NULL;
    }
    //for push operation we have to insert node from beginning
    void Push(int x)
    {
        Node* temp=new Node(x);
        if(top==NULL)
        {
            top=temp;
            return;
        }
        temp->next=top;
        top=temp;

    }
    //for pop we have to delete node from beginning
    void Pop()
    {
        if(top==NULL)
        {
            cout<<"Stack is empty";
            return;
        }
        Node* temp=top;
        top=top->next;
        delete temp;
    }
    //Return the top element
    void peek()
    {
        cout<<top->data;
        return;
    }
    //Display the items in the stack
    void Display()
    {
        Node* temp=top;
        if(top==NULL)
        {
            cout<<"Stack is empty"<<endl;
            return;
        }
        while(temp!=NULL)
        {
           
            cout<<temp->data<<"  ";
            temp=temp->next;
        }
        cout<<endl;
    }
    ~Stack()
    {
        Node* temp=top;
        while(temp!=NULL)
        {
            Node* next=temp->next;
            delete temp;
            temp=next;
        }
        delete temp;
    }
};
int main()
{
    Stack st;
    st.Push(2);
    st.Push(3);
    st.Push(4);
    st.Push(5);
    st.Push(6);
    st.Display();
    st.Pop();
    st.Display();
    st.peek();

    return 0;
}