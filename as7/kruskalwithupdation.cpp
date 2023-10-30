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
void mst(vector<pair<int,pair<char,char>>>&ori_graph,vector<pair<int,pair<char,char>>>&ans_graph,int &sum,int numNodes)
{
    sort(ori_graph.begin(),ori_graph.end());
    Ds *mst=new Ds(numNodes);
    
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
}
int main()
{
    vector<pair<int,pair<char,char>>>ori_graph,ans_graph,updated_graph;
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
    int sum=0;
    mst(ori_graph,ans_graph,sum,numNodes);
    cout<<"sum: "<<sum<<endl;
    for(auto x:ans_graph) cout<<x.second.first<<"-"<<x.second.second<<" "<<x.first<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    char a,b;
    int x;
    cout<<"Enter nodes of edge you want to update:";
    cin>>a>>b;
    cout<<"Enter Updated weight of that edge:";
    cin>>x;
    for(int i=0;i<numEdges;i++)
    {
        if(ori_graph[i].second.first==a &&ori_graph[i].second.second==b)ori_graph[i].first=x;
        else if(ori_graph[i].second.first==b &&ori_graph[i].second.second==a)ori_graph[i].first=x;        
    }
    cout<<"Updated MST:"<<endl;
    sum=0;
    mst(ori_graph,updated_graph,sum,numNodes);
    cout<<"sum: "<<sum<<endl;
    for(auto x:updated_graph) cout<<x.second.first<<"-"<<x.second.second<<" "<<x.first<<endl;
    return 0;
}