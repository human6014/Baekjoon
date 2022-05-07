#include <iostream>
#include <stack>
using namespace std;

int main() {
	string str;
	int answer = 0;
	cin >> str;

	stack<char> brakets;
	int small = 1, big = 1;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			small *= 2;
			brakets.push(str[i]);
		}
		else if (str[i] == '[') {
			big *= 3;
			brakets.push(str[i]);
		}
		else if (str[i] == ')') {
			if (brakets.empty() || brakets.top() != '(') { answer = 0; break; }
			if (str[i - 1] == '(') answer += small * big;

			small /= 2;
			brakets.pop();
		}
		else if (str[i] == ']') {
			if (brakets.empty() || brakets.top() != '[') { answer = 0; break; }
			if (str[i - 1] == '[') answer += small * big;

			big /= 3;
			brakets.pop();
		}
		else {
			answer = 0;
			break;
		}
	}
	if (!brakets.empty()) answer = 0;
	std::cout << answer;
}