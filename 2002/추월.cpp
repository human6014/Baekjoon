#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int N;
unordered_map<string, int> in;
int main() {
	int answer = 0;
	cin >> N;
	string car;
	for (int i = 0; i < N; i++) {
		cin >> car;
		in.insert({ car,i });
	}

	vector<pair<string, int>> out(N);
	for (int i = 0; i < N; i++) {
		cin >> out[i].first;
		out[i].second = in[out[i].first];
	}

	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (out[i].second > out[j].second) {
				answer++;
				break;
			}
		}
	}
	cout << answer;
}
/*
6
1 2 3 4 5 6
2 4 3 1 6 5
 = 4

4
a b c d
d a c b
 = 2
*/