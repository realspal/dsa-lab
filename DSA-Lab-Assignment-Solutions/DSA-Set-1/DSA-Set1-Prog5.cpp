//DSA Set 1 Program 5 - operations on singly connected linked list
#include<iostream>
using namespace std;
class Node 
{
    public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data=data;
        next=NULL;
    }
};
Node *head=NULL;
int countNodes()
{
    Node *temp=head;
    int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}
void display()
{
    cout<<"Linked List :    ";
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"  ";
        temp=temp->next;
    }
    cout<<endl;
}
void insertAtStart()
{
    int data;
    cout<<"Enter data : ";
    cin>>data;
    Node *newNode=new Node(data);
    if(head==NULL)
    head=newNode;
    else
    {
        Node *temp=head;
        head=newNode;
        newNode->next=temp;
    }
    display();
}
void insertAtEnd()
{
    int data;
    cout<<"Enter data : ";
    cin>>data;
    Node *newNode=new Node(data);
    if(head==NULL)
    head=newNode;
    else
    {
        Node *temp=head;
        while(temp->next!=NULL)
        temp=temp->next;
        temp->next=newNode;
    }
    display();
}
void insertAtIndex()
{
    int data,p;
    cout<<"Enter data : ";
    cin>>data;
    cout<<"Enter position : ";
    cin>>p;
    int n=countNodes();
    if(p>n+1 || p<1)
    cout<<"Invalid index."<<endl;
    else
    {
        Node *newNode=new Node(data);
        if(head==NULL)
        head=newNode;
        else
        {
            Node *temp=head;
            if(p==1)
            {
                head=newNode;
                newNode->next=temp;
            }
            else
            {
                for(int i=2;i<p;i++)
                temp=temp->next;
                newNode->next=temp->next;
                temp->next=newNode;
            }
        }
    }
    display();
}
void deleteFromIndex()
{
    int p;
    cout<<"Enter position : ";
    cin>>p;
    int n=countNodes();
    if(p>n || p<1)
    cout<<"Invalid index."<<endl;
    else
    {
        Node *temp=head;
        if(p==1)
        head=temp->next;
        else
        {
            for(int i=2;i<p;i++)
            temp=temp->next;
            temp->next=(temp->next)->next;
        }
    }
    display();
}
void displayReverse()
{
    Node *temp=head;
    Node *temp1=NULL;
    Node *temp2=NULL;
    while(temp!=NULL)
    {
        temp1=temp->next;
        temp->next=temp2;
        temp2=temp;
        temp=temp1;
    }
    head=temp2;
    display();
}
int main()
{
    int ch=7,x=0;
    do
    {
        cout<<"Enter 1 to insert node at beginning, 2 to insert node at end, 3 to insert node at specified position,"<<endl;
        cout<<"      4 to delete node from specified position, 5 to count nodes, 6 to reverse linked list, 7 to exit."<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
            insertAtStart();
            break;
            case 2:
            insertAtEnd();
            break;
            case 3:
            insertAtIndex();
            break;
            case 4:
            deleteFromIndex();
            break;
            case 5:
            x=countNodes();
            cout<<"Number of nodes = "<<x<<endl;
            break;
            case 6:
            displayReverse();
            break;
            default:
            cout<<"Invalid choice.";
        }
    }
    while(ch!=7);
    return 0;
}