#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int n;
string str;
int play(int opt) {
	int cnt = 0;
	if (opt) {
		//R로 먼저 뒤집어
		char target = 'B';
		for (int i = 0;i < n;i++) {
			if (str[i] == 'R')
				continue;
			else {
				if (i == 0) {
					cnt++;
					continue;
				}
				if (str[i - 1] == str[i]) {
					continue;
				}
				cnt++;
			}
		}
	}
	else {
		//B로 먼저 뒤집어
		char target = 'R';
		for (int i = 0;i < n;i++) {
			if (str[i] == 'B')
				continue;
			else {
				if (i == 0) {
					cnt++;
					continue;
				}
				if (str[i - 1] == str[i]) {
					continue;
				}
				cnt++;
			}
		}
	}
	return cnt;
}
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	
	cin >> str;
	cout << min(play(0), play(1))+1;

	return 0;
}