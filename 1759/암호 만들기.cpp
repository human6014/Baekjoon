#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, C;
char comb[16];
char alphabet[16];
void Combination(int depth,int index) {
	if (depth == L) {
		string answer = "";
		int consonant = 0;
		int vowel = 0;
		for (int i = 0; i < L; i++) {
			answer += comb[i];
			if (comb[i] == 'a' || comb[i] == 'e' || comb[i] == 'i' || comb[i] == 'o' || comb[i] == 'u')  vowel++;
			else consonant++;
		}
		if (vowel >= 1 && consonant >= 2)cout << answer << "\n";
		return;
	}

	for (int i = index; i < C; i++) {
		comb[depth] = alphabet[i];
		Combination(depth + 1, i + 1);
	}
}
int main() {
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> alphabet[i];
	}
	sort(alphabet, alphabet + C);
	/*
	for (int i = 0; i < C; i++) {
		cout << alphabet[i] << " ";
	}
	cout << "\n";
	*/
	Combination(0, 0);
}