#include <iostream>
#include <vector>
using namespace std;

int N,M;
int numArray[1025][1025];
vector<int>answers;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;

	int num;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> num;
			numArray[i][j] = numArray[i][j - 1] + num;
		}
	}
	int x1, y1, x2, y2;
	//X : 青	Y : 凯
	int answer = 0;
	for (int i = 0; i < M; i++) {
		cin >> x1 >> y1 >> x2 >> y2;

		for (int j = x1; j <= x2; j++) {
			answer += numArray[j][y2] - numArray[j][y1 - 1];
		}
		
		answers.push_back(answer);
		answer = 0;
	}
	for (auto i : answers) {
		cout << i <<"\n";
	}
	
	/*
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << numArray[i][j] - numArray[i][j - 1] << " ";
		}
		cout << "\n";
	}
	*/
	
}
/*
4 3
1 2 3 4
2 3 4 5
3 4 5 6
4 5 6 7

2 2 3 4
3 4 3 4
1 1 4 4

2青 2凯 + 3青 4凯	27	: 3 + 4 + 5  + 4 + 5 + 6
3青 4凯 + 3青 4凯	6	: 6
1青 1凯 + 4青 4凯	64	: 1 + 2 + 3 + 4 + 2 + 3 + 4 + 5 + 3 + 4 + 5 + 6 + 4 + 5 + 6 + 7

*/