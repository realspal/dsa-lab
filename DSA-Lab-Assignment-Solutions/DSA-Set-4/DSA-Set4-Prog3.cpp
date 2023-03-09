//DSA Set 4 Program 3 - Topological ordering of a graph
#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>& graph, vector<int>& check, stack<int>& ans, int node)
{
    if(!check[node])
    {
        check[node]=1;
        for(auto item: graph[node])
        dfs(graph,check,ans,item);
        ans.push(node);
    }
}
void dfstopo(vector<vector<int>>& graph, int nodes)
{
    vector<int>check(nodes,0);
    stack<int>ans;
    for(int i=0;i<nodes;i++)
    {
        if(!check[i])
        dfs(graph,check,ans,i);
    }
    while(!ans.empty())
    {
        int temp=ans.top();
        cout<<temp<<" ";
        ans.pop();
    }
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
    }
    dfstopo(graph,n);
}
