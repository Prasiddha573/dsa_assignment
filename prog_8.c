#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long comparisons = 0;
long swaps = 0;

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
    swaps++;
}

void bubbleSort(int a[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
        {
            comparisons++;
            if (a[j] > a[j + 1])
                swap(&a[j], &a[j + 1]);
        }
}

void selectionSort(int a[], int n)
{
    int i, j, min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            comparisons++;
            if (a[j] < a[min])
                min = j;
        }
        if (min != i)
            swap(&a[i], &a[min]);
    }
}

void insertionSort(int a[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;
        while (j >= 0)
        {
            comparisons++;
            if (a[j] > key)
            {
                a[j + 1] = a[j];
                swaps++;
                j--;
            }
            else
                break;
        }
        a[j + 1] = key;
    }
}

void merge(int a[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[50], R[50];

    for (i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2)
    {
        comparisons++;
        if (L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }

    while (i < n1)
        a[k++] = L[i++];
    while (j < n2)
        a[k++] = R[j++];
}

void mergeSort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main()
{
    int a[100], b[100];
    int n, i, choice;

    scanf("%d", &n);
    srand(time(0));

    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 1000 + 1;
        b[i] = a[i];
    }

    scanf("%d", &choice);

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    if (choice == 1)
        bubbleSort(b, n);
    else if (choice == 2)
        selectionSort(b, n);
    else if (choice == 3)
        insertionSort(b, n);
    else if (choice == 4)
        mergeSort(b, 0, n - 1);

    for (i = 0; i < n; i++)
        printf("%d ", b[i]);
    printf("\n");

    printf("%ld\n", comparisons);
    printf("%ld\n", swaps);

    return 0;
}
