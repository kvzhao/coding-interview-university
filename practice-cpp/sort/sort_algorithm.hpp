
#pragma once

#include <vector>

using namespace std;

class MergeSort {

public:
void sort(vector<int>& arr);

private:

void merge(vector<int>& arr, vector<int>& aux, int low, int mid, int high);
void _sort(vector<int>& arr, vector<int>& aux, int low, int high);

vector<int> aux;

};


class QuickSort {

public:
void sort(vector<int>& arr);
int top_k(vector<int>& arr, int k);

private:
void _sort(vector<int>& arr, int lo, int hi);
int _partition(vector<int>& arr, int lo, int hi);

};