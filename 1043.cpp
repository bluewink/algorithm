#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//union & find

int parent[51];
vector<vector<int>> party;
vector<int> know_ppl;
int find(int a) {
	if (parent[a] < 0) return a;
	parent[a] = find(parent[a]);
	return parent[a];
	
}

void merge(int a, int b) {
	int aa = find(a);
	int bb = find(b);
	if (aa == bb) {
		return;
	}
	parent[aa] = bb;

}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	int ppl_num, party_num, know_num, in, tmp;

	cin >> ppl_num >> party_num;
	cin >> know_num;

	for (int i = 0;i < know_num;i++) {
		cin >> in;
		know_ppl.push_back(in);
	}
	vector<int> single_party;
	for (int i = 0;i < party_num;i++) {
		//��Ƽ���� ���� ����� ����
		cin >> tmp;
		for (int j = 0;j < tmp;j++) {
			cin >> in;
			single_party.push_back(in);
		}
		party.push_back(single_party);
		single_party.clear();
	}
	
	fill(parent, parent + 51, -1);
	//�˰� �ִ� ������� ���� set���� ����.
	for (int i = 0;i < know_num;i++) {
		if (i >= 1) {
			merge(know_ppl[0], know_ppl[i]);
		}
	}
	//��Ƽ ������ ��� union-find
	for (vector<int> vec : party) {
		for (int i = 0;i < vec.size();i++) {
			if (i >= 1) {
				merge(vec[0], vec[i]);
			}
		}
	}
	int flag, cnt;
	cnt = 0;

	for (vector<int> vec : party) {
		flag = 0;
		for (int i = 0;i < vec.size();i++) {
			if (know_num > 0) {
				if (find(know_ppl[0]) == find(vec[i])) {
					//������ �ƴ� ����� �ִ�
					flag = -1;
					break;
				}
			}
		}
		if (flag == 0) {
			cnt++;
		}
	}
	cout << cnt;


	return 0;
}