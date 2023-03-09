//DSA Set 4 Program 2a - Depth first traversal
#include<bits/stdc++.h>
using namespace std;
void bfs(vector<vector<int>>& graph,int n)
{
    vector<int>visited(n,0);
    vector<int>ans;
    queue<int> q;
    q.push(0);
    visited[0]=1;
    while(!q.empty())
    {
        int node=q.front();
        ans.push_back(node);
        q.pop();
        for(int item: graph[node])
        {
            if(!visited[item])
            {
                visited[item]=1;
                q.push(item);
            }
        }
    }
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
    bfs(graph,n);
}