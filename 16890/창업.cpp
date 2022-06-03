#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

string kooosaga;
string cubelover;
string answer;
int main() {
	cin >> kooosaga;
	cin >> cubelover;

	int start = 0;
	int end = kooosaga.size();
	answer.resize(end);

	deque<char> ksg;
	deque<char> cube;

	sort(kooosaga.begin(), kooosaga.end());
	sort(cubelover.rbegin(), cubelover.rend());
	
	for (int i = 0; i < (kooosaga.size() + 1) / 2; i++) ksg.push_back(kooosaga[i]);
	for (int i = 0; i < cubelover.size() / 2; i++) cube.push_back(cubelover[i]);

	for (int i = 0; i < kooosaga.length(); i++) {
		if (i % 2 == 0) {
			if (cube.empty() || ksg.front() < cube.front()) {
				answer[start++] = ksg.front();
				ksg.pop_front();
			}
			else {
				answer[--end] = ksg.back();
				ksg.pop_back();
			}
		}
		else {
			if (ksg.empty() || ksg.front() < cube.front()) {
				answer[start++] = cube.front();
				cube.pop_front();
			}
			else {
				answer[--end] = cube.back();
				cube.pop_back();
			}
		}
	}
	
	cout << answer;
}
/*
koooosaga
cubelover
 = avaugrkoo

ioi
imo
 = ioi

bb
aa
 = ab

zxy
azb
 = xzy

ayz
xyc
 = ayy

aunqz
xepov
 = axnvq

zwpgbwk
awqqkvc
 = bwgvkqp

zwvxwmxzw
bwdscsdtq
 //answer
 = mwwswswtv

 //correct
 = mwvtwswsw
*/
