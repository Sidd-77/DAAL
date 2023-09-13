#include <bits/stdc++.h>
using namespace std;
int c=1;
void towerOfHanoi(int n,char source,char destination,char extra)
{
	if(n==1)
	{
    	cout<<c<<") move disc 1 from "<<source<<" to "<<destination<<endl;
    	c++;
    	return ;
	}
	towerOfHanoi(n-1,source,extra,destination);
	cout<<c<<") move disc " << n << " from "<<source<<" to "<<destination<<endl;
	c++;
	towerOfHanoi(n-1,extra,destination,source);
}
int main()
{
	int n;
	cin>>n;
	towerOfHanoi(n,'A','C','B');
	return 0;
}
