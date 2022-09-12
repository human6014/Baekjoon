#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, answer;
int main() {
	cin >> N;
	vector<int> crain(N);
	for (int i = 0; i < N; i++) cin >> crain[i];
	
	cin >> M;
	vector<int> boxes(M);
	for (int i = 0; i < M; i++) cin >> boxes[i];
	
	sort(crain.begin(), crain.end(), greater<>());
	sort(boxes.begin(), boxes.end(), greater<>());

	if (crain[0] < boxes[0]) {
		cout << -1;
		return 0;
	}
	while (!boxes.empty()) {
		for (int i = 0; i < crain.size(); i++) {
			for (int j = 0; j < boxes.size(); j++) {
				if (crain[i] >= boxes[j]) {
					boxes.erase(boxes.begin() + j);
					break;
				}
			}
			if (boxes.empty()) break;
		}
		answer++;
	}

	cout << answer;
}