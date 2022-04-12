#include <iostream>
using namespace std;

int N, KimJiMin, ImHanSoo, answer;
bool isOdd(int n) {
	if (n % 2 == 0)return false;
	return true;
}
int main() {
	cin >> N >> KimJiMin >> ImHanSoo;
	int smaller, bigger;
	while (true) {
		smaller = min(KimJiMin, ImHanSoo);
		bigger = max(KimJiMin, ImHanSoo);
		if (isOdd(smaller) && smaller + 1 == bigger) break;

		N = isOdd(N) ? (N + 1) / 2 : N / 2;
		KimJiMin = isOdd(KimJiMin) ? (KimJiMin + 1) / 2 : KimJiMin / 2;
		ImHanSoo = isOdd(ImHanSoo) ? (ImHanSoo + 1) / 2 : ImHanSoo / 2;
		answer++;
	}
	cout << answer + 1;
}

//16	8	9
//8		4	5
//4		2	3
//2		1	2