#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> num;
bool IndexSort(pair<int,int>begin,pair<int,int>end) {
	if (begin.second > end.second)return false;
	return true;
}
int main() {
	cin >> N;
	num.resize(N);
	int value;
	for (int i = 0; i < N; i++) {
		cin >> value;
		num[i] = { value,i };
	}

	sort(num.begin(), num.end());

	int front = num[0].first;
	num[0].first = 0;
	int count = 0;
	for (int i = 1; i < N; i++) {
		if (num[i].first != front) count++;
		front = num[i].first;
		num[i].first = count;
	}

	sort(num.begin(), num.end(), IndexSort);
	
	for (int i = 0; i < N; i++) {
		cout << num[i].first << " ";
	}
	
}