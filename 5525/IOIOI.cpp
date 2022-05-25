#include <iostream>
#include <string>
using namespace std;

int N, M;
string S;
/*
int main() {
	cin >> N;
	cin >> M;
	cin >> S;
	string ioi ="I";

	for (int i = 0; i < 2 * N; i+=2) {
		ioi += "OI";
	}

	int answer = 0;
	for (int i = 0; i < S.length() - (2*N); i++) {
		if (S[i] == 'I') {
			string temp = S.substr(i, 2*N+1);
			//cout << temp <<"\n";
			if (temp == ioi) {
				answer++;
				i++;
			}
		}
	}
	cout << answer;
}
*/
int main() {
	cin >> N;
	cin >> M;
	cin >> S;

	int answer = 0;
	int n;
	for (int i = 0; i < S.length() - (2 * N); i++) {
		if (S[i] == 'I') {
			n = 0;
			while (S[i + 1] == 'O' && S[i + 2] == 'I') {
				i += 2;
				n++;
				if (N == n) {
					answer++;
					n--;
				}
			}
		}
	}
	cout << answer;
}