#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> args = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
    int target = 16;
    int pivot;
    for(int i=0; i<args.size()-1; i++){
        if(args[i]>args[i+1]) pivot = i;
    }
    //cout<<pivot<<endl;
    int l1,r1;

    if(target>args[0] && target<=args[pivot]){
        l1=0;
        r1=pivot;
    }else{
        l1=pivot+1;
        r1=args.size()-1;
    }

    while(l1<=r1){
        int mid = l1+(r1-l1)/2;
        if(target==args[mid]){
            cout<<mid;
            return 0;
        }else if(target<args[mid]){
            r1=mid-1;
        }else{
            l1=mid+1;
        }
    }
    return 0;
}