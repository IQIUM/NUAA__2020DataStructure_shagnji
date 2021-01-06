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

/* ˮƽ�� */
bool hok(int h, int f) {
    return mp[h][0] == f && mp[h][0] == mp[h][1] &&
           mp[h][1] == mp[h][2]; //�ж����Ƿ���������
}

/* ��ֱ�� */
bool lok(int l, int f) {
    return mp[0][l] == f && mp[0][l] == mp[1][l] &&
           mp[1][l] == mp[2][l]; //�ж����Ƿ���������
}

/***
 * @description: ����ո������
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
 * @param: f ���� 1 / 2��������ڵ�������
 * @return:
 */
int win(int f) { //�жϵ�ǰ����ʤ�����
    int wi = 0, ans = 1;
    if (hok(0, f) || hok(1, f) || hok(2, f)) /* ���ÿһ�� */
        wi = 1;
    if (lok(0, f) || lok(1, f) || lok(2, f)) /* ���ÿһ�� */
        wi = 1;
    if (mp[0][0] == f && mp[0][0] == mp[1][1] &&
        mp[1][1] == mp[2][2]) /* ���Խ��� */
        wi = 1;
    if (mp[0][2] == f && mp[0][2] == mp[1][1] &&
        mp[1][1] == mp[2][0]) /* ���Խ��� */
        wi = 1;
    if (!wi) /* ���ûһ������ľ����� */
        return 0;
    ans += spa(); /* ����У�������������� */
    return (f == 1) ? ans : -ans;
}

/* һ��ʼС�����жϽ�������ʼ��ʽ���壬peo ���������� */
int dfs(int peo) { //�Կ�����
    if (!spa())    /* ����������ˣ�����û�зֳ�ʤ�� */
        return 0;
    int Max = -10, Min = 10;
    for (int i = 0; i < 3; i++) {
        for (int j = 0, w; j < 3; j++) {
            if (!mp[i][j]) /* �����еĻ�û���µ�λ�� */
            {              //ö�ٿ��������λ��
                mp[i][j] =
                    peo + 1; /* peo Ϊ 0������Alice, peo Ϊ 1������ Bob */
                w = win(peo + 1); /* �жϵ�������֮��᲻��Ӯ */
                if (w)            /*���Ӯ��  */
                {
                    mp[i][j] = 0; /* Ӯ�ˣ����� */
                    return w > 0 ? max(Max, w) : min(Min, w);
                }

                if (!peo) /* ��һ���жϾ���������һ��λ�� */
                    Max = max(Max, dfs(1));
                else
                    Min = min(Min, dfs(0));

                mp[i][j] = 0; /* ���� */
            }
        }
    }
    return peo ? Min : Max; // 0-Alice-Max��1-Bob-Min
}

int main() {
    int t;
    cin >> t;
    while (t--) /* ����ѭ�� */
    {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                cin >> mp[i][j];
        int x = win(1),
            y = win(2); /* ������һ���ȥ��ʱ��ͽ�������жϣ����÷���� */
        if (x) /* ����е÷־�if��û�÷� x = 0 */
        {
            cout << x << endl;
            continue;
        }
        if (y) {
            cout << y << endl;
            continue;
        }
        cout << dfs(0) << endl; /* �ų�һ��ʼ��ʤ���������ʼ��ʽ����
                                   ��0��ʾAlice�£�1��ʾBob��*/
    }
    return 0;
}