/*#include<queue>
#include<iostream>
#include<string>
#include<sstream>
#include<vector>

using namespace std;

int main(){

	int n;
	string x;
	int y;
	string buffer;

	vector<string> result;
	queue<int> q;
	cin >> n;

	for(int i=0;i<n;i++){
		cin >> x;

		if (x == "push") {
			cin >> y;
			q.push(y);
		}
		else if (x == "size") {
			cout << q.size() << "\n";
		}
		else if (x == "empty") {
			if (q.empty()) {
				cout << "1\n";
			}
			else cout << "0\n";
		}
		else if (q.empty()) {
			cout << "-1\n";
		}
		else if (x == "pop") {
			cout << q.front() << "\n";
			q.pop();
		}
		else if (x == "front") {
			cout << q.front() << "\n";
		}
		else if (x == "back") {
			cout << q.back() << "\n";
		}	
	}
	return 0;
}*/