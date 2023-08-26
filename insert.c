#include <stdio.h>

// Function to insert an element into the array
int insert(int arr[], int size, int element, int position) {
    if (position < 0 || position > size) {
        printf("Invalid position for insertion\n");
        return size;
    }

    for (int i = size - 1; i >= position; i--) {
        arr[i + 1] = arr[i];
    }

    arr[position] = element;
    return size + 1;
}

// Function to delete an element from the array
intdelete(int arr[], int size, int position) {
    if (position < 0 || position >= size) {
        printf("Invalid position for deletion\n");
        return size;
    }

    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    return size - 1;
}

// Function to display the elements of the array
void display(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[100];
    int size = 0;

    size = insert(arr, size, 10, 0);
    size = insert(arr, size, 20, 1);
    size = insert(arr, size, 30, 2);

    printf("After insertion:\n");
    display(arr,size);
    printf("After deletion:\n");
    display(arr, size);

    return 0;
}
