#include<iostream>
using namespace std;
class Node
{
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
class linkedList
{
    Node* head;
public:
    linkedList()
    {
        head=NULL;
    }
    void insertAtbeg(int x)
    {
        Node* newNode=new Node(x);
        if(head==NULL)
        {
            head=newNode;
            return;
        }
        newNode->next=head;
        head=newNode;
    }
    void insertAtend(int x)
    {
        Node* newNode=new Node(x);
        if(head==NULL)
        {
            head=newNode;
            return;
        }
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
    void insertAfterspc(int x)
    {
        int element;
        cout<<"Enter after which element you want to insert?:";
        cin>>element;
        Node* newNode=new Node(x);
        Node* temp=head;
        while(temp->next!=NULL)
        {
            if(temp->data==element)
            {
                break;
            }
            temp=temp->next;
        }
        newNode->next=(temp->next);
        temp->next=newNode;
        if(temp==NULL)
        {
            cout<<"Specific Node not found";
            return;
        }
    }
    void insertBeforespc(int x)
    {
        int element;
        cout<<"Enter before which element you want to insert?:";
        cin>>element;
        Node* newNode=new Node(x);
        Node* temp=head;
        while((temp->next)!=NULL)
        {
            if((temp->next)->data==element)
            {
                break;
            }
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
        if(temp==NULL)
        {
            cout<<"Specific Node not found";
            return;
        }
    }
    void deleteFromBeg()
    {
        Node* temp=head;
        if(head==NULL)
        {
            cout<<"List is empty"<<endl;
            return;
        }
        head=head->next;
        delete temp;
    }
    void deleteFromEnd()
    {
        Node* temp=head;
        if(head==NULL)
        {
            cout<<"List is empty"<<endl;
            return;
        }
        while((temp->next)->next!=NULL)
        {
            temp=temp->next;
        }
        Node* temp1=temp->next;
        temp->next=NULL;
        delete temp1;
    }
    void deleteAfterSpc()
    {
        if(head==NULL)
        {
            cout<<"List is empty:"<<endl;
            return;
        }
        cout<<"After which element you want to delete the node:";
        int element;
        cin>>element;

        Node* temp=head;
        while(temp->next!=NULL)
        {
            if(temp->data==element)
            {
                break;
            }
            temp=temp->next;
        }
        if(temp==NULL)
        {
            cout<<"Specific node Not found"<<endl;
            return;
        }
        Node* temp1=temp->next;
        temp->next=temp1->next;
        delete temp1;
    }
    void display()
    {
        if(head==NULL)
        {
            cout<<"List is empty"<<endl;
            return;
        }
        Node* temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"  ";
            temp=temp->next;
        }
        cout<<endl;
    }
    ~linkedList()
    {
        Node* temp=head;
        while(temp!=NULL)
        {
            Node* next=temp->next;
            delete temp;
            temp=next;
        }
    }
};
int main()
{
    linkedList l1;
    l1.insertAtbeg(2);
    l1.insertAtbeg(4);
    l1.insertAtend(6);
    l1.insertAtend(8);
    l1.display();
    l1.insertAfterspc(10);
    l1.display();
    l1.insertBeforespc(12);
    l1.display();
    l1.deleteFromBeg();
    l1.display();
    l1.deleteFromEnd();
    l1.display();
    l1.deleteAfterSpc();
    l1.display();
    return 0;
}