#include <iostream>

using namespace std;
const int TARGET = 1;
int dp[1000001];

int DP(int N) {
	if (N == 1) return 0;
	if (dp[N] != 0)return dp[N];

	dp[N] = DP(N - 1) + 1;
	if (N % 3 == 0) dp[N] = min(DP(N / 3) + 1, dp[N]);
	if (N % 2 == 0) dp[N] = min(DP(N / 2) + 1, dp[N]);

	return dp[N];
}

int main() {
	int N;
	cin >> N;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	cout << DP(N);
}

/*
250

정답: 8 (250 -> 249 -> 83 -> 82 -> 81 -> 27 -> 9 -> 3 -> 1)
출력: 9


251

정답: 9 (251 -> 250 -> 249 -> 83 -> 82 -> 81 -> 27 -> 9 -> 3 -> 1)
출력: 10

*/