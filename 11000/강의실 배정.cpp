/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define PII pair<int,int>

int N;
vector<PII> times;
vector<PII> roomsTime;
bool Sorting(PII start, PII end) {
	if (start.first == end.first) return start.second < end.second;
	return start.first < end.first;
}
int main() {
	cin >> N;
	times.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> times[i].first >> times[i].second;
	}

	sort(times.begin(), times.end(), Sorting);

	roomsTime.push_back(times[0]);

	bool isIn;
	for (int i = 1; i < times.size(); i++) {
		isIn = false;
		for (int j = 0; j < roomsTime.size(); j++) {
			if (roomsTime[j].second <= times[i].first) {
				roomsTime[j].second = times[i].second;
				isIn = true;
				break;
			}
		}
		if (!isIn) roomsTime.push_back(times[i]);
	}

	cout << "\n";
	for (int i = 0; i < roomsTime.size(); i++) {
		cout << roomsTime[i].first << " " << roomsTime[i].second << "\n";
	}
	cout << roomsTime.size();
}
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define PII pair<int,int>

struct compare {
	bool operator()(PII start, PII end) {
		return start.second > end.second;
	}
};
int N;
priority_queue<PII, vector<PII>, compare> roomsTime;
priority_queue<PII, vector<PII>, greater<PII>> timesQ;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	int start, end;
	for (int i = 0; i < N; i++) {
		cin >> start >> end;
		timesQ.push({ start, end });
	}

	int frontF,frontS;
	int startTime, endTime;
	while (!timesQ.empty()) {
		frontF = timesQ.top().first;
		frontS = timesQ.top().second;
		timesQ.pop();

		if (roomsTime.empty()) {
			roomsTime.push({frontF,frontS});
			continue;
		}
		startTime = roomsTime.top().first;
		endTime = roomsTime.top().second;
		if (endTime <= frontF) {
			roomsTime.pop();
			roomsTime.push({startTime,frontS});
		}
		else roomsTime.push({frontF,frontS});
	}

	cout << roomsTime.size();
}
/*
5
1 7
2 3
3 4
4 8
7 10
=2

4
1 2
1 4
2 6
4 5
=2

6
1 3
2 5
7 8
4 12
9 10
7 11
=3
*/