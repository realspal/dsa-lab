//DSA Set 1 Program 8 - merging two sorted linked lists
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
void inputLL(Node **head)
{
    int n,x;
    cout<<"Enter size : ";
    cin>>n;
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
void fillLL(Node **head)
{
    int n=countNodes(a)+countNodes(b);
    for(int i=0;i<n;i++)
    {
        Node *newnode=new Node(0);
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
void mergeLL(Node **head1, Node **head2, Node **head3)
{
    Node *h1=*head1;
    Node *h2=*head2;
    Node *h3=*head3;
    int n1=countNodes(h1);
    int n2=countNodes(h2);
    int i=0,j=0,k=0;
    while(i<n1 && j<n2)
    {
        if((h1->data)<(h2->data))
        {
            h3->data=h1->data;
            h3=h3->next;
            k++;
            h1=h1->next;
            i++;
        }
        else
        {
            h3->data=h2->data;
            h3=h3->next;
            k++;
            h2=h2->next;
            j++;
        }
    }
    while(i<n1)
    {
        h3->data=h1->data;
        h3=h3->next;
        k++;
        h1=h1->next;
        i++;
    }
    while(j<n2)
    {
        h3->data=h2->data;
        h3=h3->next;
        k++;
        h2=h2->next;
        j++; 
    }
}
int main()
{
    cout<<"Enter data for first linked list :"<<endl;
    inputLL(&a);
    cout<<"Enter data for second linked list :"<<endl;
    inputLL(&b);
    fillLL(&c);
    mergeLL(&a,&b,&c);
    cout<<"First linked list  :   ";
    printLL(a);
    cout<<"Second linked list :   ";
    printLL(b);
    cout<<"Merged linked list :   ";
    printLL(c);
    return 0;
}