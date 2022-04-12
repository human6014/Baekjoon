#include <iostream>
#include <string>
using namespace std;

int main() {
	string text;
	int stack, num;
	cin >> num;
	for (int j = 0; j < num; j++) {
		stack = 0;
		cin >> text;
		for (int i = 0; i <= text.length(); i++) {
			if (stack < 0) {
				cout << "NO\n";
				break;
			}
			if (stack == 0 && i == text.length()) {
				cout << "YES\n";
			}
			else if (stack != 0 && i == text.length()) {
				cout << "NO\n";
			}
			if (text[i] == '(') {
				stack++;
			}
			else if (text[i] == ')') {
				stack--;
			}
		}
	}
}