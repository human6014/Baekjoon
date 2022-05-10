#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

const int MAX = 100001;

int dp[10001];
int n, target;
set<int> coins;
int main() {
	int answer = -1;
	cin >> n >> target;

	int coin;
	for (int i = 0; i < n; i++) {
		cin >> coin;
		coins.insert(coin);
	}
	for (int i = 1; i <= target; i++) {
		dp[i] = MAX;
	}

	int minValue = 0;
	for (int i = 1; i <= target; i++) {
		for (auto coin : coins) {
			if (i - coin >= 0) {
				minValue = dp[i - coin] + 1;
				dp[i] = min(minValue, dp[i]);
			}
		}
		//cout << "i : "<< i << "\tÃÖ¼Ú°ª : " << dp[i] << "\n";
	}
	if (dp[target] == MAX) cout << -1;
	else cout << dp[target];
}
/*
3 15
1
5
12

1 : 1			1
2 : 1+1			2
3 : 1+1+1		3
4 : 1+1+1+1		4
5 : 5			1
6 : 5+1			2
7 : 5+1+1		3
8 : 5+1+1+1		4
9 : 5+1+1+1+1	5
10: 5+5			2
11: 5+5+1		3
12: 12			1
13 :12+1		2
14 :12+1+1		3
15: 5+5+5		3


3 12
10
4
2
: 2
*/