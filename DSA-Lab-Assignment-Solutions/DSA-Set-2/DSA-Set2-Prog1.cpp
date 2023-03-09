//DSA Set 2 Program 1 - operations on stack using array
#include<iostream>
using namespace std;
class Stack
{
    public:
    int size;
    int top;
    int *arr;
    Stack(int n)
    {
        size=n;
        arr=new int[n];
        top=-1;
    }
    void push(int x)
    {
        if(top==size-1)
        cout<<"Stack Overflow!"<<endl;
        else
        arr[++top]=x;
    }
    int pop()
    {
        if(top==-1)
        cout<<"Stack Underflow!"<<endl;
        else
        return arr[top--];
        return -1;
    }
    int peek()
    {
        if(top==-1)
        cout<<"Stack Underflow!"<<endl;
        else
        return arr[top];
        return -1;
    }
    bool isEmpty()
    {
        if(top==-1)
        return true;
        else
        return false;
    }
    bool isFull()
    {
        if(top==size-1)
        return true;
        else
        return false;
    }
};
int main()
{
    int ch=7,x=0,y=-1;
    Stack *st;
    do
    {
        cout<<"Enter 1 to create stack, 2 to push item, 3 to pop item, 4 to check if empty, 5 to check if full, 6 to peek, 7 to exit."<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
            cout<<"Enter size of stack : ";
            cin>>y;
            st=new Stack(y);
            cout<<"Created stack of size "<<y<<"."<<endl;
            break;
            case 2:
            cout<<"Enter item to be pushed : ";
            cin>>y;
            st->push(y);
            break;
            case 3:
            y=st->pop();
            if(y!=-1)
            cout<<"Item popped : "<<y<<endl;
            break;
            case 4:
            if(st->isEmpty())
            cout<<"Stack is empty."<<endl;
            else
            cout<<"Stack is not empty."<<endl;
            break;
            case 5:
            if(st->isFull())
            cout<<"Stack is full."<<endl;
            else
            cout<<"Stack is not full."<<endl;
            break;
            case 6:
            y=st->peek();
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