#include <iostream>
#include <algorithm>

template<typename T>
void bubble_sort(T* arr, int len) {
    int i, j;
    for (i = 0; i < len - 1; ++i) {
        for (j = 0; j < len - 1 - i; ++j) {
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
        }
    }
}

template<typename T>
void selection_sort(T* arr, int len) {
    for (int i = 0; i < len - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < len; ++j) {
            if (arr[j] < arr[min])
                min = j;
        }
        std::swap(arr[min], arr[i]);
    }
}

template<typename T>
void insertion_sort(T* arr, int len) {
    for (int i = 1; i < len; ++i) {
        int j = i - 1;
        T key = arr[i];
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        // 注意当前得到的数字为小于key的下标
        arr[j + 1] = key;
    }
}

template<typename T>
void shell_sort(T* arr, int len) {
    int h = 1;
    while (h < len / 3) {
        h = 3 * h + 1;
    }
    while (h >= 1) {
        for (int i = h; i < len; i += h) {
            for (int j = i; j >= h && arr[j] < arr[j - h]; j -= h) {
                std::swap(arr[j], arr[j - h]);
            }
        }
        h = h / 3;
    }
}

// 归并算法
// 迭代方法
template<typename T>
void merge_sort(T* arr, int len) {
    T* a = arr;
    T* b = new T[len];
    for (int seg = 1; seg < len; seg += seg) {
        for (int start = 0; start < len; start += seg + seg) {
            int low = start, mid = std::min(start + seg, len), high = std::min(start + seg + seg, len);
            int k = low;
            int start1 = low, end1 = mid;
            int start2 = mid, end2 = high;
            while (start1 < end1 && start2 < end2)
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
            while (start1 < end1)
                b[k++] = a[start1++];
            while (start2 < end2)
                b[k++] = a[start2++];
        }
        T *temp = a;
        a = b;
        b = temp;
    }
    if (a != arr) {
        for (int i = 0; i < len; i++)
            b[i] = a[i];
        b = a;
    }
    delete[] b;
}

// 快排
template<typename T>
void quick_sort_recursive(T* arr, int start, int end) {
    if (start >= end) {
        return;
    }
    T mid = arr[end];
    int left = start, right = end - 1;
    while (left < right) {
        while (left < right && arr[left] < mid) {
            left += 1;
        }
        while (left < right && arr[right] >= mid) {
            right -= 1;
        }
        std::swap(arr[left], arr[right]);
    }
    if (arr[left] >= arr[end]) {
        std::swap(arr[left], arr[end]);
    }
    else {
        left++;
    }
    quick_sort_recursive(arr, start, left - 1);
    quick_sort_recursive(arr, left + 1, end);
}
template<typename T>
void quick_sort(T* arr, int len) {
    quick_sort_recursive(arr, 0, len - 1);
}

int main() {
    int arr[] = { 61, 17, 29, 22, 34, 60, 72, 21, 50, 1, 62 };
    int len = (int) sizeof(arr) / sizeof(*arr);
    quick_sort(arr, len);
    for (int i = 0; i < len; i++)
        std::cout << arr[i] << ' ';
    std::cout << std::endl;
    float arrf[] = { 17.5, 19.1, 0.6, 1.9, 10.5, 12.4, 3.8, 19.7, 1.5, 25.4, 28.6, 4.4, 23.8, 5.4 };
    len = (float) sizeof(arrf) / sizeof(*arrf);
    quick_sort(arrf, len);
    for (int i = 0; i < len; i++)
        std::cout << arrf[i] << ' '<< std::endl;
    return 0;
}
