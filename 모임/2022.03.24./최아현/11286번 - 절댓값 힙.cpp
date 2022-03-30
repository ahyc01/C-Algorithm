#include <iostream>
#include <queue>
#include <functional> // greater

using namespace std;

priority_queue<int, vector<int>, greater<int>> u_pq; //오름차순 작은게 위로(양수)
priority_queue<int> d_pq; //내림차순 큰게 위로(음수)

void func () {
	if (u_pq.empty() & d_pq.empty()) {
		cout << "0\n";
	}
	else if(u_pq.empty()){
		cout << d_pq.top() << "\n";
		d_pq.pop();
	}
	else if (d_pq.empty()) {
		cout << u_pq.top() << "\n";
		u_pq.pop();
	}
	else {
		if (abs(u_pq.top()) >= abs(d_pq.top())) {

			cout << d_pq.top() << "\n";
			d_pq.pop();
		}
		else {
			cout << u_pq.top() << "\n";
			u_pq.pop();
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);

	int N, x;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x;

		if (x == 0) { // 0 일때
			func();
		}
		else if (x > 0) { // 양수일 때 u_pd
			u_pq.push(x);
		}
		else {
			d_pq.push(x); // 음수일 때 d_pq
		}
	}
	return 0;
}