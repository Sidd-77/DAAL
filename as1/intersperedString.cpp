#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<string> test = {"at","","","ball","","","car","","","dad","",""};
    string toFind = "ball";
    int l=0;
    int h=test.size()-1;
    while(l<=h){
        while(test[l]=="")l++;
        while(test[h]=="")h--;
        int mid = (l+h)/2;
        while(test[mid]=="" && l>mid)mid--;
        if(test[l]==toFind){
            cout<<l<<endl;
            break;
        }
        if(test[h]==toFind){
            cout<<h<<endl;
            break;
        }
        if(test[mid]==toFind){
            cout<<mid<<endl;
            break;
        }
        if(test[mid].compare(toFind)>0){
            l=mid+1;
            continue;
        }else{
            h=mid-1;
            continue;
        }

    }
    return 0;

}