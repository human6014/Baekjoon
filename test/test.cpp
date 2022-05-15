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

int n;
int gridMap[11][11];
int visit[11];
int Min = 98765432;
int cnt = 0;

void dfs(int first, int a, int sum) { //0으로 시작 0으로 돌아와야됨
    if (first == a && cnt == n) { //처음으로 돌아왔을 때, N번만큼 돌았으면 인정
        if (Min > sum) {
            Min = sum;
        }
        return; //갱신되던 안되던 어쨌든 리턴
    }

    for (int i = 0; i < n; i++) {
        if (visit[i] == 0 && gridMap[a][i] != 0) { //방문하지 않았고 map에 값이 있으면
            visit[i] = 1;
            sum += gridMap[a][i];
            cnt++;
            dfs(first, i, sum);
            //dfs return 이후 이전상태로 다른 노드도 탐방해야되기때문에 이전상태로 돌려준다. 백트래킹
            visit[i] = 0;
            sum -= gridMap[a][i];
            cnt--;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> gridMap[i][j];
        }
        visit[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        dfs(i, i, 0);
    }

    cout << Min << '\n';
    return 0;
}