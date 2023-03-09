//DSA Set 2 Program 2 - reversing string using stack
#include<iostream>
#include<string>
using namespace std;
class Stack
{
    public:
    int size;
    int top;
    char *arr;
    Stack(int n)
    {
        size=n;
        arr=new char[n];
        top=-1;
    }
    void push(char x)
    {
        if(top==size-1)
        cout<<"Stack Overflow!"<<endl;
        else
        arr[++top]=x;
    }
    char pop()
    {
        if(top==-1)
        cout<<"Stack Underflow!"<<endl;
        else
        return arr[top--];
        return -1;
    }
};
int main()
{
    string str="";
    cout<<"Enter a string :"<<endl;
    cin>>ws;
    getline(cin,str);
    int len=str.length();
    Stack *st=new Stack(len);
    cout<<"Original string - "<<str<<endl;
    for(int i=0;i<len;i++)
    st->push(str.at(i));
    str="";
    for(int i=0;i<len;i++)
    str=str+st->pop();
    cout<<"Reversed string - "<<str<<endl;
    return 0;
}