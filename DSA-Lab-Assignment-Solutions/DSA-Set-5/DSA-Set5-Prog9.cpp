//DSA Set 5 Program 9 - Sorting odd indices in ascending order and even indices in descending order
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
void bubbleSort(int arr[],int n)
{
    int i,j,k,n2,temp,sorted=0;
    int *even,*odd;
    odd=new int[n/2];
    if(n%2==0)
    n2=n/2;
    else
    n2=n/2+1;
    even=new int[n2];
    for(i=0,k=0;i<n;i+=2,k++)
    even[k]=arr[i];
    for(i=1,k=0;i<n;i+=2,k++)
    odd[k]=arr[i];
    for(i=0;i<n2-1 && sorted==0;i++)
    {
        sorted=1;
        for(j=0;j<n2-1-i;j++)
        {
            if(even[j]<even[j+1])
            {
                temp=even[j];
                even[j]=even[j+1];
                even[j+1]=temp;
                sorted=0;
            }
        }
    }
    sorted=0;
    for(i=0;i<n/2-1 && sorted==0;i++)
    {
        sorted=1;
        for(j=0;j<n/2-1-i;j++)
        {
            if(odd[j]>odd[j+1])
            {
                temp=odd[j];
                odd[j]=odd[j+1];
                odd[j+1]=temp;
                sorted=0;
            }
        }
    }
    for(i=0;i<n;i++)
    arr[i]=(i%2==0)?even[i/2]:odd[i/2];
}
void displayArray(int arr[],int n)
{
    cout<<"The sorted array :"<<endl;
    for(int i=0;i<n;i++)
    cout<<arr[i]<<"  ";
}
int main()
{
    int n=getLength();
    int arr[n];
    getElements(arr,n);
    bubbleSort(arr,n);
    displayArray(arr,n);
    return 0;
}