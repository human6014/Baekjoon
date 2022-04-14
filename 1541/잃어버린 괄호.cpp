#include <iostream>
#include <string>
using namespace std;

int Calc(bool isMinus, int answer, string integer) {
	if (isMinus)return answer - stoi(integer);
	return answer + stoi(integer);
}
int main() {
	string text;
	string integer;
	int answer = 0;
	bool isMinus = false;
	cin >> text;
	for (int i = 0; i < text.length(); i++) {
		if (text[i] == '-') {
			answer = Calc(isMinus, answer, integer);
			isMinus = true;
			integer = "";
		}
		else if (text[i] == '+') {
			answer = Calc(isMinus, answer, integer);
			integer = "";
		}
		else {
			integer += text[i];
		}
		if (i == text.length() - 1) {
			answer = Calc(isMinus, answer, integer);
		}
	}
	cout << answer;
}
// 0+50-40-25+40-125
// = -185