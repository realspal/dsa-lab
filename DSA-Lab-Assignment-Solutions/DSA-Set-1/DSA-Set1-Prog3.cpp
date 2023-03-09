//DSA Set 1 Program 3 - create array of 15 data, insert element after 6th data and delete element after 6th data
#include<iostream>
using namespace std;
int main()
{
    int n,temp;
    int *arr=new int[15];
    int *ptr=arr;
    cout<<"Enter 15 elements in the array :"<<endl;
    for(int i=0;i<15;i++)
    cin>>*(ptr+i);
    cout<<"Original array                                        :  ";
    for(int i=0;i<15;i++)
    cout<<*(ptr+i)<<"  ";
    cout<<endl;
    cout<<"Enter element to be inserted after 6th data           :  ";
    cin>>n;
    temp=*(ptr+14);
    for(int i=14;i>6;i--)
    *(ptr+i)=*(ptr+i-1);
    *(ptr+6)=n;
    cout<<"Modified array after inserting element after 6th data :  ";
    for(int i=0;i<15;i++)
    cout<<*(ptr+i)<<"  ";
    cout<<endl;
    for(int i=6;i<14;i++)
    *(ptr+i)=*(ptr+i+1);
    *(ptr+14)=temp;
    cout<<"Modified array after deleting element after 6th data  :  ";
    for(int i=0;i<15;i++)
    cout<<*(ptr+i)<<"  ";
    return 0;
}
