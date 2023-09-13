#include<bits/stdc++.h>
using namespace std;

vector<int> findAns(vector<vector<int>> mat, int key){
    int hr = mat.size()-1;
    int lr = 0;
    int hc = mat[0].size()-1;
    int lc = 0;
    int row =-1;
    while(hr>lr){
        int mid = (hr+lr)/2;
        if(key>=mat[mid][0] && key<=mat[mid][hc]){
            row = mid;
            break;
        }
        if(key> mat[mid][hc]){
            lr=mid+1;
        }else if(key < mat[mid][hc]){
            hr=mid;
        }
    }
    cout<<row<<endl;
    while(lc<hc){
        int mid = (lc+hc)/2;
        if(key==mat[row][mid]){
            return {row,mid};
        }
        if(key>mat[row][mid]){
            lc=mid+1;
        }else{
            hc=mid;
        }
    }
    return {-1,-1};
}

int main()
{

    vector<vector<int> > arr = { { 1, 2, 3, 4 },
                                 { 5, 6, 7, 8 },
                                 { 9, 10, 11, 12 } };
    vector<int> ans = findAns(arr, 7 );

    cout << "Element found at index: [";
    for (int i = 0; i < ans.size(); i++) {
        if (i == ans.size() - 1)
            cout << ans[i];
        else
            cout << ans[i] << ", ";
    }
    cout << "]";
}