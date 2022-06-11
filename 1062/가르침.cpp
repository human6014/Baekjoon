#include <iostream>
#include <vector>
using namespace std;

bool alphabet[26];
int N, K;
int answer=0;
vector<string>text;
void Combination(int index, int length) {
	if (length == K) {

		int count = 0;
		bool flag;
		for (int i = 0; i < text.size(); i++) {
			flag = false;
			for (int j = 4; j < text[i].size() - 4; j++) {
				if (!alphabet[text[i][j] - 'a']) {
					flag = true;
					break;
				}
			}
			if (!flag) count++;
		}
		answer = max(answer, count);
		

		/*
		for (int i = 0; i < 26; i++) {
			if(alphabet[i])cout << char(i + 97) << " ";
		}
		cout << "\n";
		*/
		return;
	}
	for (int i = index; i < 26; i++) {
		if (alphabet[i])continue;
		alphabet[i] = true;
		Combination(i + 1, length + 1);
		alphabet[i] = false;
	}
}
int main() {
	cin >> N >> K;
	text.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> text[i];
	}
	alphabet[0] = true;
	alphabet[2] = true;
	alphabet[8] = true;
	alphabet[13] = true;
	alphabet[19] = true;
	K -= 5;
	Combination(0,0);
	cout << answer;
}
/*
a,c,i,n,t 

0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
a b c d e f g h i j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z
*/