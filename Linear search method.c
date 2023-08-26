#include <stdio.h>

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the index where the target was found
        }
    }
    return -1; // Return -1 if the target was not found
}

int main() {
    int arr[] = {12, 45, 67, 89, 34, 56, 23, 78, 91, 31};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 56;

    int index = linearSearch(arr, size, target);

    if (index != -1) {
        printf("Element %d found at index %d.\n", target, index);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}
