#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int N;
int main() {
	cin >> N;
    solution({70,50,80,50},100);
}

int solution(vector<int> people, int limit) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> pq;
    sort(people.begin(), people.end());

    pq.push(people[0]);
    int top;
    for (auto i : people) {
        top = pq.top();
        if (i + top <= limit) {
            pq.pop();
            pq.push(top + i);
        }
        else {
            pq.push(i);
        }
    }
    answer = pq.size();
    return answer;
}