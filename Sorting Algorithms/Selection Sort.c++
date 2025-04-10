#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
template<typename T>
void SelectionSort(T *arr , int n) {
    for (int i = 0; i < n - 1; i++) {  
        int minl = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minl]) {
                minl = j;  
            }
        }
        swap(arr[i], arr[minl]);  
    }
}

int main() {
    int arr[] = {10, 1, 3, 4, 6, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Array before sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    SelectionSort(arr , n);

    cout << "Array after sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
