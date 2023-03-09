//DSA Set 4 Program 1a - Representing a graph using adjacency matrix
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,e;
    cin>>n>>e;
    vector<vector<int>> graph(n,vector<int>(n,0));
    for(int i=0;i<e;i++)
    {
        int from,to;
        cin>>from>>to;
        graph[from][to]=1;
        graph[to][from]=1;
    }
    for(int i=0;i<n;i++) 
    {
        for(int j=0;j<n;j++) 
        cout<<graph[i][j]<<" ";
        cout<<endl;
    }
}