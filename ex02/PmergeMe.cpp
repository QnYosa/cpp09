#include "PmergeMe.hpp"

// https://iq.opengenus.org/merge-insertion-sort/

void insertion_sort(std::vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    std::vector<int> left_half(n1);
    std::vector<int> right_half(n2);

    for (int i = 0; i < n1; i++)
        left_half[i] = arr[left + i]; // mettre la partie guche en partie 
        // gauche du vecteur et faire de meme avec la partie droite afin d'avoir
        // un seul vecteur. 
    for (int j = 0; j < n2; j++)
        right_half[j] = arr[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2) {
        if (left_half[i] <= right_half[j]) {
            arr[k] = left_half[i];
            i++;
        }
        else {
            arr[k] = right_half[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = left_half[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = right_half[j];
        j++;
        k++;
    }
}

void merge_insertion_sort(std::vector<int>& arr, int left, int right, int threshold) {
    if (left < right) {
        if (right - left <= threshold) {
            insertion_sort(arr, left, right);
        }
        else {
            int mid = left + (right - left) / 2;
            merge_insertion_sort(arr, left, mid, threshold);
            merge_insertion_sort(arr, mid + 1, right, threshold);
            merge(arr, left, mid, right);
        }
    }
}
