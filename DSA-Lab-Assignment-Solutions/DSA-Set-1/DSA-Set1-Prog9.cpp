//DSA Set 1 Program 9 - splitting a linked list
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
int countNodes(Node *head)
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
int inputLL(Node **head)
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
    return n;
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
void splitLL(int n)
{
    b=a;
    Node *temp=NULL;
    while(n)
    {
        if(n==2)
        temp=a;
        a=a->next;
        n-=2;
    }
    temp->next=NULL;
    c=a;
}
int main()
{
    cout<<"Enter data for the linked list :"<<endl;
    int n=inputLL(&a);
    cout<<"Original linked list  :   ";
    printLL(a);
    splitLL(n);
    cout<<"First linked list     :   ";
    printLL(b);
    cout<<"Second linked list    :   ";
    printLL(c);
    return 0;
}