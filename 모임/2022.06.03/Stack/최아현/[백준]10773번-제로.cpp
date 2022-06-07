/*#include<stack>
#include<iostream>

using namespace std;

int main() {

	int K,x,result=0;
	cin >> K;
	
	stack<int> s;

	for (int i = 0; i < K; i++) {
		cin >> x;

		if (x != 0) {
			s.push(x);
		}
		else {
			s.pop();
		}
	}

	while (!s.empty()){
		result += s.top();
		s.pop();
	}
	cout << result;
	return 0;
}*/