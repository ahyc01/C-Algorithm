#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N, cnt, AC; // AC = Apartment Complex
string house;
vector<int> answer;
// memset(visited, 0, sizeof(visited));
int visited[25][25] = { 0, };
int board[25][25];

int xx[4] = { 1,0,-1,0 };
int yy[4] = { 0,1,0,-1 };

void DFS(int y, int x)
{
	cnt++;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + xx[i];
		int ny = y + yy[i];

		if (ny < 0 || nx < 0 || nx >= N || ny >= N)
			continue;

		if (board[ny][nx] && !visited[ny][nx])
		{
			visited[ny][nx] += 1;
			DFS(ny, nx);
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> house;
		for (int j = 0; j < N; j++) {
			if (house[j] == '1') {
				board[i][j] = 1;
			}
			else {
				board[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 1 && visited[i][j] == 0) {
				visited[i][j] = 1;
				cnt = 0;
				DFS(i, j);
				answer.emplace_back(cnt);
				AC++;
			}
		}
	}

	sort(answer.begin(), answer.end());

	cout << AC << "\n";
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}
	
	return 0;
}
