//DSA Set 2 Program 6 - reversing string using stack (linked list) 
#include<iostream>
#include<string>
using namespace std;
class Node
{
    public:
    char data;
    Node *link;
    Node(char data)
    {
        this->data=data;
        link=NULL;
    }  
};
Node *top=NULL;
void push(char x)
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
char pop()
{
    char x='\0';
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
int main()
{
    string str="";
    cout<<"Enter a string :"<<endl;
    cin>>ws;
    getline(cin,str);
    int len=str.length();
    cout<<"Original string - "<<str<<endl;
    for(int i=0;i<len;i++)
    push(str.at(i));
    str="";
    for(int i=0;i<len;i++)
    str=str+pop();
    cout<<"Reversed string - "<<str<<endl;
    return 0;
}