#include <iostream>
#include <map>
#include <string>

using namespace std;

#define fast_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int main() {
	int N = 0, cnt = 0;
	string cmd, answer;
	map<string, int> m;
  fast_IO;
  
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> cmd;
		m[cmd] += 1;
	}

	for (auto map : m) {
		if (cnt < map.second) {
			cnt = map.second;
			answer = map.first;
		}
	}

	cout << answer;
}
