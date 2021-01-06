/***
 * @Author         : IQIUM
 * @Date           : 2020-12-06 22:52:12
 * @LastEditors    : IQIUM
 * @LastEditTime   : 2020-12-07 16:19:48
 * @FilePath       : \Exercise7\4\OptimalIrrigation.cpp
 * @Discription    : 使用最邻近法完成货郎担问题（贪心算法）
 */
#include <iostream>
using namespace std;
const int INF = 20000;
const int MAX = 1100; /* 定义最大的节点数 */

class Graph {
  public:
    char vertexs[MAX];
    int arcs[MAX][MAX];
    int vertexNum;
    int arcNum;
    Graph() {
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                arcs[i][j] = INF;
            }
            vertexs[i] = i;
        }
    }
};

Graph *graph = new Graph();
int n; /* 节点数 */
int m; /* 边数 */

void createGraph() {
    cin >> n >> m;
    graph->vertexNum = n;
    graph->arcNum = m;
    for (int i = 0; i < m; i++) {
        int x = 0, y = 0, weight = 0;
        cin >> x >> y >> weight;
        graph->arcs[x][y] = weight;
        graph->arcs[y][x] = weight;
    }
}

int getMinNeightbor(int dist[], bool flag[]) {
    int min_index = -1;
    int min = INF;
    for (int i = 1; i <= graph->vertexNum; i++) {
        if (!flag[i] && dist[i] != INF && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void test(int dist[], int vexcode[]) {
    for (int i = 1; i <= graph->vertexNum; i++) {
        cout << dist[i] << "  " << vexcode[i] << endl;
    }
}

/* 使用prime算法求最小生成树 */
void prime() {
    int sumWeight = 0;
    int *vexcode = new int[graph->vertexNum + 1];
    int *dist = new int[graph->vertexNum + 1];
    bool *flag = new bool[graph->vertexNum + 1]();

    /* 1.初始化 */
    for (int i = 1; i <= graph->vertexNum; i++) {
        vexcode[i] = 1;
        dist[i] = graph->arcs[1][i];
    }

    flag[1] = true;
    dist[1] = 0;

    for (int i = 1; i <= graph->vertexNum; i++) {
        int min_index = getMinNeightbor(dist, flag);
        // cout << min_index << endl;
        if (min_index == -1) {
            break;
        }
        flag[min_index] = true;
        sumWeight += dist[min_index];

        /* 2.更新所有的顶点 */
        for (int i = 1; i <= graph->vertexNum; i++) {
            if (!flag[i] && dist[i] > graph->arcs[min_index][i]) {
                dist[i] = graph->arcs[min_index][i];
                vexcode[i] = min_index;
            }
        }
    }
    cout << sumWeight << endl;
    delete[] vexcode;
    delete[] dist;
    delete[] flag;
}

int main() {
    createGraph();
    prime();
    delete graph;
    return 0;
}