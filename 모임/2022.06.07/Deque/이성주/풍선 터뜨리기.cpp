#include <iostream>
#include <deque>

using namespace std;

#define fast_IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

int main() {
	int N, num, tmp;
	deque<pair<int, int>> balloon;
	fast_IO;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> tmp;
		balloon.emplace_back(make_pair(i, tmp));
	}

	while (!balloon.empty()) {
		cout << balloon.front().first << ' '; // 주의! 출력이 한칸씩 공백으로 출력된다.
		num = balloon.front().second;
		balloon.pop_front();

		if (balloon.size() != 0) {
			if (num > 0) {
				num -= 1;
				for (int i = 0; i < num; i++) {	// 데이터 중간에서 삭제가 불가능하므로 이동 순서는 앞뒤로 유지하되 해당 인덱스(다음 풍선 위치)를 front로 위치시킴.
					balloon.emplace_back(balloon.front());
					balloon.pop_front();
				}
				num = 0;
			}
			else {
				for (int i = 0; i > num; i--) {
					balloon.emplace_front(balloon.back());
					balloon.pop_back();
				}
				num = 0;
			}
		}
	}

	return 0;
}
