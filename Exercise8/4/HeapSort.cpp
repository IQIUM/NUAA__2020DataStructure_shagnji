#include <bits/stdc++.h>
using namespace std;

const int counts = 10;
int arr[10] = {2, 5, 3, 9, 1, 43, 55, 12, 15, 10};
void HeapSort();
void HeapSort(int i, int length);
void print();

int main() {
    cout << "ÅÅÐòÇ°£º  ";
    print();
    HeapSort();
    cout << "ÅÅÐòºó£º  ";
    print();

    return 0;
}

void HeapSort(int i, int length) {
    int tmp = arr[i];
    for (int k = 2 * i + 1; k < length; k = 2 * k + 1) {
        if (k + 1 < length && arr[k] < arr[k + 1]) {
            ++k;
        }
        if (tmp < arr[k]) {
            arr[i] = arr[k];
            i = k;
        } else {
            break;
        }
    }
    arr[i] = tmp;
}

void HeapSort() {
    int tmp = 0;
    for (int i = counts / 2 - 1; i >= 0; --i) {
        HeapSort(i, counts);
    }
    for (int j = counts - 1; j > 0; j--) {
        tmp = arr[j];
        arr[j] = arr[0];
        arr[0] = tmp;
        HeapSort(0, j);
    }
}

void print() {
    for (int i = 0; i < counts; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}