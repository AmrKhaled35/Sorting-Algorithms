#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
template<typename T>
void BucketSort(T* arr, ll sz) {
    T** arr2 = new T*[10];
    for (ll i = 0; i < 10; i++) {
        arr2[i] = new T[10];
    }
    ll* idx = new ll[10];
    for (ll i = 0; i < 10; i++) {
        idx[i] = 0;
    }
    for (ll i = 1; i < sz; i++) {
        ll j ;
        // float num = arr[i - 1] * 10 ;
        // int id = (int) num   ;
        string s = to_string(arr[i - 1]);
        for (char c : s) {
            if (isdigit(c) && c != '0') {
                j = c - '0';
                break;
            }
        }

        arr2[j][idx[j]] = arr[i - 1];
        idx[j]++;
    }

    for (ll i = 0; i < 10; i++) {
        for (ll j = 1; j < idx[i]; ++j) {
            T s = arr2[i][j];
            ll k = j - 1;
            while (k >= 0 && arr2[i][k] > s) {
                arr2[i][k + 1] = arr2[i][k];
                k--;
            }
            arr2[i][k + 1] = s;
        }
    }
    for (int i = 0; i <= 9; i++) {
        cout << "arr2[" << i << "]: ";
        for (int j = 0; j < idx[i]; j++) {
            cout << arr2[i][j] << " ";
        }
        if (idx[i] == 0) cout << " ";
        cout << endl;
    }
    for (ll i = 0; i < 10; i++) {
        delete[] arr2[i];
    }
    delete[] arr2;
    delete[] idx;
}

int main() {
    float arr[] = {0.75, 0.88, .99};
    BucketSort(arr, 3);

    return 0;
}
