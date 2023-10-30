#include<bits/stdc++.h>
using namespace std;
class Job {
    public:
	string id;
	int dead;
	int profit;
};
class DisjointSet
{
    public:
	int *parent;
	DisjointSet(int n)
	{
		parent = new int[n+1];
		for (int i = 0; i <= n; i++)
			parent[i] = i;
	}
    int find(int s)
	{
		if (s == parent[s])
			return s;
		return parent[s] = find(parent[s]);
	}
    void merge(int u, int v)
	{
		parent[v] = u;
	}
};
bool cmp(Job a, Job b)
{
	return (a.profit > b.profit);
}
int findMaxDeadline(struct Job arr[], int n)
{
	int ans = INT_MIN;
	for (int i = 0; i < n; i++)
		ans = max(ans, arr[i].dead);
	return ans;
}

void printJobScheduling(Job arr[], int n)
{
	sort(arr, arr + n, cmp);
	int maxDeadline = findMaxDeadline(arr, n);
	DisjointSet ds(maxDeadline);
	for (int i = 0; i < n; i++)
	{
		int availableSlot = ds.find(arr[i].dead);

		if (availableSlot > 0)
		{
			ds.merge(ds.find(availableSlot - 1), 
							availableSlot);

			cout << arr[i].id << " ";
		}
	}
}
int main()
{
	vector<int> profit,deadline;
    vector<string> ids;
    int n;
    cout<<"Enter Number of Jobs:";
    cin>>n;
    profit.resize(n);
    deadline.resize(n);
    ids.resize(n);
    cout<<"Enter array Job IDs:"<<endl;
    for(int i=0; i<n; i++)cin>>ids[i];
    cout<<"Enter Array of Profit:"<<endl;
    for(int i = 0; i < n; i++)cin>>profit[i];
    cout<<"Enter Array of Deadline:"<<endl;
    for(int i = 0; i < n; i++)cin>>deadline[i];

    Job arr[n];
    for(int i=0;i<n;i++)
    {
        arr[i]={ids[i],deadline[i],profit[i]};
    }
	cout << "Following jobs need to be  executed for maximum profit:"<<endl;
	printJobScheduling(arr, n);
	return 0;
}
