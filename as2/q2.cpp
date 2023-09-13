
#include <bits/stdc++.h>
using namespace std;

void findWinner(vector<int>& votes){
	unordered_map<int, int> mapObj;
	for (auto& str : votes) {
		mapObj[str]++;
	}

	int maxValueInMap = 0;
	int winner;
	for (auto& entry : mapObj) {
		int key = entry.first;
		int val = entry.second;
		if (val > maxValueInMap) {
			maxValueInMap = val;
			winner = key;
		}
		else if (val == maxValueInMap && winner > key)
			winner = key;
	}
	cout << winner << endl;
}


int main()
{
	vector<int> votes = { 23,44,34,23,23,44,23,34 };

	findWinner(votes);
	return 0;
}
