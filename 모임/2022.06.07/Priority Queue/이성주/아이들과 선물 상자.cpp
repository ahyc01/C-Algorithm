#include <iostream>
#include <queue>

using namespace std;

#define fast_IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int main() {
	int N, M;
	priority_queue<int> gift;
	fast_IO;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int gift_box;
		cin >> gift_box;
		gift.push(gift_box);
	}

	for (int i = 0; i < M; i++) {
		int child;
		cin >> child;

		// 아이가 원하는 선물 개수가 선물 상자에서 꺼낼 수 있는 개수라면
		if (child <= gift.top()) {
			if (child == gift.top()) { // 아이가 원하는 선물 개수와 상자에 있는 개수가 같다면 0 이므로 -> 큐에 굳이 넣을 필요없음 -> 건너뜀
				continue;
			}
			gift.push(gift.top() - child); // 아이가 원하는 개수를 주고 나머지를 우선 순위 큐에 다시 push
			gift.pop();
		}
		else { // 아이가 원하는 선물 개수가 선물 상자에서 꺼낼 수 없는 개수라면 0을 출력 후 바로 종료.
			cout << 0;
			return 0;
		}
	}

	cout << 1;

	return 0;
}
