#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<pair<int,int>> vec;
queue<pair<int, int>> q;
int main() {
	int n, in;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> in;
		q.push({ i,in });
	}
	while(!q.empty()){
		cout << q.front().first << endl;
		int turn = q.front().second;
		q.pop();
		if (q.empty())
			break;
		turn = turn > 0 ? turn - 1 : n*q.size()+turn;
		int cnt = 0;
		while (cnt < turn) {
			pair<int,int> cur = q.front();
			q.pop();
			q.push(cur);
			cnt++;
		}
	}
	return 0;
}