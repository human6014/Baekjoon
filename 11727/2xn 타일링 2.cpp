#include <iostream>
using namespace std;

int N;
int DP[1001];
int main() {
	cin >> N;
	DP[1] = 1;
	DP[2] = 3;
	for (int i = 3; i <= N; i++) {
		DP[i] = (DP[i - 1] + 2 * DP[i - 2])%10007;
	}
	cout << DP[N];
}
/*
1	:	1
2	:	3
3	:	5
4	:	11
5	:	21
6	:	43
7	:	85
8	:	171
9	:
10	:
11	:
12	:	2731
*/