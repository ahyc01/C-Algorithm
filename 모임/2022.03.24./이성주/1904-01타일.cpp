#include <iostream>
#include <vector>

using namespace std;

int N, tmp;

int main() {
	vector<unsigned int> result = {0, 1, 2};

	cin >> N;

	for (int i = 3; i < N + 1; i++) {
		tmp = result[i - 1] + result[i - 2];
		result.push_back(tmp%15746);
	}

	cout << result[N];
}
