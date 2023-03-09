//DSA Set 5 Program 2 - Bubble sort
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
    int i,j,temp,sorted=0;
    for(i=0;i<n-1 && sorted==0;i++)
    {
        sorted=1;
        for(j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                sorted=0;
            }
        }
    }
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