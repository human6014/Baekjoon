#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, L;
vector<pair<int, int>> pallets;
int main() {
	int answer = 0;
	cin >> N >> L;
	pallets.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> pallets[i].first >> pallets[i].second;
	}

	sort(pallets.begin(), pallets.end());

	int j = 0;

	/*
	for (int i = 0; i < pallets[N - 1].second; i++) {
		if (i >= pallets[j].first) {
			i += (L - 1);
			answer++;
		}
		if (i >= pallets[j].second) {
			j++;
		}
	} ¾ÈµÊ
	*/

	/*
	int i = 0;
	while (i < pallets[N - 1].second) {
		if (i >= pallets[j].first) {
			while (i < pallets[j].second) {
				i += L;
				answer++;
			}
			j++;
		}
		else i++;
	} µÇ´Â°Å 408ms
	*/

	for (int i = 0; i < pallets.size(); i++) {
		if (pallets[i].first > j) j = pallets[i].first;
		if (pallets[i].first <= j) {
			while (j < pallets[i].second) {
				j += L;
				answer++;
			}
		}
	}
	//µÇ´Â°Å 172ms

	cout << answer;
}
/*
3 9
0 3
4 6
7 9
=1

MMM.MM.MM // ¿õµ¢ÀÌ
012345678 // ÁÂÇ¥
111111111

3 10
1 5
6 8
9 11

1 3
1 4
=1

1 3
1 3
=1

3 10
0 1
1 2
3 11
=2
*/