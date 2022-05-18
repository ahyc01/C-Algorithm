#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
	vector<int> answer;
	vector<int> se;
	vector<int> nums(100001);

	string num = "";

	for (auto i : s) {
		if ((i >= '0' && i <= '9')) {
			num += i;
		}
		else {
			if (num != "") {
				se.push_back(stoi(num));
				num = "";
			}
		}
	}

	sort(se.begin(), se.end());

	for (auto j : se) {
		nums[j] += 1;
	}

	se.erase(unique(se.begin(), se.end()), se.end());

	for (auto z : se) {
		int max = max_element(nums.begin(), nums.end()) - nums.begin();
		cout << z << " - ";
		cout << max << "\n";
		answer.push_back(max);
		nums[max] = 0;
	}

	return answer;
}