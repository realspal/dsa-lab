//DSA Set 1 Program 11 - splitting a linked list
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
Node *a=NULL;
Node *b=NULL;
Node *c=NULL;
void inputLL(Node **head)
{
    int n,x;
    do
    {
        cout<<"Enter size : ";
        cin>>n;
        if(n%2!=0)
        cout<<"Linked list of odd number size cannot be split into two equal halves."<<endl;
    }
    while(n%2!=0);
    cout<<"Enter "<<n<<" elements : ";
    for(int i=0;i<n;i++)
    {
        cin>>x;
        Node *newnode=new Node(x);
        if(*head==NULL)
        *head=newnode;
        else
        {
            Node *temp=*head;
            while(temp->next!=NULL)
            temp=temp->next;
            temp->next=newnode;
        }
    }
}
void printLL(Node *head)
{
    Node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"  ";
        temp=temp->next;
    }
    cout<<endl;
}
void addNode(Node **head,int x)
{
    Node *newnode=new Node(x);
    if(*head==NULL)
    *head=newnode;
    else
    {
        Node *temp=*head;
        while(temp->next!=NULL)
        temp=temp->next;
        temp->next=newnode;
    }
}
void splitLL()
{
    Node *temp=a;
    while(temp!=NULL)
    {
        int d=temp->data;
        if(d%2==0)
        addNode(&c,d);
        else
        addNode(&b,d);
        temp=temp->next;
    }
}
int main()
{
    cout<<"Enter data for the linked list :"<<endl;
    inputLL(&a);
    cout<<"Original linked list        :   ";
    printLL(a);
    splitLL();
    cout<<"Linked list of odd numbers  :   ";
    printLL(b);
    cout<<"Linked list of even numbers :   ";
    printLL(c);
    return 0;
}