#include <iostream>
#include <queue>
#include <vector>
// #include <functional> // 2015에서 우선 순위 큐 비교 연산자(greater<자료형> : 오름차순, less<자료형> : 내림차순)를 사용하기 위해서 선언한다. 아니면 직접 함수를 구현해 사용한다.

using namespace std;

#define fast_IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

struct cmp {
	bool operator() (int a, int b) {
		return a > b;
	}
};

int main() {
	// 2,147,483,647은 컴퓨팅에서 32비트 부호 정수형의 최댓값이기도 하다. 그래서 일반적인 CPU 위에서 작동하는 많은 프로그래밍 언어에서 변수 int로 선언될 수 있는 최댓값으로 지정되어 있다.
	// x -> 2^31 = 2,147,483,648
	int N, x;
	vector<int> answer;
	priority_queue<int, vector<int>, cmp> min_heap;
	fast_IO;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x;
		if (x == 0) {
			if (min_heap.empty()) {
				answer.emplace_back(0);
			}
			else {
				answer.emplace_back(min_heap.top());
				min_heap.pop();
			}
		}
		else {
			min_heap.push(x);
		}
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}

	return 0;
}
