#include <bits/stdc++.h>
using namespace std;

const int counts = 10;
int arr[10] = {2, 5, 3, 9, 1, 43, 55, 12, 15, 10};
void QuickSort();
void QuickSort(int low, int high);
int partition(int low, int high);
void print();

int main() {
    cout << "ÅÅÐòÇ°£º  ";
    print();
    QuickSort();
    cout << "ÅÅÐòºó£º  ";
    print();

    return 0;
}

void QuickSort() { QuickSort(0, counts - 1); }

void QuickSort(int low, int high) {
    if (low < high) {
        int pivot = partition(low, high);
        QuickSort(low, pivot - 1);
        QuickSort(pivot + 1, high);
    }
}
int partition(int low, int high) {
    int tmp = arr[low];
    while (low < high) {
        while (low < high && tmp <= arr[high]) {
            high--;
        }
        arr[low] = arr[high];
        while (low < high && tmp >= arr[low]) {
            low++;
        }
        arr[high] = arr[low];
    }
    arr[low] = tmp;
    return low;
}

void print() {
    for (int i = 0; i < counts; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}