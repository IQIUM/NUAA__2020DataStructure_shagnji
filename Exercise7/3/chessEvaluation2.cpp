/***
 * @Author         : IQIUM
 * @Date           : 2020-11-30 15:27:23
 * @LastEditors    : IQIUM
 * @LastEditTime   : 2020-12-07 10:48:30
 * @FilePath       : \Exercise7\3\chessEvaluation2.cpp
 */
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
int mp[4][4];

/* 水平行 */
bool hok(int h, int f) {
    return mp[h][0] == f && mp[h][0] == mp[h][1] &&
           mp[h][1] == mp[h][2]; //判断行是否三颗相连
}

/* 竖直列 */
bool lok(int l, int f) {
    return mp[0][l] == f && mp[0][l] == mp[1][l] &&
           mp[1][l] == mp[2][l]; //判断列是否三颗相连
}

/***
 * @description: 计算空格的数量
 */
int spa() {
    int res = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (!mp[i][j])
                res++;
    return res;
}

/*
 * @Description:
 * @param: f 代表 1 / 2，检查现在的棋局情况
 * @return:
 */
int win(int f) { //判断当前局面胜负情况
    int wi = 0, ans = 1;
    if (hok(0, f) || hok(1, f) || hok(2, f)) /* 检查每一行 */
        wi = 1;
    if (lok(0, f) || lok(1, f) || lok(2, f)) /* 检查每一列 */
        wi = 1;
    if (mp[0][0] == f && mp[0][0] == mp[1][1] &&
        mp[1][1] == mp[2][2]) /* 主对角线 */
        wi = 1;
    if (mp[0][2] == f && mp[0][2] == mp[1][1] &&
        mp[1][1] == mp[2][0]) /* 辅对角线 */
        wi = 1;
    if (!wi) /* 如果没一个满足的就舍弃 */
        return 0;
    ans += spa(); /* 如果有：计算分数，返回 */
    return (f == 1) ? ans : -ans;
}

/* 一开始小儿科判断结束，开始正式下棋，peo 代表下棋人 */
int dfs(int peo) { //对抗搜索
    if (!spa())    /* 代表棋局满了，但还没有分出胜负 */
        return 0;
    int Max = -10, Min = 10;
    for (int i = 0; i < 3; i++) {
        for (int j = 0, w; j < 3; j++) {
            if (!mp[i][j]) /* 找所有的还没有下的位置 */
            {              //枚举可以落棋的位置
                mp[i][j] =
                    peo + 1; /* peo 为 0，代表Alice, peo 为 1，代表 Bob */
                w = win(peo + 1); /* 判断当我下了之后会不会赢 */
                if (w)            /*如果赢了  */
                {
                    mp[i][j] = 0; /* 赢了，回溯 */
                    return w > 0 ? max(Max, w) : min(Min, w);
                }

                if (!peo) /* 这一个判断就是再找下一个位置 */
                    Max = max(Max, dfs(1));
                else
                    Min = min(Min, dfs(0));

                mp[i][j] = 0; /* 回溯 */
            }
        }
    }
    return peo ? Min : Max; // 0-Alice-Max，1-Bob-Min
}

int main() {
    int t;
    cin >> t;
    while (t--) /* 次数循环 */
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                cin >> mp[i][j];
        int x = win(1),
            y = win(2); /* 在数组一输进去的时候就进行棋局判断，检查得分情况 */
        if (x) /* 如果有得分就if，没得分 x = 0 */
        {
            cout << x << endl;
            continue;
        }
        if (y) {
            cout << y << endl;
            continue;
        }
        cout << dfs(0) << endl; /* 排除一开始就胜利的情况后开始正式下棋
                                   ，0表示Alice下，1表示Bob下*/
    }
    return 0;
}