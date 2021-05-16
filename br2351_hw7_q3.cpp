/*Question 3:
 * Implement the function:
 * void oddsKeepEvensFlip(int arr[], int arrSize)
 * This function gets an array of integers arr and its logical size arrSize.
 * When called, it should reorder the elements of arr so that:
 * 1. All the odd numbers come before all the even numbers
 * 2. The odd numbers will keep their original relative order
 * 3. The even numbers will be placed in a reversed order (relative to their original order).
 * For example, if arr = [5, 2, 11, 7, 6, 4],
 * after calling oddsKeepEvensFlip(arr, 6), arr will be:
 * [5, 11, 7, 4, 6, 2]
 * Implementation requirements:
 * 1. Your function should run in linear time. That is, if there are n items in arr, calling
 * oddsKeepEvensFlip(arr, n) will run in 𝜃(𝑛).
 * 2. Write a main() program that tests this function.
 * 3. Note that at the end, the elements should be stored starting at the same base
 * address, as was given in arr. (i.e. do not create new array) */

#include <iostream>
#include <vector>
using namespace std;

void oddsKeepEvensFlip(int arr[], int n);

int main() {

    int inputArr[] = {5, 2, 8, 11, 7, 6, 4};
    int inputArrSize = 7;

    oddsKeepEvensFlip(inputArr, inputArrSize);

    for (int i = 0; i < inputArrSize; i++){
        cout << inputArr[i] << " ";
    }

    return 0;
}

void oddsKeepEvensFlip(int arr[], int n){

    vector<int> oddsTemp, evensTemp;
    unsigned int i, j;

    // Separate odds and evens into two vectors in order of appearance
    for (i = 0; i < n; i++){
        if (arr[i] % 2 == 1) {
            oddsTemp.push_back(arr[i]);
        }
        else {
            evensTemp.push_back(arr[i]);
        }
    }

    // Replace the first oddsTemp.size{} number vals in arr[i] with the values from the odds vector,
    for (i = 0; i < oddsTemp.size(); i++){
        arr[i] = oddsTemp[i];
    }

    // Starting at arr[i], now reverse order of evensTemp into arr[i]
    for (j = evensTemp.size() - 1; i < n; i++, j--){
        arr[i] = evensTemp[j];
    }

}
