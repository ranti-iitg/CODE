#include<iostream>
#include<cstring>
using namespace std;

long long arr[66][66][2];

long long  dp(int n, int s, int x)
{
	if(n == 1)
	{
		if(s == 0 && x == 1)
			return 1;
		if(s == 0 && x == 0)
			return 2;
		if(s == 1 && x == 1)
			return 1;
		return 0;
	}
	if(n < s)
		return 0;
	if(n == s && x == 0)
		return 0;
	if(arr[n][s][x] != -1)
		return arr[n][s][x];
	if(x)
		arr[n][s][x] =  dp(n-1,s-1,1) + dp(n-1,s,0);
	else
		arr[n][s][x] =  dp(n-1,s,1) + dp(n-1,s,0);
	return arr[n][s][x];
}
main()
{
	memset(arr, -1, sizeof(arr));
	int n,s;
	while(1)
	{
		cin>>n>>s;
		if(n<0 && s<0)
			break;
		cout<<dp(n,s, 1)<<endl;
	}
}
