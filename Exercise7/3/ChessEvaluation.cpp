/***
 * @Author         : IQIUM
 * @Date           : 2020-11-26 19:38:51
 * @LastEditors    : IQIUM
 * @LastEditTime   : 2020-11-30 19:47:28
 * @FilePath       : \Exercise7\3\ChessEvaluation.cpp
 */
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
int matrix[3][3];

int count() {
    int count = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] == 0) {
                count++;
            }
        }
    }
    return count;
}

/***
 * @description:
 * 用于判断是否有人成功，若Alice胜利，则返回1，若Bob胜，返回2，若平局，返回0
 */
int success() {
    int res = 0;
    for (int i = 0; i < 3; i++) {
        if ((matrix[i][0] == 1 && matrix[i][1] == 1 && matrix[i][2] == 1) ||
            (matrix[0][i] == 1 && matrix[1][i] == 1 && matrix[2][i] == 1) ||
            (matrix[0][0] == 1 && matrix[1][1] == 1 && matrix[2][2] == 1) ||
            (matrix[0][2] == 1 && matrix[1][1] == 1 && matrix[2][0] == 1)) {
            res = 1;
        } else if ((matrix[i][0] == 2 && matrix[i][1] == 2 &&
                    matrix[i][2] == 2) ||
                   (matrix[0][i] == 2 && matrix[1][i] == 2 &&
                    matrix[2][i] == 2) ||
                   (matrix[0][0] == 2 && matrix[1][1] == 2 &&
                    matrix[2][2] == 2) ||
                   (matrix[0][2] == 2 && matrix[1][1] == 2 &&
                    matrix[2][0] == 2)) {
            res = 2;
        }
    }
    if (res != 0) {
        res = res == 1 ? count() + 1 : -(count() + 1);
    }
    return res;
}

void traverse() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

bool isFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

/*
 * @Description:
 * @param: x 为 1 或 2，1代表Alice,B代表Bob
 * @return: 最终得分
 */
int chessEvaluation(int x) {

    /* 1. 首先判断当前棋局是否是平局 */
    if (isFull()) {
        return 0;
    }
    int bestRes = x == 1 ? -10 : 10;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] == 0) {
                /* 1. 递归回溯 */
                matrix[i][j] = x;
                int res = 0;
                if (res = success()) { /* 判断刚下完后是否胜利 */
                    matrix[i][j] = 0;
                    return res;
                }
                /* 如果不胜利，则采用极大极小 */
                if (x == 1) {
                    bestRes = max(chessEvaluation(2), bestRes);
                } else {
                    bestRes = min(chessEvaluation(1), bestRes);
                }
                /* 回溯 */
                matrix[i][j] = 0;
            }
        }
    }
    return bestRes;
}

int main() {
    int n = 0; /* n 表示数据的组数 */
    scanf("%d", &n);
    vector<int> v; /* 向量用于存储所有的得分情况 */
    for (int i = 0; i < n; i++) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                scanf("%d", &matrix[i][j]);
            }
        }

        /* 看刚输入数据时时候有人胜利 */
        int res = 0;
        if (!(res = success())) {
            res = chessEvaluation(1);
        }
        v.push_back(res);
    }
    for (int i = 0; i < n; i++) {
        printf("%d\n", v[i]);
    }

    return 0;
}