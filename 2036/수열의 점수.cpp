#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
long long answer;
bool compare(int first, int second) {
	if (first <= 0 || second <= 0) return first < second;
	else {
		if (first > second) return true;
		else return false;
	}
}
int main() {
	cin >> N;

	vector<long long> num(N);
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}

	sort(num.begin(), num.end(), compare);
	if (N == 1) answer = num[0];
	for (int i = 1; i < num.size(); i++) {
		if (num[i - 1] < num[i - 1] * num[i]) {
			answer += num[i - 1] * num[i];
			i++;
		}
		else answer += num[i - 1];
		if (i == num.size() - 1)answer += num[i];
	}
	cout << answer;
}
/*
11
-10
9
-8
7
-6
5
-4
3
-1
1
0

-10
-8
-6
-4
-1
0
9
7
5
3
1
 = 183


5
-1
5
-3
5
1

-3
-1
1
5
5

 = 29

4
-4
0
1
1
 = 2
*/
