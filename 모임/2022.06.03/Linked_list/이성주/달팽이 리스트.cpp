// 배열의 크기가 최대 200,000이고 쿼리 개수가 최대 1,000,000,000개이기 때문에 브루트포스로는 접근할 수 없는 문제
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, M, V, K;
	int N_arr[200001] = { 0, };
	vector<int> answer;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> V;

	for (int i = 0; i < N; i++) {
		cin >> N_arr[i];
	}

	int cycle = V - 1;

	for (int i = 0; i < M; i++) {
		cin >> K;

		if (K < cycle) {
			answer.emplace_back(N_arr[K]);
		}
		else {
			answer.emplace_back(N_arr[(K - cycle) % (N - cycle) + cycle]); // 입력된 값이 순회되는 구간이 아니면 해당 길이를 입력값과 전체길이에서 제외하고 나머지 값을 구한다. 그 후 cycle 값으로 shift
		}
	}

	for (int i = 0; i < M; i++) {
		cout << answer[i] << '\n';
	}

	return 0;
}
