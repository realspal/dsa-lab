//DSA Set 2 Program 4b - implementing queue using linked list 
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
class Queue 
{
    Node *front;
    Node *rear;
    int size;
    public:
    Queue()
    {
        front=NULL;
        rear=NULL;
        size=0;
    }
    ~Queue()
    {
        clear();
    }
    void enqueue(int num)
    {
        Node *newnode=new Node(num);
        if(front==NULL)
        {
            front=newnode;
            rear=newnode;
        }
        else
        {
            rear->link=newnode;
            rear=newnode;
        }
        size++;
    }
    int dequeue()
    {
        if(isEmpty())
        cout<<"Queue underflow!"<<endl;
        else
        {
            int num=front->data;
            Node *temp=front->link;
            delete front;
            front=temp;
            size--;
            return num;
        }
        return -1;
    }
    bool isEmpty()
    {
        return size==0;
    }
    int getSize()
    {
        return size;
    }
    void check()
    {
        if(isEmpty())
        cout<<"Queue underflow!"<<endl;
        else
        cout<<"Not underflow."<<endl;
    }
    void clear()
    {
        int x;
        while(!isEmpty())
        x=dequeue();
    }
};
int main()
{
    int ch=7,x=0,y=-1;
    Queue *q;
    do
    {
        cout<<"Enter 1 to create queue, 2 to enqueue item, 3 to dequeue item, 4 to count items, 5 to check underflow, 6 to clear queue, 7 to exit."<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
            q=new Queue();
            cout<<"Created queue."<<endl;
            break;
            case 2:
            cout<<"Enter item to be enqueued : ";
            cin>>y;
            q->enqueue(y);
            break;
            case 3:
            y=q->dequeue();
            if(y!=-1)
            cout<<"Item dequeued : "<<y<<endl;
            break;
            case 4:
            cout<<"Number of items = "<<(q->getSize())<<endl;
            break;
            case 5:
            q->check();
            break;
            case 6:
            q->clear();
            cout<<"Queue cleared."<<endl;
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