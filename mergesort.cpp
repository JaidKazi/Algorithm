#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, int left, int mid, int right) {
    std::vector<int> left_arr(arr.begin() + left, arr.begin() + mid);
    std::vector<int> right_arr(arr.begin() + mid, arr.begin() + right);

    int i = 0, j = 0, k = left;

    while (i < left_arr.size() && j < right_arr.size()) {
        if (left_arr[i] <= right_arr[j]) {
            arr[k++] = left_arr[i++];
        } else {
            arr[k++] = right_arr[j++];
        }
    }

    while (i < left_arr.size()) {
        arr[k++] = left_arr[i++];
    }

    while (j < right_arr.size()) {
        arr[k++] = right_arr[j++];
    }
}

void merge_sort(std::vector<int>& arr, int n) {
    for (int width = 1; width < n; width *= 2) {
        for (int left = 0; left < n; left += 2 * width) {
            int mid = left + width;
            int right = std::min(mid + width, n);
            if (mid < right) {
                merge(arr, left, mid, right);
            }
        }
    }
}

int main() {
    std::vector<int> arr = {5, 2, 8, 3, 1, 6, 4};
    int n = arr.size();

    merge_sort(arr, n);

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
