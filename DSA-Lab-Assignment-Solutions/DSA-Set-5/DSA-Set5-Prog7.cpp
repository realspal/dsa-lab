//DSA Set 5 Program 7 - Binary search
#include<iostream>
using namespace std;
int getLength()
{
    int n;
    cout<<"Enter length of the sorted array :"<<endl;
    cin>>n;
    return n;
}
void getElements(int arr[],int n)
{
    cout<<"Enter "<<n<<" elements in ascending order :"<<endl;
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
void binarySearch(int arr[],int n,int e)
{
    int start=0,end=n-1,mid,found=0;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(e==arr[mid])
        {
            found=1;
            break;
        }
        else if(e<arr[mid])
        end=mid-1;
        else
        start=mid+1;
    }
    if(found==0)
    cout<<"Failure. Element not found."<<endl;
    else
    cout<<"Success. Element found at index "<<mid<<"."<<endl;
}
int main()
{
    int n=getLength();
    int arr[n];
    getElements(arr,n);
    int e=getNumber();
    binarySearch(arr,n,e);
    return 0;
}