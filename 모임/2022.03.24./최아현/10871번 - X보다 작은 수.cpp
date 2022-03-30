/*#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, X, A;
	vector<int> result;

	cin >> N >> X;

	for (int i = 0; i < N; i++) {

		cin >> A;
		if (A < X) {
			result.push_back(A);
		}
	}
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}

	return 0;
}*/