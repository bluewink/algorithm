/*
	boj 17822 원판돌리기 -> 브루트포스, 시뮬레이션.

	1. rotate를 swap을 이용해 구현할 수 있다.
	2. 지워지는 걸 0으로 만들고, 예외처리를 안해줘서 생기는 문제들이 있었다.
	-> 지워지는 애들은 무시한다는 것 주의, 혹은 다른 변수로 관리하자
	3. if, else if 분기 처리를 안했더니 원하는대로 동작하지 않음.
	4. 문제를 잘 읽자. 22/6 =3 으로 지레짐작해서 해맸다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int board_num, score_num, test_num;
vector<vector<int>> vec;

int filter(vector<vector<int>>& target) {
	int check[51][51];
	int flag = 0;
	memset(check, 0, sizeof(check));

	for (int i = 0;i < board_num;i++) {
		for (int j = 0;j < score_num;j++) {
			if (target[i][j] == 0)
				continue;

			if (i < board_num - 1) {	//층별 조사
				if (target[i][j] == target[i + 1][j]) {
					check[i][j] = check[i + 1][j] = 1;
				}
			}

			if (j == score_num - 1) {	//같은 원판 내 조사
				if (target[i][j] == target[i][0]) {
					check[i][j] = check[i][0] = 1;
				}
			}
			else  {
				if (target[i][j] == target[i][j + 1])
					check[i][j] = check[i][j + 1] = 1;
			}

		}
	}
	
	//int sum = 0;
	for (int i = 0;i < board_num;i++) {
		for (int j = 0;j < score_num;j++) {
			if (check[i][j]) {
				target[i][j] = 0;
				flag = 1;
				//cout << "delete!!"<<endl;
			}
			
			//sum += target[i][j];
		}
	}
	
	if (!flag)	//지워진게 없으면
		return 1;

	return -1;
}

void my_rotate(vector<int>& target, int dir, int cnt) {
	//dir 0 : 시계방향, 1: 반시계
	//1 2 3 4 -> 4 1 2 3
	for (int i = 0;i < cnt;i++) {
		if (!dir) {
			//시계
			for (int j = target.size()-1;j >=1 ;j--) {
				//swap을 이용해 바꾸기
				swap(target[j], target[j - 1]);
			}
		}
		else{
			//반시계 1 2 3 4 -> 2 3 4 1
			for (int j = 0;j < target.size()-1;j++) {
				swap(target[j], target[j + 1]);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> board_num >> score_num >> test_num;
	int in;
	for (int i = 0;i < board_num;i++) {
		vector<int> tmp;
		for (int j = 0;j < score_num;j++) {
			cin >> in;
			tmp.push_back(in);
		}
		vec.push_back(tmp);
	}
	int target, dir, cnt;
	for (int i = 0;i < test_num;i++) {
		cin >> target >> dir >> cnt;
		for (int j = 0;j < board_num;j++) {
			if ((j+1) % target == 0) {
				//회전
				my_rotate(vec[j], dir, cnt);
			}
		}
		/*
		cout << " after turn " << endl;
		
		for (int m = 0;m < board_num;m++) {
			for (int n = 0;n < score_num;n++) {
				//ans += vec[m][n];
				cout << vec[m][n] << " ";
			}
			cout << endl;
		}
		cout << endl;
		*/

		//인접한 수 지우기
		int res = filter(vec);
		//cout << "res : " << res << endl;
		if (res == 1) {
			//지워진게 없으면
			int num = 0;
			int sum = 0;
			for (int m = 0;m < board_num;m++) {
				for (int n = 0;n < score_num;n++) {
					if (vec[m][n]) {
						num++;
						sum += vec[m][n];
					}
				}
			}
			float avg = (float)sum / (float)num;

			for (int m = 0;m < board_num;m++) {
				for (int n = 0;n < score_num;n++) {
					if (vec[m][n] == 0)
						continue;

					if ((float)vec[m][n]>avg) {
						vec[m][n] -= 1;
					}
					else if((float)vec[m][n]<avg) {
						vec[m][n] += 1;
					}
				}
			}
			/*
			cout << " after avg " << endl;
			cout << "avg " << avg << "sum " << sum << "num "<< num <<endl;
			
			for (int m = 0;m < board_num;m++) {
				for (int n = 0;n < score_num;n++) {
					//ans += vec[m][n];
					cout << vec[m][n] << " ";
				}
				cout << endl;
			}
			cout << endl;
			*/
			
		}

	}
	int ans = 0;


	for (int m = 0;m < board_num;m++) {
		for (int n = 0;n < score_num;n++) {
			ans += vec[m][n];
			//cout << vec[m][n] << " ";
		}
		//cout << endl;
	}
	cout << ans;


	return 0;
}