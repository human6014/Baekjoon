#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector <int> comb;
void ReCombination(int length,int index) {
	if (length == M) {
		for (int i = 0; i < comb.size(); i++) {
			cout << comb[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = index; i <= N; i++) {
		comb[length] = i;
		ReCombination(length + 1, i);
	}
}
int main() {
	cin >> N >> M;
	comb.resize(M);
	ReCombination(0,1);
}