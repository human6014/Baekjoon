#include <iostream>
#include <deque>
using namespace std;

int N, W, L;
int trucks[1001];
deque<pair<int,int>> q;
int main() {
	cin >> N >> W >> L;

	int answer = 0;
	
	for (int i = 0; i < N; i++) {
		cin >> trucks[i];
	}

	int inTruckNum = 1;
	int inQueueWeight = trucks[0];
	q.push_back({ 1,trucks[0] });
	while (!q.empty()) {
		answer++;
		for (int i = 0; i < q.size(); i++) {
			q[i].first++;
		}
		if (q.front().first > W) {
			inQueueWeight -= q.front().second;
			q.pop_front();
		}
		if (inTruckNum <= N && inQueueWeight + trucks[inTruckNum] <= L) {
			q.push_back({ 1,trucks[inTruckNum] });
			inQueueWeight += trucks[inTruckNum];
			inTruckNum++;
		}
	}
	cout << answer;
}
/*
5 2 10
9 4 8 1 5
 : 9
*/

//1.	초기상태
//2.	다리 위 트럭 1칸 앞으로 이동
//3.	앞 트럭이 다리 밖이라면 pop
//4.	이동했을 때 하중이 된다면 다음 트럭 push
//5.	3과 4는 동시에 이루어질 수 있음