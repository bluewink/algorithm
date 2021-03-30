/*
	부분합
	-> 투포인터
	
	시행착오
	반례를 찾지 못했다.
	맨 끝에서 조건을 만족하는 경우를 놓쳤다.
	반례를 찾을 때는 맨 처음과 맨 끝, 동일한 숫자로 이루어진 경우 등 엣지 케이스를 고려해보자.

	+ 고려사항
	탐색 종료조건을 따지는 게 까다로웠다.
	이 문제 같은 경우 sum < k && right == end일 때 탐색을 종료하면 된다.

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> vec;
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int left, right,sum, n, k,in;
	cin >> n >> k;
	for (int i = 0;i < n;i++) {
		cin >> in;
		vec.push_back(in);
	}
	left = right = 0;
	sum = vec[left];
	int mm = 987654321;
	int vec_len = vec.size();
	while (1) {
		if (right == vec_len - 1 && left == vec_len - 1) {
			if (sum >= k)
				mm = min(mm, right - left + 1);
			break;
		}
		if (sum >= k) {
			mm = min(mm, right - left + 1);
			if (mm == 1) {
				break;
			}
			if (left < right) {
				sum -= vec[left];
				left++;
			}
			else {
				right++;
				sum += vec[right];
			}
		}
		else {
			//sum < k
			if (right < vec_len - 1) {
				right++;
				sum += vec[right];
			}
			else {
				sum -= vec[left];
				left++;
			}
		}
	}
	if (mm == 987654321)
		cout << 0;
	else
		cout << mm;
	return 0;
}