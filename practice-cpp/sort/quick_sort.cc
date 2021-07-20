
#include "sort_algorithm.hpp"
#include <vector>
#include <algorithm>
#include <iostream>
#include <random>

int QuickSort::_partition(vector<int> &arr, int lo, int hi) {

    int l = lo, r = hi + 1;
    int v = arr[lo];

    while (true) {
        while (arr[++l] <= v) {
            if (l == hi) break;
        }

        while (arr[--r] >= v) {
            if (r == lo) break;
        }

        if (l >= r) break;

        swap(arr[r], arr[l]);
    }

    // a[lo, ... r-1], a[r], a[r+1, ... hi]
    // put v to a[r]
    swap(v, arr[r]);

    return r;
}


void QuickSort::_sort(vector<int>& arr, int lo, int hi) {

    if (lo >= hi) return;

    int j = _partition(arr, lo, hi);
    _sort(arr, lo, j);
    _sort(arr, j + 1, hi);

}


void QuickSort::sort(vector<int>& arr) {
    // shuflle
    _sort(arr, 0, arr.size() - 1);
}