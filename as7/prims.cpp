#include<bits/stdc++.h>
using namespace std;
int main()
{
    int numNodes=10,numEdges=19;
    map<char,vector<pair<int,char>>> mp;
    vector<pair<int,pair<char,char>>> ori_graph;
    vector<int>visited(numNodes,0);
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

    for(auto x:ori_graph)
    {
        mp[x.second.first].push_back({x.first,x.second.second});
        mp[x.second.second].push_back({x.first,x.second.first});
    }
    priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>> pque;
    pque.push({0,'A'});
    int sum = 0;
    while(pque.size())
    {
        pair<int,char> p=pque.top();
        pque.pop();
        if(!visited[p.second-'A'])
        {
            sum += p.first;
            cout<<"Next node included is:- '"<<p.second<<"'  and Sum of weight of MST till now: "<<sum<<endl;
        }
        visited[p.second-'A'] ++;
        for(auto x:mp[p.second])
        if(!visited[x.second-'A'])
        pque.push({x.first,x.second});
    }
    cout<<"Total sum:"<<sum<<endl;
    return 0;
}