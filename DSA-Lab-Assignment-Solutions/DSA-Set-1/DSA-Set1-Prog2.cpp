//DSA Set 1 Program 2 - Create structure to store information about students and add, display, search and modify records
#include<iostream>
#include<string>
using namespace std;
struct Student
{
    int roll;
    string name;
    double perc;
};
void add(Student p[10],int n)
{
    Student s;
    cout<<"Enter record to be added."<<endl;
    cout<<"Roll number         : ";
    cin>>s.roll;
    cout<<"Name                : ";
    cin>>ws;
    getline(cin,s.name);
    cout<<"Percentage of marks : ";
    cin>>s.perc;
    p[n]=s;
}
void display(Student p[10],int n)
{
    for(int i=0;i<n;i++)
    cout<<"RECORD "<<(i+1)<<" : "<<"Roll number - "<<p[i].roll<<", Name - "<<p[i].name<<", Percentage of marks - "<<p[i].perc<<endl;
}
void search(Student p[10],int n)
{
    int check_roll;
    string check_name;
    double check_perc;
    cout<<"Enter record to be searched."<<endl;
    cout<<"Roll number         : ";
    cin>>check_roll;
    cout<<"Name                : ";
    cin>>ws;
    getline(cin,check_name);
    cout<<"Percentage of marks : ";
    cin>>check_perc;
    int flag=0;
    for(int i=0;i<n;i++)
    if(p[i].roll==check_roll && p[i].name==check_name && p[i].perc==check_perc)
    {
        cout<<"RECORD FOUND. (Record number = "<<(i+1)<<")"<<endl;
        flag++;
        break;
    }
    if(!flag)
    cout<<"RECORD NOT FOUND."<<endl;
}
void modify(Student p[10],int n)
{
    int num;
    cout<<"Enter record number to be modified : ";
    cin>>num;
    if(num<=0||num>n)
    cout<<"Record number out of range."<<endl;
    else
    {
        cout<<"Enter modified record."<<endl;
        cout<<"Roll number         : ";
        cin>>p[num-1].roll;
        cout<<"Name                : ";
        cin>>ws;
        getline(cin,p[num-1].name);
        cout<<"Percentage of marks : ";
        cin>>p[num-1].perc;
    }
}
int main()
{
    int ch=0,n=0;
    Student arr[10];
    Student *ptr=arr;
    do
    {
        cout<<"ENTER : 1 to add new record"<<endl;
        cout<<"      : 2 to display all records"<<endl;
        cout<<"      : 3 to search a record"<<endl;
        cout<<"      : 4 to modify a record"<<endl;
        cout<<"      : 5 to exit"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
            add(ptr,n);
            n++;
            break;
            case 2:
            display(ptr,n);
            break;
            case 3:
            search(ptr,n);
            break;
            case 4:
            modify(ptr,n);
            break;
            case 5:
            break;
            default:
            cout<<"Invalid choice."<<endl;
        }
    }
    while(ch!=5);
    return 0;
}