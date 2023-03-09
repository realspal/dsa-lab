//DSA Set 2 Program 8 - checking array of parenthesis using stack
#include<iostream>
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
bool isEmpty()
{
    return top==NULL;
}
bool isWellFormed(string str)
{
    char x;
    for(int i=0;i<str.length();i++)
    {
        char ch=str.at(i);
        if(ch=='('||ch=='['||ch=='{')
        {
            push(ch);
            continue;
        }
        if(isEmpty())
        return false;
        switch(ch)
        {
            case ')':
            x=pop();
            if(x=='{'||x=='[')
            return false;
            break;
            case '}':
            x=pop();
            if(x=='('||x=='[')
            return false;
            break;
            case ']':
            x=pop();
            if(x=='{'||x=='(')
            return false;
            break;
            default:
            break;
        }
    }
    return isEmpty();
}
int main()
{
    string str="";
    cout<<"Enter expression :"<<endl;
    cin>>ws;
    getline(cin,str);
    if(isWellFormed(str))
    cout<<"It is well formed."<<endl;
    else
    cout<<"It is not well formed."<<endl;
    return 0;
}