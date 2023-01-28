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

PPPP는 NP


PPPAPAP
P들어감	P
P들어감	PP
P들어감	PPP
A들어감	PPPA
P들어감 PPPAP	-> PPAP완성		-> PP
A들어감 PPA
P들어감 PPAP	-> PPAP완성		-> P

*/