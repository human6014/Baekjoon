#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool compare(pair<int,int> a,pair<int,int>b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main() {
	int num;
	cin >> num;
	int first, second;
	
	vector<pair<int, int>> usingTime;
	int endTime = 0;
	int answerCount = 0;
	usingTime.resize(num);
	for (int i = 0; i < num; i++) {
		cin >> usingTime[i].first>> usingTime[i].second;
		//usingTime.push_back(make_pair(first,second));
	}

	sort(usingTime.begin(), usingTime.end(), compare);
	for (int i = 0; i < usingTime.size(); i++) {
		if (usingTime[i].first >= endTime) {
			answerCount++;
			endTime = usingTime[i].second;
		}
	}
	cout << answerCount;
}