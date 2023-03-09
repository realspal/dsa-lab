//DSA Set 5 Program 4 - Merge sort
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
void displayArray(int arr[],int n)
{
    cout<<"The sorted array :"<<endl;
    for(int i=0;i<n;i++)
    cout<<arr[i]<<"  ";
    cout<<endl;
}
void mergeArray(int arr[],int start,int end)
{
    int mid=(start+end)/2;
    int s=mid-start+1,e=end-mid;
    int temp_s[s];
    int temp_e[e];
    for(int i=0;i<s;i++)
    temp_s[i]=arr[start+i];
    for(int j=0;j<e;j++)
    temp_e[j]=arr[mid+1+j];
    int i=0,j=0,k=start;
    while(i<s && j<e)
    {
        if(temp_s[i]<=temp_e[j])
        arr[k++]=temp_s[i++];
        else
        arr[k++]=temp_e[j++];
    }
    while(i<s)
    arr[k++]=temp_s[i++];
    while(j<e)
    arr[k++]=temp_e[j++];
}
void mergeSorting(int arr[],int start,int end)
{
    if(start>=end)
    return;
    else
    {
        int mid=(start+end)/2;
        mergeSorting(arr,start,mid);
        mergeSorting(arr,mid+1,end);
       	mergeArray(arr,start,end);
    }
}
void mergeSort(int arr[],int n)
{
    mergeSorting(arr,0,n-1);
}
int main()
{
    int n=getLength();
    int arr[n];
    getElements(arr,n);
    mergeSort(arr,n);
    displayArray(arr,n);
    return 0;
}