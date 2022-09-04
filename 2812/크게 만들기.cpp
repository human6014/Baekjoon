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

4 ������ ä�� ����
1 ���� -> �״�� stack�� ����
7 ���� -> �״�� stack�� top ���� ũ�Ƿ� stack pop
	   -> pop�� �ؼ� 4�� top�ε� �׷��� top ���� ŭ
	   -> stack pop�� 7 ����							K-=2
7 ���� -> �״�� stack�� ����
2 ���� -> �״�� stack�� ����
5 ���� -> top���� ũ�Ƿ� stack pop �� stack�� ����		K-=1
2 ���� -> �״�� stack�� ����
8 ���� -> top���� ũ�Ƿ� stack pop �� stack�� ����		K-=1
K�� 0�̹Ƿ� ������ ���� stack�� ���� ����

*/