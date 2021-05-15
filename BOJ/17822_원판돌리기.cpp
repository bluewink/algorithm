/*
	boj 17822 ���ǵ����� -> ���Ʈ����, �ùķ��̼�.

	1. rotate�� swap�� �̿��� ������ �� �ִ�.
	2. �������� �� 0���� �����, ����ó���� �����༭ ����� �������� �־���.
	-> �������� �ֵ��� �����Ѵٴ� �� ����, Ȥ�� �ٸ� ������ ��������
	3. if, else if �б� ó���� ���ߴ��� ���ϴ´�� �������� ����.
	4. ������ �� ����. 22/6 =3 ���� ���������ؼ� �ظ̴�.
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

			if (i < board_num - 1) {	//���� ����
				if (target[i][j] == target[i + 1][j]) {
					check[i][j] = check[i + 1][j] = 1;
				}
			}

			if (j == score_num - 1) {	//���� ���� �� ����
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
	
	if (!flag)	//�������� ������
		return 1;

	return -1;
}

void my_rotate(vector<int>& target, int dir, int cnt) {
	//dir 0 : �ð����, 1: �ݽð�
	//1 2 3 4 -> 4 1 2 3
	for (int i = 0;i < cnt;i++) {
		if (!dir) {
			//�ð�
			for (int j = target.size()-1;j >=1 ;j--) {
				//swap�� �̿��� �ٲٱ�
				swap(target[j], target[j - 1]);
			}
		}
		else{
			//�ݽð� 1 2 3 4 -> 2 3 4 1
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
				//ȸ��
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

		//������ �� �����
		int res = filter(vec);
		//cout << "res : " << res << endl;
		if (res == 1) {
			//�������� ������
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