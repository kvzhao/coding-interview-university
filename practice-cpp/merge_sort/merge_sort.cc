
#include "merge_sort.hpp"

#include <iostream>
#include <vector>

void MergeSort::sort(std::vector<int>& arr) {

    aux.assign(arr.begin(), arr.end());
    // sort
    _sort(arr, aux, 0, arr.size() - 1);
}

void MergeSort::_sort(vector<int>& arr, vector<int>& aux, int lo, int hi) {

    if (hi <= lo) {
        return;
    }

    int mid = lo + (hi - lo) / 2;

    // eliminate copy
    _sort(aux, arr, lo, mid);
    _sort(aux, arr, mid + 1, hi);
    merge(arr, aux, lo, mid, hi);
}

void MergeSort::merge(vector<int>& arr, vector<int>& aux, int lo, int mid, int hi) {

    int left = lo, right = mid + 1;

    for (int i = lo; i < hi + 1; i++) {
        if (left > mid) {
            aux[i] = arr[right++];
        } else if (right > hi) {
            aux[i] = arr[left++];
        } else if (arr[right] < arr[left]) {
            aux[i] = arr[right++];
        } else {
            aux[i] = arr[left++];
        }
    }
}