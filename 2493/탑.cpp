//ž
#include <iostream>
#include <stack>
using namespace std;

int N; int answer[500001]; int main() {
    stack<pair<int, int>> s; cin >> N;

    int height;
    bool isEmpty;
    for (int i = 0; i < N; i++) {
        cin >> height;

        if (i == 0) {
            answer[0] = 0;
            s.push({ i + 1, height });
            continue;
        }

        while (!(isEmpty = s.empty()) && s.top().second < height) s.pop();

        answer[i] = isEmpty ? 0 : s.top().first;
        s.push({ i + 1, height });
    }

    for (int i = 0; i < N; i++) cout << answer[i] << " ";
} 
/* 
5 
6 9 5 7 4

6 ���� -> ù��°�� �״�� stack Go! 
9 ���� -> stack top = 6 
       -> �ڽź��� �۱� ������ ��� pop top 
       -> stack�� �� �����Ƿ� 0 ���� 
       -> �ڱ� �ڽ� stack push 
5 ���� -> stack top = 9 
       -> �ڽź��� ũ�� ������ �ش� �ѹ� ���� 
       -> �ڱ� �ڽ� stack push 
7 ���� -> stack top = 5 
       -> �ڽź��� �۱� ������ ��� pop top 
       -> 9�� ������ �ڽź��� ũ�� ������ �ش� �ѹ� ���� 
       -> �ڱ� �ڽ� stack push

9 
10 6 5 4 3 2 7 5 9 
 0 1 2 3 4 5 1 7 1

*/