#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
string target;
int nums[11];
int visited[2][1000001];
queue<pair<int,pair< int, string>>> q;	//stat, cnt, str
void bfs() {
	
	while (!q.empty()) {
		string cur = q.front().second.second;
		int cnt = q.front().second.first;
		int reset = q.front().first;	//이전에 +,-버튼 누름
		q.pop();
	
		if (cur==target) {
			cout << cnt;
			return;
		}

		int cur_int = stoi(cur);
		//if (cur_int > 500000)
		//	continue;
		//+
		if (!visited[1][cur_int + 1]) {
			visited[1][cur_int + 1] = 1;
			q.push({ 1,{cnt + 1,to_string(cur_int + 1) } });
		}
		//-
		if (cur_int > 0 && !visited[1][cur_int-1]) {

			visited[1][cur_int - 1] = 1;
			q.push({ 1,{cnt + 1,to_string(cur_int - 1) } });
		}
		//숫자
		for (int i = 0;i <= 9;i++) {
			if (!reset) {	// 숫자 이어 붙이기
				if (nums[i] != -1) {
					string next_str = cur + to_string(i);
					int next_int = stoi(next_str);
					if (next_int > 1000000)
						continue;
					if (!visited[0][next_int]) {
						visited[0][next_int] = 1;
						q.push({ 0,{cnt + 1,next_str } });
					}
				}
			}
			else {
				//숫자 head에 추가
				if (nums[i] != -1) {
					if (!visited[0][i]) {
						visited[0][i] = 1;
						q.push({ 0,{cnt + 1,to_string(i)} });
					}
				}
			}
		}
	}


}
int main() {
	int n, in;
	cin >> target >> n;
	for (int i = 0;i < n;i++) {
		cin >> in;
		nums[in] = -1;
	}
	visited[1][100] = 1;
	q.push({ 1,{ 0,"100" } });
	bfs();

	return 0;
}