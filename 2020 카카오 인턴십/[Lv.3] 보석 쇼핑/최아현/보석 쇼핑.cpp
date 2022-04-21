#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> gems) {
	vector<int> answer(2);
	vector<string> list;
	unordered_map<string, int> m;

	list = gems;
	int min, start = 0, end = 0;

	sort(list.begin(), list.end());
	list.erase(unique(list.begin(), list.end()), list.end());

	for (int j = 0; j < gems.size(); j++) {
		for (int z = 0; z < list.size(); z++) {
			if (gems[j] == list[z]) {
				list.erase(list.begin() + z);
				break;
			}
		}
		if (list.size() == 0) {
			end = j;
			break;
		}
	}
	cout << end << "\n";

	for (int i = 0; i <= end; i++) {
		m[gems[i]]++; // end까지의 보석 갯수 확인
	}

	min = end - start;  //min 구간
	answer[0] = start + 1; // 시작위치
	answer[1] = end + 1; // 끝 위치

	while (end < gems.size()) {
		string s = gems[start];
		m[s]--;
		start++;

		if (m[s] == 0) { 
			end++;
			for (; end < gems.size(); end++) {
				m[gems[end]]++;
				if (s == gems[end])
					break;
			}
			if (end == gems.size()) 
				break;
		}
		if (min > end - start) { // 더 작을 때
			answer[0] = start + 1;
			answer[1] = end + 1;
			min = end - start;
		}
	}
	return answer;
}

int main() {
	vector<string> gems = { "XYZ", "XYZ", "XYZ" };
	vector<int> answer(2);
	answer = solution(gems);
	for (int a : answer)
		cout << a;
	return 0;
}