/*
	우선순위 큐
	
	항상 min heap 크기를 n으로 유지한다.
	1. heap에 n개를 채우고,
	2. 이후에 넣을 때마다 하나를 빼준다.
	3. 모든 탐색이 끝났을 때 heap안에는 n번째로 큰수, n-1번째로 큰수... 1번째로 큰수가 들어간다.
	4. 따라서 top에 있는게 n번째로 큰수가 된다.

	메모리 초과가 나서 고민하다가 풀이를 참고했다... ㅠㅠ

*/
#include <iostream>
#include <queue>

using namespace std;
priority_queue<int, vector<int>, greater<>> pq;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, in;
	cin >> n;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			cin >> in;
			if (i == 0) {
				pq.push(in);
			}
			else {
				pq.push(in);
				pq.pop();
			}
		}
	}
	cout << pq.top();

	return 0;
}