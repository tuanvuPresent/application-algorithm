#include <iostream>

using namespace std;
float arr[1000000] = { 0 };

void quickSort(float arr[], int left, int right)
{
    if (left < right) {
        //patition
        int pos = left + 1;
        for (int i = left + 1; i <= right; i++) {
            if (arr[i] < arr[left]) {
                //swap
                float temp = arr[i];
                arr[i] = arr[pos];
                arr[pos] = temp;

                pos++;
            }
        }
        //swap
        float temp = arr[left];
        arr[left] = arr[pos - 1];
        arr[pos - 1] = temp;

        //
        if (left < pos - 2) {
            quickSort(arr, left, pos - 2);
        }
        if (pos < right) {
            quickSort(arr, pos, right);
        }
    }
}

int main()
{

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    return 0;
}
