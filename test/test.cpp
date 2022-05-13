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

unordered_map <string, int> orderMap[21];
vector<pair<string, int>> ordersVector[21];
void Combination(vector<string>orders ,int depth, int index, int maxIndex) {
    if (depth == maxIndex) {
        string temp ="";
        for (int i = 0; i < depth; i++) {
            temp += orders[i];
        }
        return;
    }
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    for (int i = 0; i < orders.size(); i++) 
        sort(orders[i].begin(), orders[i].end());
    
    for (int i = 0; i < orders.size(); i++) {
        for (int j = 0; j < course.size(); j++) {

        }
    }
    return answer;
}

int main() {
    vector<string> orders = { "ABCFG","AC","CDE","ACDE","BCFG","ACDEH" };
    vector<int> course = { 2,3,4 };
    vector<string> answer = solution(orders, course);

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] <<"\n";
    }
}