
/*
	문자열폭발
	
	스택 두개를 활용해 풀었다.
	스택 하나를 복구용으로 사용해서, 뒤에서부터 폭발을 일으키다가, 폭발이 발생하지 않을 경우 문자열을 원상복구했다.

	예외 처리를 하나 빼먹음.

	input : baba / ab
	-> runtime error
	-> src가 target보다 길 때만 폭발이 일어나도록 예외처리함.

*/


#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
stack<char> master, tmp;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	string str, target;
	cin >> str >> target;

	int flag = 1;

	for (char x : str) {
		master.push(x);
		if (x == target.back() && master.size()>=target.length()) {
			flag = 1;
			for (int i = target.length()-1;i >=0;i--) {
				//target 길이만큼 꺼내서 비교
				char cur = master.top();
				master.pop();
				//tmp에 옮겨두기
				tmp.push(cur);
				if (cur != target[i]) {
					//일치하지 않는다. 복구하자.
					while (!tmp.empty()) {
						master.push(tmp.top());
						tmp.pop();
					}
					flag = 0;
					break;
				}
			}
			if (flag) {
				//문자열 폭발!
				while (!tmp.empty())
					tmp.pop();
			}
		}
	}

	if (master.empty()) {
		cout << "FRULA";
		return 0;
	}
	string ans;
	while (!master.empty()) {
		ans.push_back(master.top());
		master.pop();
	}
	reverse(ans.begin(), ans.end());
	cout << ans;

	return 0;
}