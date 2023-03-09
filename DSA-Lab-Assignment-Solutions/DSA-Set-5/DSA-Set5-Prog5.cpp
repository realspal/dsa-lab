//DSA Set 5 Program 5 - Quick sort
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
int partitionArray(int arr[],int start,int end)
{ 
    int pivot=arr[start];
    int count=0;
    for(int i=start+1;i<=end;i++)
        if(arr[i]<=pivot)
            count++;
    int pivotIndex=start+count;
    int temp=arr[start]; 
    arr[start]=arr[pivotIndex];
    arr[pivotIndex]=temp;
    int i=start,j=end;
    while(i<=pivotIndex && j>=pivotIndex)
    {
        while(arr[i]<=pivot)
            i++;
        while(arr[j]>pivot)
            j--;
        if(i<pivotIndex && j>pivotIndex)
        {
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
            j--;
        }
    }
    return pivotIndex;
}
void quickSorting(int arr[],int start,int end)
{
    if(start>=end)
    return;
    int pivotIndex=partitionArray(arr,start,end);
    quickSorting(arr,start,pivotIndex-1);
    quickSorting(arr,pivotIndex+1,end);
}
void quickSort(int arr[],int n)
{
    quickSorting(arr,0,n-1);
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
    quickSort(arr,n);
    displayArray(arr,n);
    return 0;
}