#include <iostream>
using namespace std;

int findduplicate(int a[], int n){

    int i = 0, j = 0;
    while (i < n) {
        if (a[i] == a[++j])
            return a[j];
        if (j == n - 1) {
            i++;
            j = i;
        }
    }
    return -1;
}

int main(){

    int arr[] = { 1, 2, 4, 3, 4, 5, 6, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findduplicate(arr, n) << endl;
    return 0;
}