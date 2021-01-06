/***
 * @Author         : IQIUM
 * @Date           : 2020-11-23 09:36:39
 * @LastEditors    : IQIUM
 * @LastEditTime   : 2020-12-07 09:33:03
 * @FilePath       : \Exercise7\2\Dijkstra.cpp
 */
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stack>
using namespace std;
const int INFINTY = 10000;
const int MAX = 100;

class Graph {
  public:
    int vertexNum; /* 图顶点的个数 */
    int edgeNum;   /* 图边的个数 */
    char *vertex;  /* 顶点的存储 */
    int **edges;   /* 边的存储 */
    Graph() : vertexNum(0), edgeNum(0), vertex(NULL), edges(NULL) {}
};

Graph *graph = new Graph();

void createGraph() {
    cout << "请输入顶点数和边数：  ";
    cin >> graph->vertexNum >> graph->edgeNum;
    graph->vertex = new char[MAX]();
    graph->edges = new int *[MAX];
    for (int i = 0; i < MAX; i++) {
        graph->edges[i] = new int[MAX];
    }
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            graph->edges[i][j] = INFINTY;
        }
    }
    cout << "请输入各个顶点的信息：  ";
    for (int i = 0; i < graph->vertexNum; i++) {
        cin >> graph->vertex[i];
    }
    cout << "请输入边：  \n";
    string edge;
    for (int i = 0; i < graph->edgeNum; i++) {
        cin >> edge;
        int x = edge[1] - '0';
        int y = edge[3] - '0';
        if (edge[4] == '>') /* 有向图 */
        {
            graph->edges[x][y] = 1;
        } else if (edge[4] == ')') /* 无向图 */
        {
            graph->edges[x][y] = 1, graph->edges[y][x] = 1;
        } else if (edge[6] == '>') /* 带权有向图 */
        {
            graph->edges[x][y] = edge[5] - '0';
        } else if (edge[6] == ')') /* 带权无向图 */
        {
            graph->edges[x][y] = graph->edges[y][x] = edge[5] - '0';
        }
    }
}

/* 获取图的某一个节点 */
char getVertex(int index) { return graph->vertex[index]; }

/* 返回顶点v的第一个邻接点 */
int firstAdjVex(int index) {
    int aim = -1;
    for (int i = 0; i < graph->vertexNum; i++) {
        if (graph->edges[index][i] != INFINTY) {
            aim = i;
            break;
        }
    }
    return aim;
}

int nextAdjVex(int u, int v) {
    for (int i = v + 1; i < graph->vertexNum; i++) {
        if (graph->edges[u][i] != INFINTY) {
            return i;
        }
    }
    return -1;
}

int getIndexByValue(char ch) {
    for (int i = 0; i < graph->vertexNum; i++) {
        if (graph->vertex[i] == ch) {
            return i;
        }
    }
    return -1;
}

void deleteGraph() {
    for (int i = 0; i < MAX; i++) {
        delete[] graph->edges[i];
    }
    delete[] graph->edges;
    delete graph;
}

int getMinDistance(int dist[], bool flag[]) {
    int min_index = -1;
    int min = INFINTY;
    for (int i = 0; i < graph->vertexNum; i++) {
        if (!flag[i] && dist[i] < min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

/***
 * @description: 使用 Dijkstra 求最短路径，index表示索引起始
 */
void Dijkstra(int index, int end) {
    /* 1.设置三个辅助数组 */
    int dist[MAX];
    int path[MAX];
    bool flag[MAX];
    /* 2. 初始化 */
    for (int i = 0; i < graph->vertexNum; i++) {
        flag[i] = false;
        dist[i] = graph->edges[index][i];
        if (dist[i] != INFINTY) {
            path[i] = index;
        } else {
            path[i] = -1;
        }
    }
    /* 3. 访问index */
    flag[index] = true;
    dist[index] = -1;
    for (int i = 0; i < graph->vertexNum - 1; i++) {
        int min_index = getMinDistance(dist, flag);
        if (min_index == -1) {
            return;
        }
        flag[min_index] = true;
        int minDist = dist[min_index];
        if (minDist < INFINTY) {
            /* 4. 更新 */
            for (int i = 0; i < graph->vertexNum; i++) {
                if (!flag[i] &&
                    dist[i] > graph->edges[min_index][i] + minDist) {
                    dist[i] = graph->edges[min_index][i] + minDist;
                    path[i] = min_index;
                }
            }
        }
    }

    cout << "从起点 " << index << " 到终点 " << end << " 的最短路径为： ";
    int i = end;
    int minWeight = dist[i]; /* 最短距离 */
    stack<int> s;            /* 最短路径 */
    while (i != -1) {
        s.push(i);
        i = path[i];
    }
    while (!s.empty()) {
        int top = s.top();
        cout << " " << top << " ";
        if (s.size() != 1) {
            cout << "-->";
        }
        s.pop();
    }
    cout << "\n\t"
         << "该路的长度为：  " << minWeight << endl;
}

int main() {
    createGraph();

    cout << "请输入起点编号：  ";
    int start = -1;
    cin >> start;
    cout << "请输入终点编号：  ";
    int end = -1;
    cin >> end;
    Dijkstra(start, end);

    deleteGraph();
    return 0;
}
