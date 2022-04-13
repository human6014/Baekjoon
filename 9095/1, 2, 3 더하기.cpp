#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
int T, N[1000001],answer[11];
int DP[1000001];
const int usingNum[3] = { 1, 2, 3 };

void Recursive(int n,int start) {
	if (n < start)return;
	if (n == start) {
		answer[n]++;
		return;
	}
	for (int i = 0; i < 3; i++) {

		Recursive(n, start + usingNum[i]);
	}
}
int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N[i];
	}
	int start = 0;
	for (int i = 0; i < T; i++) {
		Recursive(N[i],start);
		cout << answer[N[i]] <<"\n";
	}
}
*/
int T, answerCase[100001];
vector<int>answers;
int main() {
	cin >> T;
	int num;
	for (int i = 0; i < T; i++) {
		cin >> num;
		answers.push_back(num);
	}
	answerCase[1] = 1;
	answerCase[2] = 2;
	answerCase[3] = 4;
	for (int i = 4; i <= *max_element(answers.begin(),answers.end()); i++) {
		answerCase[i] = answerCase[i - 1] + answerCase[i - 2] + answerCase[i - 3];
	}
	for (int i = 0; i < T; i++) {
		cout << answerCase[answers[i]] <<"\n";
	}
}