//DSA Set 4 Program 2b - Breadth first traversal
#include<bits/stdc++.h>
using namespace std;
void dfsutil(vector<vector<int>>& graph, vector<int>& visited, vector<int>& ans, int src)
{
    visited[src]=1;
    ans.push_back(src);
    for(auto item: graph[src])
    if(!visited[item])
    dfsutil(graph,visited,ans,item);
}
void dfs(vector<vector<int>>& graph, int n)
{
    vector<int>visited(n,0);
    vector<int>ans;
    dfsutil(graph,visited,ans,0);
    for(int item: ans)
    cout<<item<<" ";
    cout<<endl;
}
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
    dfs(graph,n);
}