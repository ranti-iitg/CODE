#include <iostream>

using namespace std;

#define MOD 1000000007
typedef long long int ll;

ll dp[100001][10];

ll mod(ll a, ll b)
{
	return (((a % 1000000007) + (b % 1000000007)) % 1000000007);
}

int t, n;

void dynamic()
{
	for (int j = 0; j < 10; j++)
		dp[1][j] = 1;

	for (int i = 2; i <= 100000; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) dp[i][j] = dp[i-1][7]%MOD;
			if (j == 1) dp[i][j] = (dp[i-1][2]+ dp[i-1][4])%MOD;
			if (j == 2) dp[i][j] = ((dp[i-1][1]+ dp[i-1][3])%MOD+ dp[i-1][5])%MOD;
			if (j == 3) dp[i][j] = (dp[i-1][2]+ dp[i-1][6])%MOD;
			if (j == 4) dp[i][j] = ((dp[i-1][1]+ dp[i-1][5])%MOD+ dp[i-1][7])%MOD;
			if (j == 5) dp[i][j] = ((dp[i-1][2]+ dp[i-1][4])%MOD+ (dp[i-1][6]+ dp[i-1][8])%MOD)%MOD;
			if (j == 6) dp[i][j] = ((dp[i-1][3]+ dp[i-1][5])%MOD+ dp[i-1][9])%MOD;
			if (j == 7) dp[i][j] = ((dp[i-1][4]+ dp[i-1][8])%MOD+ dp[i-1][0])%MOD;
			if (j == 8) dp[i][j] = ((dp[i-1][5]+ dp[i-1][7])%MOD+ dp[i-1][9])%MOD;
			if (j == 9) dp[i][j] = (dp[i-1][6]+ dp[i-1][8])%MOD;
		}
	}
}

int main()
{
	dynamic();

	cin >> t;

	while (t--) {
		cin >> n;

		ll sum = 0;

		for (int i = 0; i < 10; i++) {
			sum = (sum + dp[n][i])%MOD;
		}

		cout << sum << endl;
	}
}
