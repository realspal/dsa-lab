//DSA Set 2 Program 7 - evaluating postfix expression using stack
#include<iostream>
#include<math.h>
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
bool isEmpty()
{
    return top==NULL;
}
int evaluate(string str)
{
    char x;
    for(int i=0;i<str.length();i++)
    {
        x=str.at(i);
        if(x==' ')
        continue;
        else if(isdigit(x))
        push(x-'0');
        else
        {
            int a=pop();
            int b=pop();
            switch(x)
            {
                case '+': push(b+a); break;
                case '-': push(b-a); break;
                case '*': push(b*a); break;
                case '/': push(b/a); break;
		case '^': push(pow(b,a)); break;
                default: break;
            }
        }
    }
    return pop();
}
int main()
{
    string str="";
    cout<<"Enter expression :"<<endl;
    cin>>ws;
    getline(cin,str);
    cout<<"Postfix evaluation = "<<evaluate(str)<<endl;
    return 0;
}