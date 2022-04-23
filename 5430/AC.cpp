#include <iostream>
#include <string>
#include <algorithm>
#include <deque>
using namespace std;

int N;
string answer[100];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	string command;
	int size;
	string contents;

	deque<int> numbers;
	string tempNum;

	bool flag = false;
	bool isReversed = false;
	for (int i = 0; i < N; i++) {
		cin >> command;
		cin >> size;
		cin >> contents;

		tempNum = "";
		for (int j = 1; j < contents.size() - 1; j++) {
			if (contents[j] == ',') {
				numbers.push_back(stoi(tempNum));
				tempNum = "";
			}
			else {
				tempNum += contents[j];
				if (j == contents.size() - 2) {
					numbers.push_back(stoi(tempNum));
					break;
				}
			}
		}
		/*
		for (int j = 0; j < numbers.size(); j++) {
			cout << numbers[j] << " ";
		}
		cout << "\n";
		*/

		for (int j = 0; j < command.size(); j++) {
			if (command[j] == 'R') isReversed = !isReversed;
			else if (command[j] == 'D') {
				if (numbers.size() <= 0) {
					flag = true;
					break;
				}
				if (isReversed) numbers.erase(numbers.end() - 1);
				else numbers.erase(numbers.begin());
			}
		}

		if (flag) answer[i] = "error";
		else {
			if(isReversed) reverse(numbers.begin(), numbers.end());
			answer[i] += '[';
			for (int j = 0; j < numbers.size(); j++) {
				answer[i] += to_string(numbers[j]);
				if(j!=numbers.size() - 1) answer[i] += ',';
			}
			answer[i] += ']';
		}

		numbers.clear();
		flag = false;
		isReversed = false;
	}
	for (int i = 0; i < N; i++) {
		cout << answer[i] <<"\n";
	}

}