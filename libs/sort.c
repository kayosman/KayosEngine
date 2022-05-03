#include <stdio.h>
#include "sort.h"

int main()
{
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: "); 
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter the choice of sorting algorithm: \n1. Bubble Sort\n2. Insertion Sort\n3. Selection Sort\n4. Merge Sort\n5. Quick Sort\n6. Heap Sort\n7. Counting Sort\n8. Bucket Sort\n");
    int choice;
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        "Bubble Sort: \n";
        bubbleSort(arr, n);
        break;
    case 2:
        "Insertion Sort: \n";
        insertionSort(arr, n);
        break;
    case 3:
        "Selection Sort: \n";
        selectionSort(arr, n);
        break;
    case 4:
        "Merge Sort: \n";
        mergeSort(arr, 0, n - 1);
        break;
    case 5:
        "Quick Sort: \n";
        quickSort(arr, 0, n - 1);
        break;
    case 6:
        "Heap Sort: \n";
        heapSort(arr, n);
        break;
    case 7:
        "Counting Sort: \n";
        countingSort(arr, n);
        break;
    case 8:
        "Bucket Sort: \n";
        bucketSort(arr, n);
        break;
    default:
        "Wrong choice\n";
    }
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}