/* Question 6:
In this question, you will write two versions of a program that reads from the user a
sequence of positive integers ending with -1, and another positive integer num that the
user wishes to search for.
The program should then print all the line numbers in sequence entered by the user, that
contain num, or a message saying that num does not show at all in the sequence.
Your program should interact with the user exactly as it shows in the following example:
Please enter a sequence of positive integers, each in a separate line.
End you input by typing -1.
13
5
8
2
9
5
8
8
-1
Please enter a number you want to search:
5
5 shows in lines 2, 6.
a) The first version of the program, is not allowed to use the vector data structure.
b) The second version of the program, should use the vector data structure.
Implementation requirements (for both programs):
1. Think how to break down your implementation to functions.
2. Your programs should run in linear time. That is, if there are n numbers in the input
sequence, your program should run in 𝜃(𝑛).
3. Write the two programs in two functions named main1() and main2(). Also have
the main() test these two functions. */

#include <iostream>
#include <vector>
using namespace std;

int* fillArray(int& outArrSize);
/* Prompts the user for a list of positive integers and stores the values to an array
 * Input parameter: an arbitrary integer variable that will hold the size of the return array
 * Output: an array pointer to and array size equal to number of positive integers entered by user */

int* findInt(const int arr[], int arrSize, int searchInt, int& numResults);
/* Searches an array for a value entered by the user and returns an array with the indices
 * where the value is found in the input array
 * Input parameters: arr[] - the array to be searched. arrSize - the size of the arr[]
 * searchInt - the number being searched for in arr. numResults - holds the number of results
 * found (i.e. the size of the array returned by the function)
 * Output: an array containing the index locations where the search term was found */

void fillVector(vector<int>& inputVect);
/* Prompts the user for a list of positive integers and stores the values to a vector.
 * Input: an empty vector. Output: a vector containing the user entered values */

void main1();
/* Function containing the solution with no use of vectors (uses dynamic arrays) */

void main2();
/* Function containing the solution using vectors */

int main() {

    cout << "Version 1: Function implementation using dynamic arrays" << endl;
    main1();
    cout << endl;

    cout << "Version 2: Function implementation with vectors" << endl;
    main2();
    cout << endl;

    return 0;
}

void main1(){
    int *searchArr;
    int searchArrSize;
    int searchInt;
    int *results;
    int resultsArrSize;

    cout << "Please enter a sequence of positive integers, each in a separate line." << endl;
    cout << "End you input by typing -1." << endl;

    searchArr = fillArray(searchArrSize);

    cout << "Please enter a number you want to search:" << endl;
    cin >> searchInt;
    results = findInt(searchArr, searchArrSize, searchInt, resultsArrSize);

    delete [] searchArr;
    searchArr = nullptr;

    if (resultsArrSize == 1){
        cout << searchInt << " shows in line " << results[0] + 1 << "." << endl;
    } else if (resultsArrSize > 1) {
        cout << searchInt << " shows in lines ";
        for (int i = 0; i < resultsArrSize; i++) {
            if (i != resultsArrSize - 1)
                cout << results[i] + 1 << ", ";
            else
                cout << results[i] + 1 << "." << endl;
        }
    } else
        cout << searchInt << " was not found" << endl;

    delete [] results;
    results = nullptr;
}

void main2(){
    vector<int> searchVect;
    vector<int> resultsVect;
    int searchInt;

    cout << "Please enter a sequence of positive integers, each in a separate line." << endl;
    cout << "End you input by typing -1." << endl;

    fillVector(searchVect);

    cout << "Please enter a number you want to search:" << endl;
    cin >> searchInt;

    for (int i = 0; i < searchVect.size(); i++){
        if (searchVect[i] == searchInt)
            resultsVect.push_back(i);
    }

    if (resultsVect.size() == 1){
        cout << searchInt << " shows in line " << resultsVect[0] + 1 << "." << endl;
    } else if (resultsVect.size() > 1) {
        cout << searchInt << " shows in lines ";
        for (int i = 0; i < resultsVect.size(); i++) {
            if (i != resultsVect.size() - 1)
                cout << resultsVect[i] + 1 << ", ";
            else
                cout << resultsVect[i] + 1 << "." << endl;
        }
    } else
        cout << searchInt << " was not found" << endl;
}

int* fillArray(int& outArrSize){
    int index = 0;
    int inputInt = 0;
    int arrCap = 1;
    int *arr = new int[arrCap];
    bool isNotFinished = true;

    while (isNotFinished) {
        cin >> inputInt;
        if (inputInt == -1)
            isNotFinished = false;
        else {
            if (index == arrCap){
                int *newArr = new int[arrCap * 2];
                for (int i = 0; i < arrCap; i++)
                    newArr[i] = arr[i];
                delete [] arr;
                arr = newArr;
                arrCap *= 2;
            }
            arr[index] = inputInt;
            index++;
        }
    }
    outArrSize = index;
    return arr;
}

int* findInt(const int arr[], int arrSize, int searchInt, int& numResults){
    using namespace std;

    numResults = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == searchInt)
            numResults += 1;
    }

    int *results;
    int index = 0;
    results = new int[numResults];

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == searchInt) {
            results[index] = i;
            if (index != numResults - 1)
                index++;
        }
    }
    return results;
}

void fillVector(vector<int>& inputVect){
    int inputInt;
    bool isNotFinished = true;

    while (isNotFinished) {
        cin >> inputInt;
        if (inputInt == -1)
            isNotFinished = false;
        else {
            inputVect.push_back(inputInt);
        }
    }
}
