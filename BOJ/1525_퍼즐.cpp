#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

int board[3][3];
queue<pair<int, string>> q;
map<string, int> visited;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int px, py;
string map_to_str() {
	string str = "";
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			str += to_string(board[i][j]);
		}
	}
	return str;
}
void str_to_map(string str) {
	for (int i = 0;i < str.length();i++) {
		int row = i / 3;
		int col = i % 3;
		board[row][col] = str[i] - '0';
		if (board[row][col] == 0) {
			px = col; py = row;
		}
	}
}
int bfs() {
	
	while (!q.empty()) {
		string cur_str = q.front().second;
		int cnt = q.front().first;
		q.pop();
		str_to_map(cur_str);
		
		if (cur_str == "123456780") {
			return cnt;
		}

		for (int dir = 0;dir < 4;dir++) {
			int nx = px + dx[dir];
			int ny = py + dy[dir];
			if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
				swap(board[ny][nx], board[py][px]);
				string next_str = map_to_str();
				//cout << next_str << endl;
				if (!visited[next_str]) {
					//cout << next_str << endl;
					visited[next_str] = 1;
					q.push({ cnt + 1,next_str });
				}
				swap(board[ny][nx], board[py][px]);
			}
		}

	}
	return -1;
}

int main() {

	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			cin >> board[i][j];
			
		}
	}
	string str = map_to_str();
	visited[str] = 1;
	q.push({ 0,str });
	cout << bfs();

	return 0;
}