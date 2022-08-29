#include <iostream>
#include <cstring>
using namespace std;

string mainString, boomString, answer;
int main() {
	cin >> mainString >> boomString;
	char lastChar = boomString[boomString.length() - 1];
	/*
	for (int i = boomString.length() - 1; i < mainString.length(); i++) {
		if (mainString[i] == lastChar) {
			for (int j = 1; j < boomString.length(); j++) {
				if (mainString[i - j] != boomString[boomString.length() - j - 1]) break;
				if (j == boomString.length() - 1) {
					mainString.erase(i - boomString.length() + 1, boomString.length());
					i -= boomString.length();
				}
			}
		}
	}
	if (mainString.length() > 0)cout << mainString;
	else cout << "FRULA";
	*/

	for (int i = 0; i < mainString.length(); i++) {
		answer += mainString[i];
		if (mainString[i] == lastChar && answer.length() >= boomString.length()) {
			for (int j = 0; j < boomString.length(); j++) {
				if (answer[answer.length() - boomString.length() + j] != boomString[j])break;
				if (j == boomString.length() - 1) {
					for (int k = 0; k < boomString.length(); k++) {
						answer.pop_back();
					}
				}
			}
		}
	}
	if (answer.length() > 0)cout << answer;
	else cout << "FRULA";
}