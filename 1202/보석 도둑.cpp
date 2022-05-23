/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, K;
vector<pair<int, int>> jewelry;
priority_queue<int, vector<int>, greater<int>> bag;
bool sorting(pair<int, int> start, pair<int, int> end) {
	if (start.first = end.first) return start.second > end.second;
	return start.first > end.first;
}
int main() {
	cin >> N >> K;
	int answer = 0;
	int weight, value, bagWeight;
	for (int i = 0; i < N; i++) {
		cin >> weight >> value;
		jewelry.push_back({ weight, value });
	}
	sort(jewelry.begin(), jewelry.end());
	for (int i = 0; i < K; i++) {
		cin >> bagWeight;
		bag.push(bagWeight);
	}

	
	int jewelryWeight, jewelryValue, bagFrontWeight;
	int maxValue, index;
	while (!bag.empty()) {
		index = -1;
		maxValue = 0;
		bagFrontWeight = bag.top();
		for (int i = 0; i < jewelry.size(); i++) {
			if (jewelry[i].first > bagFrontWeight) break;
			if (maxValue < jewelry[i].second) {
				maxValue = jewelry[i].second;
				index = i;
			}
		}
		if (index != -1) jewelry[index].second = 0;
		answer += maxValue;
		bag.pop();
	}
	
	
	cout << "\n";
	for (int i = 0; i < N; i++) {
		cout << jewelry[i].first << " " << jewelry[i].second << "\n";
	}
	while (!bag.empty()) {
		cout << bag.top() << "\n";
		bag.pop();
	}
	
	cout << answer;
}
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, K;
vector<pair<int, int>> jewelry;
vector<int> bag;
priority_queue<int> pq;
int main() {
	cin >> N >> K;
	jewelry.resize(N);
	bag.resize(K);
	for (int i = 0; i < N; i++) {
		cin >> jewelry[i].first >> jewelry[i].second;
	}
	for (int i = 0; i < K; i++) {
		cin >> bag[i];
	}
	sort(jewelry.begin(), jewelry.end());
	sort(bag.begin(), bag.end());

	long long answer = 0;
	int index = 0;
	for (int i = 0; i < bag.size(); i++) {
		while (index < jewelry.size() && bag[i] >= jewelry[index].first) {
			pq.push(jewelry[index].second);
			index++;
		}
		if (!pq.empty()) {
			answer += pq.top();
			pq.pop();
		}
	}

	/*
	cout << "\n";
	for (int i = 0; i < N; i++) {
		cout << jewelry[i].first << " " << jewelry[i].second << "\n";
	}
	while (!bag.empty()) {
		cout << bag.top() << "\n";
		bag.pop();
	}
	*/
	cout << answer;
}
/*
4 2
4 100
5 110
6 90
7 80
5
7
 = 210

3 2
1 10
2 5
2 7
1
3
 = 17

5 2
1 28
2 5
2 7
3 15
1 5
1
3
 = 43
*/