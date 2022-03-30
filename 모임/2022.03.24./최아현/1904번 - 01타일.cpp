#include <iostream>
#include <vector>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);

	int N, result = 0;

	cin >> N;

	vector<int> a(N+1);

	a[0] = 1;
	a[1] = 1;
	for (int i = 2; i <= N; i++) {
		a[i] = (a[i - 1] + a[i - 2]) % 15746;
	}

	cout << a[N];

	return 0;
}
