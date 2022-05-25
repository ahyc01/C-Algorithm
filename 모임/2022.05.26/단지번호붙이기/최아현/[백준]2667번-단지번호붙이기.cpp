#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

queue<pair <int,int> > q;
string map[25];
bool visited[25][25] = {0, };
int N;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int bfs(int x, int y) {
	int cnt = 0, a, b, nx, ny;

	visited[x][y] = true;
	q.push({ x,y });
	cnt++;

	while (!q.empty()) {
		a = q.front().first;
		b = q.front().second;
		q.pop();

		for (int j = 0; j < 4; j++) {
			nx = a + dx[j];
			ny = b + dy[j];
			if (nx >= 0 && ny >= 0 && nx < N && ny < N
				&& visited[nx][ny] == false && map[nx][ny] == '1') {
				q.push({ nx,ny });
				visited[nx][ny] = true;
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {

	int cnt;
	cin >> N;
	
	vector<int> result;
	
	for (int i = 0; i < N; i++) {
		cin >> map[i];
	}

	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			//cout << map[x][y];
			if (map[x][y] == '1' && visited[x][y] == false) {
				cnt = bfs(x, y);
				result.push_back(cnt);
			}
		}
	}
	sort(result.begin(), result.end());

	cout << result.size() << "\n";
	for (int z = 0; z < result.size(); z++) {
		cout << result[z] << "\n";
	}

	return 0;
}
