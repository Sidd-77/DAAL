#include<bits/stdc++.h>
using namespace std;

//Time Complexity == O(n)
//Space Complexity == O(1)

int main(){
    int A[10]={1,4,6,7,9};
    int B[5]={2,3,5,8,11};
    int n=5;
    int m=5;
    int temp=INT_MAX;

    int lasInd = 9;
    int i=n-1;
    int j=m-1;
    while(j>=0){
        if(i>=0 && A[i]>=B[j]){
            A[lasInd]=A[i];
            i--;
        }else{
            A[lasInd]=B[j];
            j--;
        }
        lasInd--;
    }

    for(int k=0;k<10;k++){
        cout<<A[k]<<" ";
    }

    return 0;
}



