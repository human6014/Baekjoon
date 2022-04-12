#include <iostream>
#include <queue>
using namespace std;

int main() {
	int num;
	cin >> num;
	queue<int>Myq;
	for (int i = 1; i <= num; i++) {
		Myq.push(i);
	}
	int recycle;
	while (Myq.size() != 1) {
		Myq.pop();
		recycle = Myq.front();
		Myq.pop();
		Myq.push(recycle);
	}
	cout << Myq.front();
}