/*Question 7:
Implement the function:
int* findMissing(int arr[], int n, int& resArrSize)
This function gets an array of integers arr and its logical size n. All elements in arr are
in the range {0, 1, 2, … , n}.
Note that since the array contains n numbers taken from a range of size n+1, there must
be at least one number that is missing (could be more than one number missing, if there
are duplicate values in arr).
When called, it should create and return a new array, that contains all the numbers in
range {0, 1, 2, … , n} that are not in arr. The function should also update the output
parameter, resArrSize, with the logical size of the new array that was created.
For example, if arr=[3, 1, 3, 0, 6, 4], after calling
findMissing(arr, 6, resArrSize), the function should create and return an
array that contains [2, 5], and update the value in resArrSize to be 2.
Implementation requirements:
1. Your function should run in linear time. That is, it should run in 𝜃(𝑛).
2. Write a main() program that tests this function..*/

#include <iostream>
#include <vector>
using namespace std;

int* findMissing(int arr[], int n, int& resArrSize);

int main() {
    int arr[] = {3, 1, 3, 0, 6, 4, 7, 8, 1, 3};
    int n = 10;
    int *resArr;
    int resArrSize;

    resArr = findMissing(arr, n, resArrSize);

    cout << "Missing values are: [";
    for (int i = 0; i < resArrSize; i++) {
        if (i != resArrSize -1)
            cout << resArr[i] << ", ";
        else
            cout << resArr[i] << "]";
    }
    cout << endl;

    delete [] resArr;
    resArr = nullptr;

    return 0;
}

int* findMissing(int arr[], int n, int& resArrSize) {
    int numEmptyIndex = 0;
    vector<int> missingNum;
    resArrSize = 0;

    int *temp;
    temp = new int[n + 1];
    for (int i = 0; i < n; i++) {
        temp[arr[i]] += 1;
    }

    for (int i = 0; i < (n + 1); i++) {
        if (temp[i] == 0) {
            numEmptyIndex += 1;
            missingNum.push_back(i);
        }
    }

    delete [] temp;
    temp = nullptr;

    int *resArr;
    resArr = new int[numEmptyIndex];
    resArrSize = numEmptyIndex;
    for (int i = 0; i < missingNum.size(); i++){
        resArr[i] = missingNum[i];
    }

    return resArr;
}