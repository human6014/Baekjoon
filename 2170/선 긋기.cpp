#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct compare {
	bool operator()(pair<int,int> a, pair<int,int> b) {
		return a.second < b.second;
	}
};
int N;
vector<pair<int, int>> line;
priority_queue<pair<int, int>,vector<pair<int,int>>, compare> nonDupleLine;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int answer = 0;
	cin >> N;
	line.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> line[i].first >> line[i].second;
	}

	sort(line.begin(), line.end());

	int start, end;
	nonDupleLine.push({line[0].first, line[0].second});
	for (int i = 1; i < N; i++) {
		if (nonDupleLine.top().second >= line[i].first) {
			start = nonDupleLine.top().first;
			end = nonDupleLine.top().second;
			nonDupleLine.pop();

			nonDupleLine.push({start,max(end,line[i].second)});
		}
		else nonDupleLine.push({line[i].first,line[i].second});
	}

	while (!nonDupleLine.empty()) {
		start = nonDupleLine.top().first;
		end = nonDupleLine.top().second;
		answer += end - start;
		nonDupleLine.pop();
	}
	cout << answer;
}
/*
4
1 3
2 5
3 5
6 7
= 5

1 2 3
  2 3 4 5
	3 4 5
		  6 7

5
-5 -2
-3 0
2 5
6 10
8 12
= 14

5
1 2
9 10
4 7
6 9
2 5
= 9

4
5 10
15 20
25 30
7 35
= 30
*/