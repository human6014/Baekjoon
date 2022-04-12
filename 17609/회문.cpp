#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int T;
string palindrome[30];
int answer,half;
int main() {
	cin.tie(NULL);
	string temp, first, second;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> palindrome[i];
	}
	for (int i = 0; i < T; i++) {
		answer = 2;
		temp = palindrome[i];
		reverse(palindrome[i].begin(), palindrome[i].end());
		if (palindrome[i] == temp) answer = 0;
		else {
			half = ceil(temp.length() / 2);
			for (int j = 0; j <= half; j++) {
				if (temp[j] == palindrome[i][j]) continue;
				first = temp;
				second = palindrome[i];
				first.erase(j, 1);
				second.erase(second.length() - j - 1, 1);
				if (first == second || temp.erase(temp.length() - j - 1, 1) == palindrome[i].erase(j, 1)) answer = 1;
				break;
			}
		}
		cout << answer <<"\n";
	}
}