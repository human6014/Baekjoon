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





int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < scoville.size(); i++) {
        pq.push(scoville[i]);
    }

    int top1, top2;
    while (pq.top() < K) {
        if (pq.size() == 1)return -1;
        answer++;
        top1 = pq.top();
        pq.pop();
        top2 = pq.top();
        pq.pop();

        pq.push(top1 + (top2 * 2));
    }

    return answer;
}
int main() {

}