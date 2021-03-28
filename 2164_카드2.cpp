#include <iostream>
#include <deque>
using namespace std;
deque<int> dq;
int main() {

	int n;

	cin >> n;
	for (int i = 1;i <= n;i++)
		dq.push_back(i);

	while (1) {
		if (dq.size() == 1) {
			cout << dq.front();
			break;
		}
		dq.pop_front();
		int cur = dq.front();
		dq.pop_front();
		dq.push_back(cur);
	}

	return 0;
}