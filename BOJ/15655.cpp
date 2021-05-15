#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
vector<int> vec, num;

void go(int pos,int dep) {
	if (dep == m) {
		//m°³¸¦ ¸ðµÎ °ñ¶ú´Ù¸é
		for (int x : vec) {
			cout << x << " ";
		}
		cout << '\n';
		return;
	}

	for (int i =pos;i<n;i++) {
		if (vec.empty() || vec.back() < num[i]) {
			vec.push_back(num[i]);
			go(pos + 1, dep + 1);
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
	go(0, 0);
	

	return 0;
}