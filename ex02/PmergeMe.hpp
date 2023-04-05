#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <vector>
#include <set>
#include <cstdlib>


// void sort(std::vector<int> &vec);
void insertion_sort(std::vector<int>& arr, int left, int right);
void merge(std::vector<int>& arr, int left, int mid, int right);
void merge_insertion_sort(std::vector<int>& arr, int left, int right, int threshold);
#endif