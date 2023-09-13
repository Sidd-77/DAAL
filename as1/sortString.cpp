#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<string> args={"abc","dogg","bcs","ggod","donkey","keydon","bac","oggd"};
    vector<pair<string,int>> ha;
    for(int i=0;i<args.size();i++){
        ha.push_back({args[i],i});
        sort(ha[i].first.begin(),ha[i].first.end());
    }
    sort(ha.begin(),ha.end());
    for(int i=0;i<ha.size();i++){
        cout<<args[ha[i].second]<<endl;
    }
    return 0;
}