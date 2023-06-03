#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
string answer;
char number[3] = { '1','2','3' };

bool isValid(string current) {
	string backCompare;
	string frontCompare;
	for (int i = 0; i < current.length() / 2; i++) {
		backCompare = current.substr(current.length() - 1 - i, i + 1);
		frontCompare = current.substr(current.length() - i * 2 - 2, i + 1);

		if (backCompare == frontCompare) return false;
	}
	return true;
}

void DFS(int n, string current) {
	if (answer != "") return;
	if (!isValid(current))
		return;

	if (n == N) {
		answer = current;
		return;
	}
	for (int i = 0; i < 3; i++) {
		current.push_back(number[i]);
		DFS(n + 1, current);
		current.pop_back();
	}
}
int main() {
	cin >> N;
	DFS(0, "");
	cout << answer;
}
/*
7
1213121

8
12131231

12131213

1
2				3
1		3		1		2
3		1	2	2	 	1	3
*/