#include <iostream>
#include <string>

using namespace std;

// N=1 : 1 => 1
// N=2 : 10 => 1
// N=3 : 100 101 => 2
// N=4 : 1000 1010 1001 => 3
// N=5 : 10000 10.101 100.10 10.100 100.01 => 5
// N=6 : 100000 101000 101010 101001 100100 100101 100010 100001 => 8

// unsigned long int dp[91]; => N이 47까지만 올바르게 표시됨.
long long int dp[91];

int main() {
	int N;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 2;
	dp[4] = 3;
	dp[5] = 5;
	dp[6] = 8;

	for (int i = 6; i <= N; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[N];

	return 0;
}
