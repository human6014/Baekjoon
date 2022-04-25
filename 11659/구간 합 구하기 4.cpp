#include <iostream>
#include <vector>
using namespace std;

int N,M;
int cumulativeSum[100001];
vector<int> answers;
int main() {
	cin.tie(NULL);
	cin >> N >> M;
	int number;
	for (int i = 1; i <= N; i++) {
		cin >> number;
		cumulativeSum[i] = cumulativeSum[i - 1] + number;
	}
	int start,end;
	for (int i = 0; i < M; i++) {
		cin >> start >> end;
		answers.push_back(cumulativeSum[end] - cumulativeSum[start - 1]);
	}
	for (auto it : answers) {
		cout << it << "\n";
	}
}