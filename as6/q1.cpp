#include <bits/stdc++.h>
using namespace std;
class Job {
    public:
	string id;
	int dead;
	int profit;
};
struct jobProfit {
	bool operator()(Job const& a, Job const& b)
	{
		return (a.profit < b.profit);
	}
};
void printJobScheduling(Job arr[], int n)
{
	vector<Job> result;
	sort(arr, arr + n,
		[](Job a, Job b) { return a.dead < b.dead; });
	priority_queue<Job, vector<Job>, jobProfit> pq;

	for (int i = n - 1; i >= 0; i--) {
		int slot_available;
		if (i == 0) {
			slot_available = arr[i].dead;
		}
		else {
			slot_available = arr[i].dead - arr[i - 1].dead;
		}
		pq.push(arr[i]);
		while (slot_available > 0 && pq.size() > 0) {
			Job job = pq.top();
			pq.pop();
			slot_available--;
			result.push_back(job);
		}
	}
	sort(result.begin(), result.end(),
		[&](Job a, Job b) { return a.dead < b.dead; });
	for (int i = 0; i < result.size(); i++)
		cout << result[i].id << ' ';
	cout << endl;
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
    cout << "Following is maximum profit sequence of jobs:"<<endl;
	printJobScheduling(arr, n);
	return 0;
}
