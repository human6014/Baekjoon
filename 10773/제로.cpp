#include <iostream>
#include <stack>
using namespace std;

stack<int>s;
int N;
int main() {
	cin >> N;
	int number;
	for (int i = 0; i < N; i++) {
		cin >> number;
		if (number == 0)s.pop();
		else s.push(number);
	}
	int answer = 0;
	while(!s.empty()){
		answer += s.top();
		s.pop();
	}
	cout << answer;
}