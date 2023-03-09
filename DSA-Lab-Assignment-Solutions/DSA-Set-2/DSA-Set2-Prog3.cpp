//DSA Set 2 Program 3 - operations on queue using array
#include<iostream>
using namespace std;
class Queue 
{
    int size,front,rear,capacity;
    int *arr;
    public:
    Queue(int s)
    {
        arr=new int[s];
        capacity=s;
        front=-1;
        rear=-1;
        size=0;
    }
    ~Queue()
    {
        delete[] arr;
    }
    void enqueue(int num)
    {
        if(isFull())
        cout<<"Queue overflow!"<<endl;
        else
        {
            rear++;
            arr[rear]=num;
            size++;
            if(size==1)
            front=0;
        }
    }
    int dequeue()
    {
        if(isEmpty())
        cout<<"Queue underflow!"<<endl;
        else
        {
            int num=arr[front];
            for(int i=front;i<rear;i++)
            arr[i]=arr[i+1];
            rear--;
            size--;
            if(size==0)
            front=-1;
            return num;
        }
        return -1;
    }
    bool isEmpty()
    {
        return size==0;
    }
    bool isFull()
    {
        return size==capacity;
    }
    int getSize()
    {
        return size;
    }
    void check()
    {
        if(isFull())
        cout<<"Queue overflow!"<<endl;
        else if(isEmpty())
        cout<<"Queue underflow!"<<endl;
        else
        cout<<"Neither overflow nor underflow."<<endl;
    }
    void clear()
    {
        front=-1;
        rear=-1;
        size=0;
    }
};
int main()
{
    int ch=7,x=0,y=-1;
    Queue *q;
    do
    {
        cout<<"Enter 1 to create queue, 2 to enqueue item, 3 to dequeue item, 4 to count items, 5 to check overflow and underflow, 6 to clear queue, 7 to exit."<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
            cout<<"Enter capacity of queue : ";
            cin>>y;
            q=new Queue(y);
            cout<<"Created queue of capacity "<<y<<"."<<endl;
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