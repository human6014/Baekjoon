#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int N;
int testNum;
vector<char> naturalNumber;
void DFS(int nowNum, int sum) {
	if (nowNum == testNum + 1) {
		if (sum == 0) {
			for (int i = 1; i < naturalNumber.size(); i++) {
				cout << i << naturalNumber[i];
			}
			cout << testNum << "\n";
		}
		return;
	}

	naturalNumber[nowNum - 1] = ' ';
	if (naturalNumber[nowNum - 2] == '+') DFS(nowNum + 1, (sum - (nowNum - 1)) + ((nowNum - 1) * 10 + nowNum));
	else if (naturalNumber[nowNum - 2] == '-') DFS(nowNum + 1, (sum + (nowNum - 1)) - ((nowNum - 1) * 10 + nowNum));
	else if (naturalNumber[nowNum - 2] != ' ') DFS(nowNum + 1, (nowNum - 1) * 10 + nowNum);

	naturalNumber[nowNum - 1] = '+';
	DFS(nowNum + 1, sum + nowNum);

	naturalNumber[nowNum - 1] = '-';
	DFS(nowNum + 1, sum - nowNum);
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> testNum;
		naturalNumber.resize(testNum);
		DFS(2, 1);
		cout << "\n";
		naturalNumber.clear();
	}
}
/*
1 2 3 4 5 + 6 7

1
7
=
1+2-3+4-5-6+7
1+2-3-4+5+6-7
1-2 3+4+5+6+7
1-2 3-4 5+6 7
1-2+3+4-5+6-7
1-2-3-4-5+6+7

1-2 3-4 5+6 7
1
-1
-22
-26
-67
0


1
8
=
1 2-3 4-5 6+7 8
1+2 3-4 5+6+7+8
1+2+3+4-5-6-7+8
1+2+3-4+5-6+7-8
1+2-3+4+5+6-7-8
1+2-3-4-5-6+7+8
1-2 3-4+5+6+7+8
1-2+3-4-5+6-7+8
1-2-3+4+5-6-7+8
1-2-3+4-5+6+7-8

1
9
=
1 2+3 4-5 6-7+8+9
1 2+3+4-5-6-7+8-9
1 2+3-4 5+6+7+8+9
1 2+3-4+5-6+7-8-9
1 2-3+4+5 6-7 8+9
1 2-3+4+5+6-7-8-9
1 2-3-4-5+6-7-8+9
1 2-3-4-5-6+7+8-9
1+2-3 4-5 6+7 8+9
1-2 3-4-5 6-7+8 9
1-2-3 4+5+6+7+8+9
*/

