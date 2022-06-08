#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

int N, K;
unordered_set<int> usingElectronic;
vector<int> electronic;
int main() {
	int answer = 0;
	cin >> N >> K;
	electronic.resize(K);

	int n;
	for (int i = 0; i < K; i++) {
		cin >> electronic[i];
	}

	for (int i = 0; i < K; i++) {
		if (usingElectronic.size() < N) {
			usingElectronic.insert(electronic[i]);
			continue;
		}
		if (usingElectronic.find(electronic[i]) != usingElectronic.end()) continue;
		else {
			int index = -1;
			int max = -1;
			int count;
			for (auto it : usingElectronic) {
				count = 0;
				for (int j = i + 1; j < K; j++) {
					if (it == electronic[j]) break;
					count++;
				}
				if (max < count) {
					max = count;
					index = it;
				}
			}
			usingElectronic.erase(index);
			usingElectronic.insert(electronic[i]);
			answer++;
		}

	}
	cout << answer;
}
/*
 3 14
1 4 3 2 5 4 3 2 5 3 4 2 3 4
 = 4

 2 15
3 2 1 2 1 2 1 2 1 3 3 3 3 3 3
 = 2

 3 6
1 1 1 1 2 3
 = 0
*/