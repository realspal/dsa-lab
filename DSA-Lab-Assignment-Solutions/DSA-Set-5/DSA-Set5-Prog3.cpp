//DSA Set 5 Program 3 - Insertion sort
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
void insertionSort(int arr[],int n)
{
    int i,j,key;
    for(i=1;i<n;i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
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
    insertionSort(arr,n);
    displayArray(arr,n);
    return 0;
}