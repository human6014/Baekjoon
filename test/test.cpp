#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;
/*
int N;
vector<int> base;
vector<int> pr;
void Comb(int depth) {
	if (depth == N) {
		for (int i = 0; i < pr.size(); i++) {
			cout << pr[i] <<" ";
		}
		cout << "\n";
		return;
	}
	else {
		pr.push_back(base[depth]);
		Comb(depth + 1);
		pr.pop_back();
		Comb(depth + 1);
	}
}
int main() {
	cin >> N;
	base.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> base[i];
	}
	Comb(0);
}
*/

int vecSize, tempAnswer;
unordered_map<string, int> clotheses;
vector<int> tempVector;
void Combination(int index, int depth) {
	if (depth == vecSize) {
		tempAnswer++;
		return;
	}
	for (auto i : clotheses) {

	}
	return;
}
int solution(vector<vector<string>> clothes) {
	int answer = 0;
	vecSize = clothes.size();
	for (int i = 0; i < clothes.size(); i++) {
		clotheses[clothes[i][1]]++;
	}
	Combination(0, 0);
	return answer;
}
int main() {
	vector<vector<string>>clothese = { {"yellowhat", "headgear"},{"bluesunglasses", "eyewear"},{"green_turban", "headgear"} };
	solution(clothese);
}
