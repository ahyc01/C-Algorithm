#include<iostream>
#include<map>
#include<string>

using namespace std;

int main() {

	map<string, int> m;
	int n, Vmax=0;
	string x, Kmax;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x;
		if (m.count(x)) { // 키 있으면 +1
			m[x] += 1;
		}
		else { // 없으면 추가
			m[x] = 1;
		}
	}

	for (auto j : m) { // 맵안의 원소들 value max 찾기
		if (Vmax < j.second) {
			Vmax = j.second;
			Kmax = j.first;
		}
	}
	cout << Kmax;

	return 0;
}
