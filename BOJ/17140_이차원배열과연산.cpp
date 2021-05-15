/*
	삼성역량테스트 기출문제 구현/시뮬레이션

	구현이 까다롭고 예외처리할 게 많아서 힘들었따..

*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<int, int> pi;
vector<vector<int>> vec;
map<int, int> m;

bool cmp(const pi& a, const pi& b) {
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

vector<pi> sort_map() {
	vector<pair<int, int> > tmp(m.begin(), m.end());
	sort(tmp.begin(), tmp.end(), cmp);

	return tmp;
}

void transpose(vector<vector<int> > &b)
{
	if (b.size() == 0)
		return;

	vector<vector<int> > trans_vec(b[0].size(), vector<int>());

	for (int i = 0; i < b.size(); i++)
	{
		for (int j = 0; j < b[i].size(); j++)
		{
			trans_vec[j].push_back(b[i][j]);
		}
	}

	b = trans_vec;   
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int r, c, k;
	cin >> r >> c >> k;
	int in;
	vector<int> tmp;
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			cin >> in;
			tmp.push_back(in);
		}
		vec.push_back(tmp);
		tmp.clear();
	}
	int t = 0;
	int row_size, col_size;
	
	while (1) {

		row_size = vec.size();
		col_size = vec[0].size();
		
		if (row_size>=r && col_size>=c && vec[r-1][c-1] == k) {
			break;
		}

		t++;
		if (t > 100) {
			cout << -1;
			return 0;
		}
	

		if (row_size >= col_size) {
	
			int MM = -1;
			for (int rr = 0;rr < row_size;rr++) {
				m.clear();
				for (int cc = 0;cc < col_size;cc++) {
					if (vec[rr][cc] == 0)
						continue;
					m[vec[rr][cc]]++;
				
				}
				vector<pi> map_vec = sort_map();
			
				vector<int> new_vec;
				for (auto xx : map_vec) {
					new_vec.push_back(xx.first);
					new_vec.push_back(xx.second);
				}
				MM = max(MM, (int)new_vec.size());
				vec[rr] = new_vec;	//이게 되나? 갈아끼우기..
				
			}
			for (int i = 0;i < row_size;i++) {
				if (vec[i].size() > 100)
					vec[i].resize(100);

				else if (vec[i].size() < MM) {
					vec[i].resize(MM);
				}
				if (MM < 3)
					vec[i].resize(3);
			}
			
		}
		else {
		
			vector<vector<int>> tmp_vec;
			int MM = -1;
			for (int cc = 0;cc < col_size;cc++) {
				m.clear();
				for (int rr = 0;rr < row_size;rr++) {
					if (vec[rr][cc] == 0)
						continue;
					m[vec[rr][cc]]++;
				}
				vector<pi> map_vec = sort_map();
				vector<int> new_vec;
				for (auto xx : map_vec) {
					new_vec.push_back(xx.first);
					new_vec.push_back(xx.second);
				}
				MM = max(MM, (int)new_vec.size());
				
				tmp_vec.push_back(new_vec);
			}
			for (int i = 0;i < col_size;i++) {
				if (tmp_vec[i].size() > 100)
					tmp_vec[i].resize(100);
				else if (tmp_vec[i].size() < MM) {
					tmp_vec[i].resize(MM);
				}
				if (MM < 3)
					tmp_vec[i].resize(3);
			}
			
			transpose(tmp_vec);	
			vec = tmp_vec;	//임시 배열을 사용했다면 본 배열로 복사하는 걸 잊지 말자!
		}
	}
	cout << t;

	return 0;
}