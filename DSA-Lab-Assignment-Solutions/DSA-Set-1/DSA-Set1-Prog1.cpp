//DSA Set 1 Program 1 - Read array elements using pointers and print with addresses
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter number of elements : ";
    cin>>n;
    int arr[n];
    int *ptr=arr;
    cout<<"Enter "<<n<<" elements in the array :"<<endl;
    for(int i=0;i<n;i++)
    cin>>*(ptr+i);
    for(int i=0;i<n;i++)
    cout<<"Array element *(ptr+"<<i<<") = "<<*(ptr+i)<<" and its address (ptr+"<<i<<") = "<<(ptr+i)<<endl;
    return 0;
}