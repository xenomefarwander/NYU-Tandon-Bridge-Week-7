/* Question 5:
 * In this question, you will write four versions of a function getPosNums that gets an
 * array of integers arr, and its logical size. When called it creates a new array containing
 * only the positive numbers from arr.
 * For example, if arr=[3, -1, -3, 0, 6, 4], the functions should create an array
 * containing the following 3 elements: [3, 6, 4],
 * The four versions you should implement differ in the way the output is returned.
 * The prototypes of the functions are:
 * a) int* getPosNums1(int* arr, int arrSize, int& outPosArrSize)
 * returns the base address of the array (containing the positive numbers), and updates
 * the output parameter outPosArrSize with the array’s logical size.
 * b) int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr)
 * returns the base address of the array (containing the positive numbers), and uses
 * the pointer outPosArrSizePtr to update the array’s logical size.
 * c) void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize)
 * updates the output parameter outPosArr with the base address of the array
 * (containing the positive numbers), and the output parameter outPosArrSize with
 * the array’s logical size.
 * d) void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr)
 * uses the pointer outPosArrPtr to update the base address of the array (containing
 * the positive numbers), and the pointer outPosArrSizePtr to update the array’s
 * logical size.
 * Note: You should also write a program that calls and tests all these functions.*/

#include <iostream>
#include <vector>
using namespace std;

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
/* Returns the base address of the array (containing the positive numbers), and updates
 * the output parameter outPosArrSize with the array’s logical size. */

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);
/* Returns the base address of the array (containing the positive numbers), and uses
 * the pointer outPosArrSizePtr to update the array’s logical size. */

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
/* Updates the output parameter outPosArr with the base address of the array
 * (containing the positive numbers), and the output parameter outPosArrSize with
 * the array’s logical size. */

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);
/* Uses the pointer outPosArrPtr to update the base address of the array (containing
 * the positive numbers), and the pointer outPosArrSizePtr to update the array’s
 * logical size. */


int main() {

    int arr[] = {3, -1, -3, 0, 6, 4};
    int arrSize = 6;
    int arr2[] = {1, -2 , 3, -5, 10};
    int arrSize2 = 5;
    int arr3[] = {8, -6 , 1, -9, 15, 18, 51, -66};
    int arrSize3 = 8;
    int arr4[] = {7, -4 , 22};
    int arrSize4 = 3;
    int *posNumsArr1, *posNumsArr2, *posNumsArr3, *posNumsArr4;
    int posNumArrSize1 = 0, posNumArrSize2 = 0, posNumArrSize3 = 0, posNumArrSize4 = 0;

    posNumsArr1 = getPosNums1(arr, arrSize, posNumArrSize1);
    posNumsArr2 = getPosNums2(arr2, arrSize2, &posNumArrSize2);
    getPosNums3(arr3, arrSize3, posNumsArr3, posNumArrSize3);
    getPosNums4(arr4, arrSize4, &posNumsArr4, &posNumArrSize4);

    cout << "Size Arr 1: " << posNumArrSize1 << endl;
    for (int i = 0; i < posNumArrSize1; i++) {
        cout << "Val " << i << ": " << posNumsArr1[i] << endl;
    }
    delete [] posNumsArr1;
    posNumsArr1 = NULL;
    cout << endl;

    cout << "Size Arr 2: " << posNumArrSize2 << endl;
    for (int i = 0; i < posNumArrSize2; i++) {
        cout << "Val " << i << ": " << posNumsArr2[i] << endl;
    }
    delete [] posNumsArr2;
    posNumsArr2 = NULL;
    cout << endl;

    cout << "Size Arr 3: " << posNumArrSize3 << endl;
    for (int i = 0; i < posNumArrSize3; i++) {
        cout << "Val " << i << ": " << posNumsArr3[i] << endl;
    }
    delete [] posNumsArr3;
    posNumsArr3 = NULL;
    cout << endl;

    cout << "Size Arr 4: " << posNumArrSize4 << endl;
    for (int i = 0; i < posNumArrSize4; i++){
        cout << "Val " << i << ": " << posNumsArr4[i] << endl;
    }
    delete [] posNumsArr4;
    posNumsArr4 = NULL;

    return 0;
}


int* getPosNums1(int* arr, int arrSize, int& outPosArrSize){

    int posNumCount = 0;

    // Count positive numbers
    for(int i = 0; i < arrSize; i++){
        if (arr[i] > 0)
            posNumCount += 1;
    }

    // Create new array
    int *posArr1;
    posArr1 = new int[posNumCount];
    for (int i = 0, j = 0; i < arrSize; i++){
        if (arr[i] > 0) {
            posArr1[j] = arr[i];
            if (j != posNumCount - 1)
                j++;
        }
    }

    // Update outPosArrSize variable and return
    outPosArrSize = posNumCount;
    return posArr1;
}

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr) {
    /* Returns the base address of the array (containing the positive numbers), and uses
     * the pointer outPosArrSizePtr to update the array’s logical size. */

    int posNumCount = 0;

    // Count positive numbers
    for(int i = 0; i < arrSize; i++){
        if (arr[i] > 0)
            posNumCount += 1;
    }

    // Create new array
    int *posArr2;
    posArr2 = new int[posNumCount];
    for (int i = 0, j = 0; i < arrSize; i++){
        if (arr[i] > 0) {
            posArr2[j] = arr[i];
            if (j != posNumCount - 1)
                j++;
        }
    }

    // Update outPosArrSizePtr variable and return
    *outPosArrSizePtr = posNumCount;
    return posArr2;
}

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize){
    /* Updates the output parameter outPosArr with the base address of the array
     * (containing the positive numbers), and the output parameter outPosArrSize with
     * the array’s logical size. */

    int posNumCount = 0;

    // Count positive numbers
    for(int i = 0; i < arrSize; i++){
        if (arr[i] > 0)
            posNumCount += 1;
    }

    // Create new array
    int *posArr3;
    posArr3 = new int[posNumCount];
    for (int i = 0, j = 0; i < arrSize; i++){
        if (arr[i] > 0) {
            posArr3[j] = arr[i];
            if (j != posNumCount - 1)
                j++;
        }
    }

    // Update outPosArrSize and outPosArr variables and return
    outPosArrSize = posNumCount;
    outPosArr = posArr3;
}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr){
    /* Uses the pointer outPosArrPtr to update the base address of the array (containing
    * the positive numbers), and the pointer outPosArrSizePtr to update the array’s
    * logical size. */

    int posNumCount = 0;

    // Count positive numbers
    for(int i = 0; i < arrSize; i++){
        if (arr[i] > 0)
            posNumCount += 1;
    }

    // Create new array
    int *posArr4;
    posArr4 = new int[posNumCount];
    for (int i = 0, j = 0; i < arrSize; i++){
        if (arr[i] > 0) {
            posArr4[j] = arr[i];
            if (j != posNumCount - 1)
                j++;
        }
    }

    // Update outPosArrSize and outPosArr variables and return
    *outPosArrSizePtr = posNumCount;
    *outPosArrPtr = posArr4;
}
