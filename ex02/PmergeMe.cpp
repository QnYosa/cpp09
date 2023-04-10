#include "PmergeMe.hpp"

// https://iq.opengenus.org/merge-insertion-sort/

void insertion_sort(std::vector<int> &arr, int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(std::vector<int> &arr, int left, int mid, int right)
{
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
    while (i < n1 && j < n2)
    {
        if (left_half[i] <= right_half[j])
        {
            arr[k] = left_half[i];
            i++;
        }
        else
        {
            arr[k] = right_half[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = left_half[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = right_half[j];
        j++;
        k++;
    }
}

void merge_insertion_sort(std::vector<int> &arr, int left, int right, int threshold)
{
    if (left < right)
    {
        if (right - left <= threshold)
        {
            insertion_sort(arr, left, right);
        }
        else
        {
            int mid = left + (right - left) / 2;
            merge_insertion_sort(arr, left, mid, threshold);
            merge_insertion_sort(arr, mid + 1, right, threshold);
            merge(arr, left, mid, right);
        }
    }
}

void mergeDeque(std::deque<int> &arr, int left, int mid, int right)
{
    std::deque<int> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right)
    {
        if (arr[i] < arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= right)
    {
        temp.push_back(arr[j]);
        j++;
    }

    for (int k = left; k <= right; k++)
    {
        arr[k] = temp.front();
        temp.pop_front();
    }
}

void mergeInsertionSortDeque(std::deque<int> &arr, int left, int right, int k)
{
    if (left < right)
    {
        if (right - left + 1 <= k)
        {
            for (int i = left + 1; i <= right; i++)
            {
                int key = arr[i];
                int j = i - 1;

                while (j >= left && arr[j] > key)
                {
                    arr[j + 1] = arr[j];
                    j--;
                }

                arr[j + 1] = key;
            }
        }
        else
        {
            int mid = left + (right - left) / 2;
            mergeInsertionSortDeque(arr, left, mid, k);
            mergeInsertionSortDeque(arr, mid + 1, right, k);
            mergeDeque(arr, left, mid, right);
        }
    }
}

void mergeInsertionSort(std::deque<int> &arr, int k)
{
    mergeInsertionSortDeque(arr, 0, arr.size() - 1, k);
}