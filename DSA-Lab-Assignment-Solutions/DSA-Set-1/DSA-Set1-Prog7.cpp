//DSA Set 1 Program 7 - adding two polynomials using linked list
#include<iostream>
#include<string>
using namespace std;
class Polynode
{
    public:
    double coeff;
    int expon;
    Polynode *next;
    Polynode(double coeff,int expon)
    {
        this->coeff=coeff;
        this->expon=expon;
        next=NULL;
    }
};
Polynode *head1=NULL;
Polynode *head2=NULL;
Polynode *head3=NULL;
void insertPolynode(Polynode **head,double c,int e)
{
    Polynode *newpolynode=new Polynode(c,e);
    if(*head==NULL)
    *head=newpolynode;
    else
    {
        Polynode *temp=*head;
        while(temp->next!=NULL)
        temp=temp->next;
        temp->next=newpolynode;
    }
}
void inputPolynomial(Polynode **head)
{
    string str="",num="";
    double c=0.0;
    int e=0;
    char ch;
    cin>>ws;
    getline(cin,str);
    str=str+"+";
    for(int i=0;i<str.length();i++)
    {
        ch=str.at(i);
        if(ch=='x')
        {
            c=stod(num);
            num="";
        }
        else if(ch=='+')
        {
            e=stoi(num);
            num="";
            insertPolynode(head,c,e);
        }
        else if(ch!='^' && ch!=' ')
        {
            num=num+ch;
        }
    }
}
void addPolynomials()
{
    Polynode *temp1=head1;
    Polynode *temp2=head2;
    Polynode *temp3=NULL;
    Polynode *newpolynode=NULL;
    while(temp1!=NULL && temp2!=NULL)
    {
        newpolynode=new Polynode(0.0,0);
        if(temp3==NULL)
        {
            temp3=newpolynode;
            head3=temp3;
        }
        else
        {
            temp3->next=newpolynode;
            temp3=temp3->next;
        }
        if((temp1->expon)>(temp2->expon))
        {
            temp3->expon=temp1->expon;
            temp3->coeff=temp1->coeff;
            temp1=temp1->next;
        }
        else if((temp1->expon)<(temp2->expon))
        {
            temp3->expon=temp2->expon;
            temp3->coeff=temp2->coeff;
            temp2=temp2->next;
        }
        else
        {
            temp3->expon=temp1->expon;
            temp3->coeff=(temp1->coeff)+(temp2->coeff);
            temp1=temp1->next;
            temp2=temp2->next;
        }
    }
    while(temp1!=NULL || temp2!=NULL)
    {
        newpolynode=new Polynode(0.0,0);
        if(temp3==NULL)
        temp3=newpolynode;
        else
        {
            temp3->next=newpolynode;
            temp3=temp3->next;
        }
        if(temp1!=NULL)
        {
            temp3->expon=temp1->expon;
            temp3->coeff=temp1->coeff;
            temp1=temp1->next;
        }
        if(temp2!=NULL)
        {
            temp3->expon=temp2->expon;
            temp3->coeff=temp2->coeff;
            temp2=temp2->next;
        }
    }
}
void displayPolynomial(Polynode *head)
{
    Polynode *temp=head;
    while(temp!=NULL)
    {
        if((temp->coeff)>0)
        {
            if(temp!=head)
            cout<<" + ";
            cout<<temp->coeff<<"x^"<<temp->expon;
        }
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    cout<<"Enter first polynomial  :  ";
    inputPolynomial(&head1);
    cout<<"Enter second polynomial :  ";
    inputPolynomial(&head2);
    addPolynomials();
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<"    First polynomial    :  ";
    displayPolynomial(head1);
    cout<<"(+) Second polynomial   :  ";
    displayPolynomial(head2);
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<"(=) Third polynomial    :  ";
    displayPolynomial(head3);
    return 0;
}