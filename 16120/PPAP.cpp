#include <iostream>
#include <stack>
using namespace std;

string text;
stack<char> s;
int main() {
	cin >> text;

	int count = 0;
	bool isPPA = false;

	for (int i = 0; i < text.length(); i++) {
		s.push(text[i]);

		if (s.top() == 'P') {
			if (isPPA) {
				for (int i = 0; i < 3; i++) s.pop();
				count -= 1;
				isPPA = false;
			}
			else count++;
		}
		else {
			if (count >= 2) isPPA = true;
		}
	}

	if (s.size() == 1 && s.top() == 'P') cout << "PPAP";
	else cout << "NP";
}

/*

PPPP�� NP


PPPAPAP
P��	P
P��	PP
P��	PPP
A��	PPPA
P�� PPPAP	-> PPAP�ϼ�		-> PP
A�� PPA
P�� PPAP	-> PPAP�ϼ�		-> P

*/