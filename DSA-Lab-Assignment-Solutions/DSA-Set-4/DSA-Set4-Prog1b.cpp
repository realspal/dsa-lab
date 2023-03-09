//DSA Set 4 Program 1b - Representing a graph using adjacency list
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,e;
    cin>>n>>e;
    vector<vector<int>> graph(n);
    for(int i=0;i<e;i++)
    {
        int from,to;
        cin>>from>>to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    for(int i=0;i<n;i++)
    {
        cout<<i<<"-- ";
        for(int item: graph[i])
        cout<<item<<" "; 
        cout<<endl;
    }
}