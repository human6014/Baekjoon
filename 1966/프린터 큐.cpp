#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int T;
queue <pair<int,int>> documents;
priority_queue<int> value;
vector<int> answers;
int main() {
	cin >> T;

	int size, target, num;
	int answer = 0;
	int tempValue, tempIndex;
	for (int i = 0; i < T; i++) {
		cin >> size >> target;

		for (int j = 0; j < size; j++) {
			cin >> num;
			documents.push({ num, j });
			value.push(num);
		}
		
		while (!documents.empty()) {
			tempValue = documents.front().first;
			tempIndex = documents.front().second;
			documents.pop();
			if (value.top() == tempValue) {
				answer++;
				if (tempIndex == target) {
					break;
				}
				value.pop();
			}
			else {
				documents.push({ tempValue, tempIndex });
			}
		}
		answers.push_back(answer);
		answer = 0;
		documents = queue<pair<int, int>>();
		value = priority_queue<int>();
	}
	for (int i = 0; i < answers.size(); i++) {
		cout << answers[i] << "\n";
	}
}