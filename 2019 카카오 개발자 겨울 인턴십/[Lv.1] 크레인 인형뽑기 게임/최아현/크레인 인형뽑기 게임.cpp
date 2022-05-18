/*#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	int target;
	stack<int> s;

	for (int i = 0; i< moves.size(); i++) {
		target = 0;

		for (int j = 0; j<board.size(); j++) {

			if (board[j][moves[i] - 1] != 0) {
				target = board[j][moves[i] - 1];
				board[j][moves[i] - 1] = 0;
				break;
			}

		}
		if (target == 0) // 스택이 0으로 쌓이는거 방지
			continue;

		if (!s.empty()) {
			if (target == s.top()) {
				s.pop();
				answer += 2;
				continue;
			}
			else {
				s.push(target);
				continue;
			}
		}
		else {
			s.push(target);
			continue;
		}
	}

	return answer;
}*/
