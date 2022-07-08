//Erkin Aydın 22002956

#include <bits/stdc++.h>
using namespace std;

bool binarySearch( int arr1[], int low, int high, int x);
int partition( int A, int si, int ei);
void exchange( int a, int b);
bool algorithm1( int arr1[], int arr2[], int size1, int size2);
bool algorithm2( int arr1[], int arr2[], int size1, int size2);
bool algorithm3( int arr1[], int arr2[], int size1, int size2);

int main() {
        for(int j = 1; j <= 10; j++) {
            int size_arr1 = j * 10000000;//10^7
            int size_arr2 = 10000;//Change this to change m value
            int *arr1 = new int[size_arr1];
            srand(time(0));
            for (int i = 0; i < size_arr1; i++) {
                arr1[i] = i;
            }
            int *arr2 = new int[size_arr2];
            for (int i = 0; i < size_arr2; i++) {
                arr2[i] = rand() % size_arr1 + 1;
            }
            clock_t startTime1 = clock();
            bool result1 = algorithm1(arr1, arr2, size_arr1, size_arr2);
            double duration1 = 1000 * double(clock() - startTime1) / CLOCKS_PER_SEC;
            cout << "For n = " << j << " Algorithm 1 took " << duration1 << "ms" << endl;

            bool result3 = algorithm3(arr1, arr2, size_arr1, size_arr2);
            sort(arr1, arr1 + size_arr1);
            clock_t startTime2 = clock();
            bool result2 = algorithm2(arr1, arr2, size_arr1, size_arr2);
            double duration2 = 1000 * double(clock() - startTime2) / CLOCKS_PER_SEC;
            cout << "For n = " << j << " Algorithm 2 took " << duration2 << "ms" << endl;
            cout << "==============================================================================" << endl;

            delete[] arr2;
            delete[] arr1;
        }
        return 0;
}


bool binarySearch(int arr1[], int low, int high, int x) {
    if (high >= low)
    {
        int mid = (low + high) / 2;
        if ((mid == 0 || x > arr1[mid - 1]) && (arr1[mid] == x))
            return mid;
        else if (x > arr1[mid])
            return binarySearch(arr1, (mid + 1), high, x);
        else
            return binarySearch(arr1, low, (mid - 1), x);
    }
    return -1;
}

bool algorithm1( int arr1[], int arr2[], int size1, int size2) {
    int i = 0;
    int j = 0;
    for (i = 0; i < size2; i++) {
        for (j = 0; j < size1; j++) {
            if (arr2[i] == arr1[j])
                break;
        }
        if (j == size1)
            return 0;
    }
    return 1;
}

bool algorithm2( int arr1[], int arr2[], int size1, int size2) {
    int i = 0;
    for (i = 0; i < size2; i++) {
        if (binarySearch(arr1, 0, size1 - 1,arr2[i]) == -1)
            return 0;
    }
    return 1;
}

bool algorithm3( int arr1[], int arr2[], int size1, int size2) {
    bool result = true;
    double duration;
    int* frequency = new int[size1];
    clock_t startTime = clock();
        for (int i = 0; i < size1; i++) {
            frequency[arr1[i]]++;
        }
        for (int j = 0; j < size2; j++) {
            if (frequency[arr2[j]] > 0) {
                frequency[arr2[j]]--;
            } else {
                result = false;
            }
        }
    duration = 1000 * double( clock() - startTime )  / CLOCKS_PER_SEC;
    cout << "Algorithm 3 took " << duration << " milliseconds." << endl;
    delete[] frequency;
    return result;
}
