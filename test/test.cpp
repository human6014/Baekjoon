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

void dfs(int first, int a, int sum) { //0���� ���� 0���� ���ƿ;ߵ�
    if (first == a && cnt == n) { //ó������ ���ƿ��� ��, N����ŭ �������� ����
        if (Min > sum) {
            Min = sum;
        }
        return; //���ŵǴ� �ȵǴ� ��·�� ����
    }

    for (int i = 0; i < n; i++) {
        if (visit[i] == 0 && gridMap[a][i] != 0) { //�湮���� �ʾҰ� map�� ���� ������
            visit[i] = 1;
            sum += gridMap[a][i];
            cnt++;
            dfs(first, i, sum);
            //dfs return ���� �������·� �ٸ� ��嵵 Ž���ؾߵǱ⶧���� �������·� �����ش�. ��Ʈ��ŷ
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