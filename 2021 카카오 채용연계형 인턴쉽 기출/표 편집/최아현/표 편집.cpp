#include <string>
#include <iterator>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

int location(int k, int loca, vector<string> table) {

	int cnt = 0;
	int i = 1;

	if (loca < 0) { // UP
		while (cnt != loca) {
			if (table[k - i] != "X") {
				cnt--;
			}
			i++;
		}
		return k - i + 1;
	}
	else { // Down
		while (cnt != loca) {
			if (table[k + i] != "X") {
				cnt++;
			}
			i++;
		}
		return k + i - 1;
	}
}

string solution(int n, int k, vector<string> cmd) {
	string answer = "";
	int loc;
	vector<string> table(n);
	stack<int> last_del;

	for (int i = 0; i<n; i++) {
		table[i] = 'O';
	}

	for (string s : cmd) {

		if (s[0] == 'D' || s[0] == 'U') {
			if (s[0] == 'U') {
				loc = -stoi(s.substr(2));
			}
			else {
				loc = stoi(s.substr(2));
			}
			k = location(k, loc, table);
		}
		else if (s[0] == 'C') { // 삭제 후 아래로
			table[k] = 'X';
			last_del.push(k);

			if (k == n - 1) // 맨 아래였을 경우
				k = location(k, -1, table);
			else
				k = location(k, 1, table);
		}
		else if (s[0] == 'Z') {
			table[last_del.top()] = 'O';
			last_del.pop();
		}
		else {
			cout << "error\n";
		}

	}
	for (string i : table) {
		answer.append(i);
	}
	return answer;
}
