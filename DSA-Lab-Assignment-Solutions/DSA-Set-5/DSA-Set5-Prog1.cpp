//DSA Set 5 Program 1 - Linear search
#include<iostream>
using namespace std;
int getLength()
{
    int n;
    cout<<"Enter length of the array :"<<endl;
    cin>>n;
    return n;
}
void getElements(int arr[],int n)
{
    cout<<"Enter "<<n<<" elements in the array :"<<endl;
    for(int i=0;i<n;i++)
    cin>>arr[i];
}
int getNumber()
{
    int e;
    cout<<"Enter number to be searched :"<<endl;
    cin>>e;
    return e;
}
void linearSearch(int arr[],int n,int e)
{
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==e)
        {
            if(flag==0)
            {
                cout<<"Success."<<endl;
                flag=1;
            }
            cout<<"Element found at index "<<i<<"."<<endl;
        }
    }
    if(flag==0)
    cout<<"Failure. Element not found."<<endl;
}
int main()
{
    int n=getLength();
    int arr[n];
    getElements(arr,n);
    int e=getNumber();
    linearSearch(arr,n,e);
    return 0;
}