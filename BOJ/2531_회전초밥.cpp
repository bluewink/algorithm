/*
	회전초밥
	
	투포인터
	시행착오 1. set을 이용해서 종류 개수를 체크했더니 시간초과가 났다. 
	해결 : map을 이용해서 종류 개수를 파악했다.
		map의 값이 0이 되면 erase 해줘서 map의 size == 종류 개수가 되도록 함.
*/
#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <algorithm>
#include <map>
using namespace std;
vector<int> tmp, sushi;
deque<int> dq;
map<int, int> m;
int MM = -1;
int n, type_num, k, bonus;
void check() {

	MM = max(MM, (int)m.size());
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> type_num >> k >> bonus;
	int in;
	for (int i = 0;i < n;i++) {
		cin >> in;
		tmp.push_back(in);
		sushi.push_back(in);
	}
	for (int x : tmp) {
		sushi.push_back(x);
	}

	int start, end;
	start = end = 0;
	m[sushi[0]]++;
	
	while (1) {
		if (start >= tmp.size()+1) {
			break;
		}
		while (end - start < k-1) {
			end++;
			m[sushi[end]]++;
			if (end - start == k - 1) {
				check();
				m[bonus]++;
			}
		}

		m[sushi[start]]--;
		if (m[sushi[start]] == 0) {
			m.erase(sushi[start]);
		}
		start++;
	}

	cout << MM;

	return 0;
}