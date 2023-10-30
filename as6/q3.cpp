#include <bits/stdc++.h>
using namespace std;
class Item {
	public:
    int profit, weight;
	Item(int profit, int weight)
	{
		this->profit = profit;
		this->weight = weight;
	}
	Item()
	{}
};
static bool cmp(struct Item a, struct Item b)
{
	double r1 = (double)a.profit / (double)a.weight;
	double r2 = (double)b.profit / (double)b.weight;
	return r1 > r2;
}
double fractionalKnapsack(int W, struct Item arr[], int N)
{
	sort(arr, arr + N, cmp);
	double finalvalue = 0.0;
	for (int i = 0; i < N; i++) {
		if (arr[i].weight <= W) {
			W -= arr[i].weight;
			finalvalue += arr[i].profit;
		}
		else {
			finalvalue
				+= arr[i].profit
				* ((double)W / (double)arr[i].weight);
			break;
		}
	}
	return finalvalue;
}
int main()
{
	int M,n;
    cout<<"Enter M:";
    cin>>M;
    cout<<"Enter n:";
    cin>>n;
    vector<int> weights,profit;
    weights.resize(n);
    profit.resize(n);
    cout<<"Enter Array of Profit:"<<endl;
    for(int i = 0; i < n; i++)cin>>profit[i];
    cout<<"Enter Array of Weight:"<<endl;
    for(int i = 0; i < n; i++)cin>>weights[i];
	Item arr[n];
    for(int i = 0; i < n;i++)
    arr[i]={profit[i], weights[i]};
	cout << fractionalKnapsack(M, arr, n);
	return 0;
}
