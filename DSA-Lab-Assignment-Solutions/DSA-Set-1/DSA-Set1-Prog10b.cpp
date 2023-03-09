//DSA Set 1 Program 10b - representing sparse matrix using linked list
#include<iostream>
using namespace std;
class Node
{
    public:
    int row,col;
    double data;
    Node *next;
    Node(int row,int col,double data)
    {
        this->row=row;
        this->col=col;
        this->data=data;
        this->next=NULL;
    }
};
int numRows,numCols;
void insertNode(Node **head,int ri,int ci,double data)
{
    Node *newnode=new Node(ri,ci,data);
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
void displayMatrix(Node **head)
{
    cout<<"\n-- MATRIX REPRESENTATION --\n"<<endl;
    Node *temp=*head;
    for(int i=1;i<=numRows;i++)
    {
        for(int j=1;j<=numCols;j++)
        {
            if(temp==NULL)
            cout<<" 0     ";
            else
            {
                if(temp->row==i && temp->col==j)
                {
                    cout<<temp->data<<"    ";
                    temp=temp->next;
                }
                else
                cout<<" 0     ";
            }
        }
        cout<<endl;
    }
}
void displayList(Node **head)
{
    cout<<"\n-- LINKED LIST REPRESENTATION --\n"<<endl;
    Node *temp=*head;
    cout<<"Row     Col     Data"<<endl;
    cout<<"------------------------"<<endl;
    while(temp!=NULL)
    {
        cout<<(temp->row)<<"       "<<(temp->col)<<"       "<<(temp->data)<<endl;
        temp=temp->next;
    }
    cout<<endl;
}
void takeInput(Node **head)
{
    int n,r,c;
    double v;
    cout<<"Enter number of rows             : ";
    cin>>numRows;
    cout<<"Enter number of columns          : ";
    cin>>numCols;
    cout<<"Enter number of non-zero entries : ";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cout<<"Enter row number, column number, data of entry "<<i<<" : ";
        cin>>ws;
        cin>>r>>c>>v;
        insertNode(head,r,c,v);
    }
}
int main()
{
    Node *head=NULL;
    takeInput(&head);
    displayList(&head);
    displayMatrix(&head);
    return 0;
}