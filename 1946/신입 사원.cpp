#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
//vector<vector<pair<int,int>>>newRecruits;

vector<int>answer;
//vector<pair<int, int>> temp;

int main() {
	cin >> N;
	int num;
	int front, back;
	int count = 1;
	vector<pair<int, int>> recruits;
	for (int i = 0; i < N; i++) {
		cin >> num;
		recruits.resize(num);
		for (int j = 0; j < num; j++) {
			cin >> recruits[j].first >> recruits[j].second;
		}
		sort(recruits.begin(), recruits.end());

		back = recruits[0].second;
		for (int j = 1; j < recruits.size(); j++) {
			if (recruits[j].second < back) {
				count++;
				back = recruits[j].second;
			}
		}
		cout << count;
		answer.push_back(count);
		count = 1;
		recruits.clear();
	}
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}

	/*
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < newRecruits[i].size(); j++) {
			cout << newRecruits[i][j].first << " " << newRecruits[i][j].second <<endl;
		}
		cout << endl;
	}
	*/
}
/*
1
6
1 6
5 1
3 4
4 3
2 2
6 5

1 6		5 1
2 2		2 2
3 4		4 3
4 3		3 4
5 1		6 5
6 5		1 6
(1,6)(5,1)(2,2) : 3

1
7
1 4
4 2
6 1
2 5
3 6
7 3
5 7

1 4		6 1
2 5		4 2
3 6		7 3
4 2		1 4
5 7		2 5
6 1		3 6
7 3		5 7
*/