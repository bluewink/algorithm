#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

/*
소수 목록 저장.
bfs

시간복잡도
소수 구하기 : 10^6
bfs : 10*4 + 10^4
*/
int visited[10001];
vector<int> prime_vec;
queue<pair<string,int>> q;
int ans = -1;
void bfs(string target) {
	string tmp;
	while (!q.empty()) {
		string cur = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (cur == target) {
			ans = cnt;
			return;
		}
		for (int i = 0;i <= 3;i++) {
			//0 자리, 1 자리, 2자리, 3자리
			tmp = cur;
			for (int j = 0;j <= 9;j++) {
				tmp[i] = j + '0';
				if (stoi(tmp)>=1000 && !visited[stoi(tmp)]) {
					if (find(prime_vec.begin(), prime_vec.end(), stoi(tmp)) != prime_vec.end()) {
						visited[stoi(tmp)] = 1;
						q.push({ tmp, cnt + 1 });
					}

				}
			}

		}
	}
}

int prime_chk(int x) {

	for (int i = 2;i*i <= x;i++) {
		if (x%i == 0) {
			return -1;
		}
	}
	return 1;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int tn;
	string a, b;

	//소수 목록 저장
	
	for (int i = 1000;i <= 9999;i++) {
		if (prime_chk(i) == 1) {
			prime_vec.push_back(i);
		}
	}

	cin >> tn;
	while (tn--) {
		cin >> a >> b;
		ans = -1;

		while (!q.empty()) {
			q.pop();
		}
		memset(visited, 0, sizeof(visited));

		q.push({ a,0 });
		bfs(b);
		if (ans == -1) {
			cout << "Impossible" << '\n';
		}
		else {
			cout << ans << '\n';
		}
	}



	return 0;
}