#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int N;
	vector<int> answer;
	string command;

	queue<int> q;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> command;

		if (command == "push") {
			int data;
			cin >> data;
			q.push(data);
		}
		else if (command == "pop") {
			if (q.size() == 0) {
				answer.emplace_back(-1);
			}
			else {
				answer.emplace_back(q.front());
				q.pop();
			}
		}
		else if (command == "size") {
			answer.emplace_back(q.size());
		}
		else if (command == "empty") {
			if (q.size() == 0) {
				answer.emplace_back(1);
			}
			else {
				answer.emplace_back(0);
			}
		}
		else if (command == "front") {
			if (q.size() == 0) {
				answer.emplace_back(-1);
			}
			else {
				answer.emplace_back(q.front());
			}
		}
		else {
			if (q.size() == 0) {
				answer.emplace_back(-1);
			}
			else {
				answer.emplace_back(q.back());
			}
		}
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}

	return 0;
}
