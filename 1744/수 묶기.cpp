#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

bool sorting(int first,int second) {
	//cout << first << " " << second <<endl;
	if (first == 0)return false;
	if (second == 0)return true;
	if (first < 0 && second < 0) {
		if (first >= second) return false;
		return true;
	}
	else {
		if (first > second)return true;
		return false;
	}
}
int main() {
	cin >> N;
	int answer = 0;
	vector<int> numbers;
	numbers.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> numbers[i];
	}

	sort(numbers.begin(), numbers.end(),sorting);
	/*
	cout << endl;
	for (int i = 0; i < N; i++) {
		cout << numbers[i] << "\n";
	}
	cout << endl;
	*/
	for (int i = 0; i < N; i++) {
		if ((i + 1 < N) &&(numbers[i] * numbers[i + 1] > numbers[i] + numbers[i + 1]) ) {
			answer += numbers[i] * numbers[i + 1];
			++i;
		}
		else answer += numbers[i];
		
	}
	cout << answer;
	
}
/*

3
-5
-2
-3


8
1
1
1
1
1
1
-1
-1

5
0
-1
-1
0
5
	:6

10
9
-4
0
-4
-5
2
17
0
-1
4
	:185
*/