#include <iostream>
using namespace std;

int N, A[101], Operator[4];
int MAX = -1000000001;
int MIN = 1000000001;
void Operating(int answer, int now,int plus,int minus,int multi,int div) {
	if (now == N) {
		if (answer > MAX)MAX = answer;
		if (answer < MIN)MIN = answer;
		return;
	}
	else {
		if (plus > 0) {
			Operating(answer + A[now + 1], now + 1,plus-1,minus,multi,div);
		}
		if (minus > 0) {
			Operating(answer - A[now + 1], now + 1,plus,minus-1,multi,div);
		}
		if (multi > 0) {
			Operating(answer * A[now + 1], now + 1,plus,minus,multi-1,div);
		}
		if (div > 0) {
			Operating(answer / A[now + 1], now + 1,plus,minus,multi,div-1);
		}
	}
}
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> Operator[i];
	}
	int start = A[1];
	int now = 1;
	Operating(start,now, Operator[0], Operator[1], Operator[2], Operator[3]);
	cout << MAX << " " << MIN;
}