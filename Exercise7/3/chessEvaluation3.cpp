/***
 * @Author         : IQIUM
 * @Date           : 2020-12-07 11:30:54
 * @LastEditors    : IQIUM
 * @LastEditTime   : 2020-12-07 11:30:54
 * @FilePath       : \Exercise7\3\chessEvaluation3.cpp
 */
#include <bits/stdc++.h>
using namespace std;
int a[4][4];
int block() { //空格的个数
    int cnt = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (a[i][j] == 0)
                cnt++;
        }
    }
    return cnt;
}
bool check_row(int row, int val) { //检查行是否三个一样
    if (a[row][0] == val && a[row][0] == a[row][1] && a[row][0] == a[row][2])
        return 1;
    return 0;
}
bool check_col(int col, int val) { //检查行是否三个一样
    if (a[0][col] == val && a[0][col] == a[1][col] && a[0][col] == a[2][col])
        return 1;
    return 0;
}
int win(int f) {
    int wi = 0, ans = 1; //判断当前能否取胜
    if (check_row(0, f) || check_row(1, f) || check_row(2, f))
        wi = 1;
    if (check_col(0, f) || check_col(1, f) || check_col(2, f))
        wi = 1;
    if (a[0][0] == f && a[0][0] == a[1][1] && a[0][0] == a[2][2])
        wi = 1;
    if (a[0][2] == f && a[0][2] == a[1][1] && a[1][1] == a[2][0])
        wi = 1;
    if (wi == 0)
        return 0;
    ans += block();
    return (f == 1) ? ans : -ans; // alice赢为正数,bob赢为负数
}
int dfs(int p) { //搜索当前局面可能的走法的最大值
    if (block() == 0)
        return 0; //棋局已满
    int max_n = -10, min_n = 10;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (!a[i][j]) {
                a[i][j] = p + 1;
                int w = win(p + 1);
                if (w != 0) {
                    a[i][j] = 0;
                    return w > 0 ? max(max_n, w) : min(min_n, w);
                }
                if (!p)
                    max_n = max(max_n, dfs(1));
                else
                    min_n = min(min_n, dfs(0));
                a[i][j] = 0;
            }
        }
    }
    return p == 1 ? min_n : max_n;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> a[i][j];
            }
        }
        int x = win(1), y = win(2);
        if (x) {
            cout << x << endl;
            continue;
        }
        if (y) {
            cout << y << endl;
            continue;
        }
        cout << dfs(0) << endl; // 0为alice走,1为bob走
    }
    return 0;
}