#include <iostream>
#include <stack>

using namespace std;

int main() {
	int N, num, answer = 0;
	stack<int> s;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> num;

		if (num == 0) {
			s.pop();
		}
		else {
			s.push(num);
		}

	}

	int size = s.size();
	for (int i = 0; i < size; i++) {
		answer += s.top();
		s.pop();
	}

	cout << answer;

	return 0;
}
