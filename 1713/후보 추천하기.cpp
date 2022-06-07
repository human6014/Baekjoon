#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct info {
	int count;
	int when;
};
int N, studentsNum;
unordered_map< int,info> allStudents;
int main() {
	cin >> N;
	cin >> studentsNum;

	int name;
	for (int i = 0; i < studentsNum; i++) {
		cin >> name;
		if (allStudents.find(name) != allStudents.end()) {
			allStudents[name].count++;
			continue;
		}
		if (allStudents.size() < N) {
			allStudents.insert({ name, {1, i} });
			continue;
		}
		else {
			int tempName;
			int minCount = 1001;
			int minWhen = 101;
			for (auto j : allStudents) {
				if (minCount == j.second.count) {
					if (minWhen > j.second.when) {
						minWhen = j.second.when;
						tempName = j.first;
					}
				}
				else if(minCount > j.second.count){
					minCount = j.second.count;
					minWhen = j.second.when;
					tempName = j.first;
				}
			}
			allStudents.erase(tempName);
			allStudents.insert({ name,{1,i} });
		}
	}

	vector<int> sorting;
	for (auto i : allStudents) {
		sorting.push_back(i.first);
	}
	sort(sorting.begin(), sorting.end());
	for (auto i : sorting) {
		cout << i <<" ";
	}
}