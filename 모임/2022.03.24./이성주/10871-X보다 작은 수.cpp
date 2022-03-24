#include <iostream>

using namespace std;

/* 
  선언해주면 빠르게 읽어온다. cin, cout이 scanf, printf 보다 느리다.
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL); 
*/

int N, X, A;

int main() {
	cin >> N >> X;

	for (int i = 0; i < N; i++) {
		cin >> A;
		if (A < X) {
			cout << A << " ";
		}
	}
}
