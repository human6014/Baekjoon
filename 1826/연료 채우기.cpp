#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct compare {
	bool operator()(pair<int, int> start, pair<int, int> end) {
		return start.second < end.second;
	}
};
int N,L,P;
vector<pair<int, int>> village;
priority_queue<pair<int, int>,vector<pair<int,int>>,compare> pq;
int main() {
	int answer = 0;
	cin >> N;
	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		village.push_back({ a,b });
	}
	cin >> L >> P;

	sort(village.begin(), village.end());
	/*
	int nowDist = 0, nowOil = P;
	int newDist = 0, newOil = 0;
	int index;
	while(nowDist + nowOil < L) {
		index = -1;
		newOil = 0;
		for (int j = 0; j < N; j++) {
			if (nowDist + nowOil < village[j].first) break;
			if (newOil < village[j].second) {
				newDist = village[j].first;
				newOil = village[j].second;
				index = j;
			}
		}
		if (index == -1) {
			answer = -1;
			break;
		}
		village[index].first = 0;
		village[index].second = 0;
		nowOil += newOil - (newDist - nowDist);
		nowDist = newDist;
		answer++;
	}
	cout << answer;
	*///시간 초과 날 것 같음
	int nowDist = 0, nowOil = P;
	int newDist = 0, newOil = 0;
	int index = 0;

	while(nowDist + nowOil < L) {
		while (index < village.size() && village[index].first <= nowOil + nowDist) {
			pq.push({village[index].first,village[index].second});
			index++;
		}
		if (!pq.empty()) {
			newDist = pq.top().first;
			newOil = pq.top().second;
			pq.pop();
			nowOil += newOil - (newDist - nowDist);
			nowDist = newDist;
			answer++;
		}
		else {
			answer = -1;
			break;
		}
	}
	cout << answer;
}
/*
4
4 4
5 2
11 5
15 10
25 10
 = 3

 4, 4  => 4, 10  (14)
 11,5  => 11, 8  (20)
 15,10 => 15, 14 (29)


5
1 5
5 7
6 1
7 10
8 3
20 10
 = 1

6
5 6
7 8
6 10
11 5
13 2
18 5
30 10
 = 3

 6, 10 => 6, 14 (20)
 11, 5 => 11, 14 (25)

 1. first 오름차순 정렬
 2. 현재 남은 기름보다 작은 first 에서 second가 가장 큰 곳 방문
 3. 거리 갱신, 기름 갱신
 4. if 거리 + 기름 >= 목적지 : answer return
 5. else 2번 이동 
*/
