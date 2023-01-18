#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* prev;
    Node* next;
    Node()
    {
        this->data=0;
        this->prev=NULL;
        this->next=NULL;
    }
    Node(int x)
    {
        this->data=x;
        this->prev=NULL;
        this->next=NULL;
    }

};
class doublyLinkedList
{
    Node* head;
public:
    doublyLinkedList()
    {
        head=NULL;
    }
    void insertAtBeg(int x)
    {
        Node* newNode=new Node(x);
        if(head==NULL)
        {
            head=newNode;
            return;
        }
        head->prev=newNode;
        newNode->next=head;
        head=newNode;
    }
    void insertAtEnd(int x)
    {
        Node* newNode=new Node(x);
        if(head==NULL)
        {
            head=newNode;
            return;
        }
        Node* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        newNode->prev=temp;
        temp->next=newNode;
    }
    void insertAfterSpecNode(int x)
    {
        int element;
        cout<<"After which node you want to insert?:";
        cin>>element;
        if(head==NULL)
        {
            cout<<"List is empty No specific node found:";
            return;
        }
        Node* temp=head;
        while(temp->next!=NULL)
        {
            if(temp->data==element)
            {
                break;
            }
            temp=temp->next;
        }
        Node* newNode=new Node(x);
        newNode->prev=temp;
        temp->next->prev=newNode;
        newNode->next=temp->next;
        temp->next=newNode;
        if(temp==NULL)
        {
            cout<<"Node you entered not found:"<<endl;
            return;
        }

    }
    void insertBeforespc(int x)
    {
        int element;
        cout<<"Before which node you want to insert?:";
        cin>>element;
        if(head==NULL)
        {
            cout<<"List is empty No specific node found:";
            return;
        }
        Node* newNode=new Node(x);
        Node* temp=head;
        if(head->data==element)
        {
            head->prev=newNode;
            newNode->next=head;
            newNode->prev=NULL;
            head=newNode;
            return;
        }
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
            cout<<"Node not found"<<endl;
            return;
        }
        newNode->prev=temp->prev;
        (temp->prev)->next=newNode;
        temp->prev=newNode;
        newNode->next=temp;
    }
    void deleteFromBeg()
    {
        if(head==NULL)
        {
            cout<<"List is empty"<<endl;
            return;
        }
        Node* temp=head;
        head=head->next;
        head->prev=NULL;
        delete temp;
    }
    void deleteFromEnd()
    {
        if(head==NULL)
        {
            cout<<"List is empty"<<endl;
            return;
        }
        Node* temp=head;
        while((temp->next)!=NULL)
        {
            temp=temp->next;
        }
        Node* temp1=temp;
        temp->prev->next=NULL;
        delete temp1;
    }
    void deleteAfterSpc()
    {
        cout<<"Enter after which node you want to delete:";
        int element;
        cin>>element;
        if(head==NULL)
        {
            cout<<"List is empty"<<endl;
            return;
        }
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
            cout<<"Node not found:"<<endl;
            return;
        }
        Node* temp1=temp->next;
        temp->next->next->prev=temp;
        temp->next=temp->next->next;
        delete temp1;
    }
    void deleteBeforeSpec()
    {
      cout<<"Enter before which node you want to delete:";
        int element;
        cin>>element;
        if(head==NULL)
        {
            cout<<"List is empty"<<endl;
            return;
        }
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
            cout<<"Node not found:"<<endl;
            return;
        }
        Node* temp1=temp->prev;
        temp->prev->prev->next=temp->next;
        temp->prev=temp->prev->prev;
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
            cout<<temp->data<<"    ";
            temp=temp->next;
        }
        cout<<endl;
    }
    ~doublyLinkedList()
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
    doublyLinkedList dl;
    dl.insertAtBeg(2);
    dl.insertAtBeg(4);
    dl.insertAtBeg(6);
    dl.insertAtBeg(8);
    dl.display();
    dl.insertAtEnd(10);
    dl.display();
    dl.insertAfterSpecNode(12);
    dl.display();
    dl.insertBeforespc(14);
    dl.display();
    dl.deleteFromBeg();
    dl.display();
    dl.deleteFromEnd();
    dl.display();
    dl.deleteAfterSpc();
    dl.display();
    dl.deleteBeforeSpec();
    dl.display();
    return 0;
}