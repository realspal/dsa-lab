//DSA Set 2 Program 4a - implementing stack using linked list 
#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *link;
    Node(int data)
    {
        this->data=data;
        link=NULL;
    }  
};
Node *top=NULL;
void push(int x)
{
    Node *temp=new Node(x);
    if(temp==NULL)
    cout<<"Stack Overflow!"<<endl;
    else
    {
        temp->link=top;
        top=temp;
    }
}
int pop()
{
    int x=-1;
    if(top==NULL)
    cout<<"Stack Underflow!"<<endl;
    else
    {
        x=top->data;
        Node *temp=top;
        top=top->link;
        temp->link=NULL;
        free(temp);
    }
    return x;
}
int peek()
{
    int x=-1;
    if(top==NULL)
    cout<<"Stack Underflow!"<<endl;
    else
    x=top->data;
    return x;
}
bool isEmpty()
{
    return top==NULL;
}
void display()
{
    if(top==NULL)
    cout<<"Stack Underflow!"<<endl;
    else
    {
        Node *temp=top;
        while(temp->link!=NULL)
        {
            cout<<temp->data<<" -> ";
            temp=temp->link;
        }
        cout<<temp->data<<endl;
    }
}
int size()
{
    if(top==NULL)
    return 0;
    else
    {
        int s=0;
        Node *temp=top;
        while(temp!=NULL)
        {
            s++;
            temp=temp->link;
        }
        return s;
    }
}
int main()
{
    int ch=6,x=0,y=-1;
    do
    {
        cout<<"Enter 1 to push item, 2 to pop item, 3 to check if empty, 4 to display stack, 5 to display size, 6 to peek, 7 to exit."<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
            cout<<"Enter item to be pushed : ";
            cin>>y;
            push(y);
            break;
            case 2:
            y=pop();
            if(y!=-1)
            cout<<"Item popped : "<<y<<endl;
            break;
            case 3:
            if(isEmpty())
            cout<<"Stack is empty."<<endl;
            else
            cout<<"Stack is not empty."<<endl;
            break;
            case 4:
            display();
            break;
            case 5:
            cout<<"Size : "<<size()<<endl;
            break;
            case 6:
            y=peek();
            if(y!=-1)
            cout<<"Item at top : "<<y<<endl;
            break;
            case 7:
            break;
            default:
            cout<<"Invalid choice."<<endl;
        }
    }
    while(ch!=7);
    return 0;
}