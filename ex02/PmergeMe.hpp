#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <vector>
#include <set>
#include <cstdlib>
#include <ctime>

void insertion_sort(std::vector<int>& arr, int left, int right);
void merge(std::vector<int>& arr, int left, int mid, int right);
void merge_insertion_sort(std::vector<int>& arr, int left, int right, int threshold);
void mergeDeque(std::deque<int>& arr, int left, int mid, int right);
void mergeInsertionSortDeque(std::deque<int>& arr, int left, int right, int k);

#endif