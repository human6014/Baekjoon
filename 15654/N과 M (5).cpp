#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<pair<int, bool>>num;
vector<int> per; 
void Permutation(int depth) {
	if (depth == M) {
		for (int i = 0; i < per.size(); i++) { 
			cout << per[i] << " "; 
		}
		cout << "\n";
		return; 
	} 
	for (int i = 0; i < num.size(); i++) {
		if (!num[i].second) {
			num[i].second = true;
			per[depth] = num[i].first;
			Permutation(depth + 1);
			num[i].second = false; 
		}
	} 
} int main() {
	cin >> N >> M;
	num.resize(N); 
	per.resize(M); 
	for (int i = 0; i < N; i++) { 
		cin >> num[i].first; 
	} 
	sort(num.begin(), num.end()); 
	Permutation(0); 
}
