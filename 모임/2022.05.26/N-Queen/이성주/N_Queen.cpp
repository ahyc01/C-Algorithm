#include <iostream>

using namespace std;

int N, answer;
int board[15];

bool check_batch(int depth) {
	for (int i = 0; i < depth; i++) {
		if (board[i] == board[depth] || abs(board[depth] - board[i]) == depth - i) { // 같은 라인이거나, 대각선에 위치할 경우
			return false;
		}
	}
	return true;
}

void N_Queen(int qn) {
	if (qn == N) {
		answer++;
	}
	else {
		for (int i = 0; i < N; i++) {
			// cout << i << " ";
			board[qn] = i; // 퀸 배치, Index는 행 Value는 열
			if (check_batch(qn)) { // True면 다음 행에서 배치 시작
				N_Queen(qn + 1);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	N_Queen(0);
	
	cout << answer;
}

// https://cryptosalamander.tistory.com/58*/
