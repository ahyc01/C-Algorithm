#include <iostream>
#include<queue>

using namespace std;

int main() {

	int n, m, x;

	cin >> n >> m;

	priority_queue<int> present;

	for (int i = 0; i < n; i++) {
		cin >> x;
		present.push(x);
	}
	for (int j = 0; j < m; j++) {
		cin >> x;

		if (present.top() >= x) {
			present.push(present.top() - x);
			present.pop();
		}
		else {
			cout << 0;
			return 0;
		}

	}
	cout << "1";
	return 0;
}