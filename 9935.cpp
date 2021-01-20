
/*
	���ڿ�����
	
	���� �ΰ��� Ȱ���� Ǯ����.
	���� �ϳ��� ���������� ����ؼ�, �ڿ������� ������ ����Ű�ٰ�, ������ �߻����� ���� ��� ���ڿ��� ���󺹱��ߴ�.

	���� ó���� �ϳ� ������.

	input : baba / ab
	-> runtime error
	-> src�� target���� �� ���� ������ �Ͼ���� ����ó����.

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
				//target ���̸�ŭ ������ ��
				char cur = master.top();
				master.pop();
				//tmp�� �Űܵα�
				tmp.push(cur);
				if (cur != target[i]) {
					//��ġ���� �ʴ´�. ��������.
					while (!tmp.empty()) {
						master.push(tmp.top());
						tmp.pop();
					}
					flag = 0;
					break;
				}
			}
			if (flag) {
				//���ڿ� ����!
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