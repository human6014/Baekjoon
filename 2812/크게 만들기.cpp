#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int N, K;
string number;
int main() {
	stack<char> s;
	cin >> N >> K;
	cin >> number;
	s.push(number[0]);
	char top;
	for (int i = 1; i < number.length(); i++) {
		if (K > 0) {
			if (s.top() >= number[i]) s.push(number[i]);
			else {
				while (!s.empty() && s.top() < number[i] && K > 0) {
					s.pop();
					K--;
				}
				s.push(number[i]);
			}
		}
		else s.push(number[i]);
	}
	string answer = "";
	while (!s.empty()) {
		if (K > 0) K--;
		else answer += s.top();
		s.pop();
	}
	reverse(answer.begin(), answer.end());
	cout << answer;
}
/*
10 4
4177252841

4 입장한 채로 시작
1 입장 -> 그대로 stack에 넣음
7 입장 -> 그대로 stack의 top 보다 크므로 stack pop
	   -> pop을 해서 4가 top인데 그래도 top 보다 큼
	   -> stack pop후 7 넣음							K-=2
7 입장 -> 그대로 stack에 넣음
2 입장 -> 그대로 stack에 넣음
5 입장 -> top보다 크므로 stack pop 후 stack에 넣음		K-=1
2 입장 -> 그대로 stack에 넣음
8 입장 -> top보다 크므로 stack pop 후 stack에 넣음		K-=1
K가 0이므로 나머지 숫자 stack에 전부 넣음

*/