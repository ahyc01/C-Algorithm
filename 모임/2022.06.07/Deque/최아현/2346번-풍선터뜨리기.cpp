#include<iostream>
#include<deque>
#include<vector>

using namespace std;

int main() {

	int n,x,tmp;
	deque<int> d;
	vector<int> v;
	vector<int> bol;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		d.push_front(i);
		cin >> x;
		bol.push_back(x);

	}
	x = 0;
	v.push_back(d.back());
	d.pop_back();

	for (int j = 0; j < n-1; j++) {

		if (bol[x] > 0) {
			for (int z = 0; z < bol[x]-1; z++) {
				tmp = d.back();
				d.pop_back();
				d.push_front(tmp);
			}
			x = d.back() - 1;
			v.push_back(d.back());
			d.pop_back();
		}
		else {
			for (int z = 0; z > bol[x] +1; z--) {
				tmp = d.front();
				d.pop_front();
				d.push_back(tmp);
			}
			x = d.front() - 1;
			v.push_back(d.front());
			d.pop_front();
		}
	}
	for (int i : v) {
		cout << i << " ";
	}

	return 0;
}