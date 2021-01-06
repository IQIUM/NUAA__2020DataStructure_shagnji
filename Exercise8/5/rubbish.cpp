#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int> > points;
int scores[5];

int main() {
    int n = 0;
    cin >> n;
    while (n--) {
        int x = 0, y = 0;
        cin >> x >> y;
        points.push_back(make_pair(x, y));
    }
    for (int i = 0; i < 5; i++) {
        scores[i] = 0;
    }
    vector<pair<int, int> > it;
    for (int i = 0; i < points.size(); i++) {
        pair<int, int> cur = points[i];
        int x = cur.first;
        int y = cur.second;
        pair<int, int> tofind;
        tofind = make_pair(x + 1, y);
        if (find(points.begin(), points.end(), make_pair(x, y + 1)) ==
            points.end()) {
            continue;
        }
        if (find(points.begin(), points.end(), make_pair(x, y - 1)) ==
            points.end()) {
            continue;
        }
        if (find(points.begin(), points.end(), make_pair(x - 1, y)) ==
            points.end()) {
            continue;
        }
        if (find(points.begin(), points.end(), make_pair(x + 1, y)) ==
            points.end()) {
            continue;
        }
        int score = 0;
        if (find(points.begin(), points.end(), make_pair(x + 1, y + 1)) !=
            points.end()) {
            score++;
        }
        if (find(points.begin(), points.end(), make_pair(x + 1, y - 1)) !=
            points.end()) {
            score++;
        }
        if (find(points.begin(), points.end(), make_pair(x - 1, y - 1)) !=
            points.end()) {
            score++;
        }
        if (find(points.begin(), points.end(), make_pair(x - 1, y + 1)) !=
            points.end()) {
            score++;
        }
        scores[score]++;
    }
    for (int i = 0; i < 5; i++) {
        cout << scores[i] << endl;
    }

    return 0;
}
