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

string targetStr;
bool isVisited[50];
int DFS(string nowStr, vector<string> words, int depth) {
    if (nowStr == targetStr) return depth;
    int answer = 0;
    int count = 0;
    for (int i = 0; i < words.size(); i++) {
        count = 0;
        if (isVisited[i]) continue;

        for (int j = 0; j < words[i].size(); j++) {
            if (nowStr[j] != words[i][j]) {
                count++;
            }
            if (count >= 2)break;
        }

        if (count < 2) {
            isVisited[i] = true;
            answer = DFS(words[i], words, depth + 1);
            isVisited[i] = false;
        }
    }
    return answer;
}
int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    targetStr = target;
    answer = DFS(begin, words, 0);

    return answer;
}
int main() {
    string begin = "hit";
    string target = "cog";
    vector<string>words =  { {"hot"}, {"dot"}, {"dog" }, {"lot"}, {"log"}, {"cog"}};
    cout << solution(begin, target, words);
}