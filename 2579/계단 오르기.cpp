#include <iostream>
using namespace std;

int N;
int answer[301];
int num[301];
int main() {
	cin >> N;
	/*
	answer[1] = num[1];
	answer[2] = num[1] + num[2];
	int first, second;
	for (int i = 3; i <= N; i++) {
		first = answer[i - 3] + num[i - 2] + num[i];
		second = answer[i - 2] + max(num[i - 1], num[i]);
		answer[i] = max(first, second);
	}
	*/
	for (int i = 1; i <= N; i++) {
		cin >> num[i];
	}
	answer[1] = num[1];
	answer[2] = num[1] + num[2];

	int first, second;
	for (int i = 3; i <= N; i++) {
		first = answer[i - 3] + num[i - 1] + num[i];
		second = answer[i - 2] + num[i];
		answer[i] = max(first, second);
	}

	cout << answer[N];
}
/*
5

1
4
3
1
9
:16

6

123
14
3
2
13
4
:143

6

60
10
61
14
9
7
:142

6

1
2
3
4
5
6
:16

5

100
100
3
2
1
:203
*/