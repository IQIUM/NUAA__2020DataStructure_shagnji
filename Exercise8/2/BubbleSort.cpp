#include <bits/stdc++.h>
using namespace std;
const int counts = 10;
int arr[10] = {2, 5, 3, 9, 1, 43, 55, 12, 15, 10};
// int arr[5] = {4, 9, 8, 5, 6};
int tmp[10];

void BubbleSort() {
    for (int i = 0; i < counts - 1; i++) {
        for (int j = 0; j < counts - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

/**
 * @description: Ñ¡ÔñÅÅÐò
 */
void Selection() {
    for (int i = 0; i < counts; i++) {
        int k = i;
        for (int j = k + 1; j < counts; j++) {
            if (arr[j] < arr[k]) {
                k = j;
            }
        }
        if (k != i) {
            int tmp = arr[i];
            arr[i] = arr[k];
            arr[k] = tmp;
        }
    }
}

void print() {
    for (int i = 0; i < counts; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void save() {
    for (int i = 0; i < counts; i++) {
        tmp[i] = arr[i];
    }
}

void trans() {
    for (int i = 0; i < counts; i++) {
        arr[i] = tmp[i];
    }
}

/**
 * @description: ?????????
 */
void merge(int left, int mid, int right, int tmp[]) {
    int i = left;
    int j = mid + 1;
    int t = 0;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            tmp[t++] = arr[i++];
        } else {
            tmp[t++] = arr[j++];
        }
    }
    while (i <= mid) {
        tmp[t++] = arr[i++];
    }
    while (j <= right) {
        tmp[t++] = arr[j++];
    }
    t = 0;
    int tmpLeft = left;
    while (tmpLeft <= right) {
        arr[tmpLeft++] = tmp[t++];
    }
}

void mergeSort(int left, int right, int tmp[]) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(left, mid, tmp);
        mergeSort(mid + 1, right, tmp);
        merge(left, mid, right, tmp);
    }
}

void mergeSort() {
    int *tmp = new int[counts]();
    mergeSort(0, counts - 1, tmp);
}

int main() {
    save();
    cout << "排序前：  ";
    print();
    cout << "冒泡排序：  ";
    BubbleSort();
    print();
    trans();
    cout << "选择排序：  ";
    Selection();
    print();
    trans();
    cout << "归并排序：   ";
    mergeSort();
    print();
    return 0;
}