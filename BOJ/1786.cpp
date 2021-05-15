#include <iostream>
#include <vector>
#include <string>
using namespace std;
string src, target;
vector<int> pi;
void getPi() {
	
	pi.resize(target.size(), 0);
	int j = 0;
	for (int i = 1;i < target.size();i++) {
		while (j > 0 && target[i] != target[j]) {
			j = pi[j - 1];
		}
		if (target[i] == target[j]) {
			pi[i] = ++j;
		}
	}
	return;
}

vector<int> kmp() {
	int j = 0;
	vector<int> res;

	for (int i = 0;i < src.size();i++) {

		while (j > 0 && src[i] != target[j]) {
			j = pi[j - 1];
		}
		if (src[i] == target[j]) {
			if (j == target.size() - 1) {
				res.push_back(i - target.size() + 2);
				j = pi[j];
			}
			else {
				j++;
			}
		}
		

	}

	return res;
}

int main() {

	getline(cin, src);
	getline(cin, target);


	getPi();
	vector<int> res = kmp();

	cout << res.size() << endl;
	for (int x : res) {
		cout << x << " ";
	}


	return 0;
}