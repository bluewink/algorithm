#include <iostream>
#include <vector>
using namespace std;
vector<pair<int,int>> vec;

int main() {
	int n, in;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> in;
		vec.push_back({ i,in });
	}
	vector<pair<int,int>>::iterator iter = vec.begin();
	int cnt;
	for (int i = 0;i < n;i++) {
		cnt = 0;
		cout << (*iter).first << endl;
		if (i == n - 1)
			break;
		int turn = (*iter).second;

		if (iter == vec.end() - 1) {
			vec.erase(iter);
			iter = vec.begin();
		}
		else
			iter = vec.erase(iter);
		turn = turn > 0 ? turn - 1 : turn;
		if (turn > 0) {
			while (cnt < turn) {
				if (iter == vec.end()-1)
					iter = vec.begin();
				else
					iter++;
				cnt++;
			}
		}
		else {
			while (cnt > turn) {
				if (iter == vec.begin())
					iter = vec.end()-1;
				else
					iter--;
				cnt--;
			}
		}
		
	}
	return 0;
}