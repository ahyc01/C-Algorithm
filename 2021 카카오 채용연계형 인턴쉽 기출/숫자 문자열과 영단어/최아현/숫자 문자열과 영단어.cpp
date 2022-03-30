#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
	string answer;
	char n;
	vector<string> num = { "zero", "one", "two","three","four","five","six","seven","eight","nine" };

	int l = s.size();

	for (int i = 0; i <l; i++) {

		if (s[i] >= '0' && s[i] <= '9') { // 숫자
			answer.push_back(s[i]);
		}
		else { // 문자
			for (int j = 0; j<10; j++) {
				if (num[j][0] == s[i]) {
					if (num[j][1] == s[i + 1]) { // 비교
						n = j + '0';
						answer.push_back(n); // 영단어 크기만큼 넘기기
						i += num[j].size() - 1;
						break;
					}
				}
			}
		}
	}
	return stoi(answer);
}