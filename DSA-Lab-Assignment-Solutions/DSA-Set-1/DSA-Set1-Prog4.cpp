//DSA Set 1 Program 4 - create a linked list of 10 nodes
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
Node *temp=NULL;
void insertAtEnd(int data)
{
    Node *newNode=new Node(data);
    if(head==NULL)
    {
        head=newNode;
        temp=head;
    }
    else
    {
        temp->next=newNode;
        temp=temp->next;
    }
}
void traversal()
{
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"  ";
        temp=temp->next;
    }
}
int main()
{
    int n;
    cout<<"Enter 10 values :"<<endl;
    for(int i=0;i<10;i++)
    {
        cin>>n;
        insertAtEnd(n);
    }
    cout<<"Linked list :  ";
    traversal();
    return 0;
}