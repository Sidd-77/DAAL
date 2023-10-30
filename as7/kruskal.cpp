#include<bits/stdc++.h>
using namespace std;
class Ds
{
    vector<int> rank,parent;
    public:
    Ds(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)parent[i]=i;
    }
    int findUparent(int node)
    {
        if(parent[node]==node)return node;
        return parent[node]=findUparent(parent[node]);
    }
    void unionbyrank(int u,int v)
    {
        int up=findUparent(u);
        int vp=findUparent(v);
        if(rank[up]>rank[vp])parent[vp]=up;
        else if(rank[up]<rank[vp])parent[up]=vp;
        else
        {
            parent[up]=vp;
            rank[vp]++;
        }
    }
};

int main()
{
    vector<pair<int,pair<char,char>>>ori_graph,ans_graph;
    int numNodes=10,numEdges=19;
    ori_graph={{15,{'A','B'}},
            {19,{'A','D'}},
            {10,{'A','C'}},
            {7,{'D','B'}},
            {16,{'C','D'}},
            {17,{'B','E'}},
            {14,{'C','F'}},
            {12,{'D','E'}},
            {6,{'D','F'}},
            {3,{'D','G'}},
            {20,{'E','G'}},
            {9,{'F','G'}},
            {13,{'E','H'}},
            {5,{'F','I'}},
            {11,{'G','J'}},
            {4,{'G','H'}},
            {18,{'I','J'}},
            {2,{'H','J'}},
            {1,{'G','I'}}};
    // cout<<"Enter number of nodes:";
    // cin>>numNodes;
    // cout<<"Enter number of edges:";
    // cin>>numEdges;
    // for(int i=0;i<numEdges;i++)
    // {
    //     char a,b;
    //     int x;
    //     cout<<"Enter nodes that are connected:";
    //     cin>>a>>b;
    //     cout<<"Enter weight of this edge:";
    //     cin>>x;
    //     ori_graph.push_back({x,{a,b}});
    // }
    sort(ori_graph.begin(),ori_graph.end());
    Ds *mst=new Ds(numNodes);
    int sum=0;
    for(int i=0;i<ori_graph.size();i++)
    {
        int u=ori_graph[i].second.first-'A';
        int v=ori_graph[i].second.second-'A';
        if(mst->findUparent(u)!=mst->findUparent(v))
        {
            mst->unionbyrank(u,v);
            sum += ori_graph[i].first;
            ans_graph.push_back(ori_graph[i]);
        }
    }
    cout<<"sum: "<<sum<<endl;
    for(auto x:ans_graph) cout<<x.second.first<<"-"<<x.second.second<<" "<<x.first<<endl;
    return 0;
}