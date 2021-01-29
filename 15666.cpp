#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
using namespace std;
int n, m;
vector<int> vec, num;
int visited[11];
set<string> ss;
void go(int pos, int dep, string str) {
	if (dep == m) {
		//m°³¸¦ ¸ðµÎ °ñ¶ú´Ù¸é
		if (ss.find(str)==ss.end()) {
			ss.insert(str);
			for (int x : vec) {
				cout << x << " ";
			}
			cout << '\n';
		}
		
		return;
	}

	for (int i = 0;i < n;i++) {
		if (vec.empty() || vec.back() <= num[i]) {
			vec.push_back(num[i]);
			str.push_back(num[i] + '0');
			go(pos + 1, dep + 1, str);
			str.pop_back();
			vec.pop_back();
		}
		
	}
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	int in;
	for (int i = 0;i < n;i++) {
		cin >> in;
		num.push_back(in);
	}
	sort(num.begin(), num.end());
	go(0, 0, "");


	return 0;
}