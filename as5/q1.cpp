#include<bits/stdc++.h>
using namespace std;

void multiply(vector<vector<int>>A, vector<vector<int>> B){
    vector<vector<int> > C = { { 0, 0, 0, 0 },
                               { 0, 0, 0, 0 },
                               { 0, 0, 0, 0 },
                               { 0, 0, 0, 0 }};

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			C[i][j] = 0;
			for (int k = 0; k < 4; k++)
			{
				C[i][j] += A[i][k]*B[k][j];
			}
		}
	}

    for (int i = 0; i <= 3; i++) {
        for (int j = 0; j <= 3; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    vector<vector<int> > matrix_A = { { 1, 8, 1, 1 },
                                      { 2, 2, 0, 2 },
                                      { 3, 3, 3, 3 },
                                      { 2, 2, 2, 2 } };

    vector<vector<int> > matrix_B = { { 1, 1, 1, 1 },
                                      { 8, 2, 2, 2 },
                                      { 3, 3, 3, 3 },
                                      { 2, 2, 2, 2 } };

    multiply(matrix_A, matrix_B);

}
