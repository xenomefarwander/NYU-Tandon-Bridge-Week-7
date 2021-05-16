/* Question 2:
 * Two strings are anagrams if the letters can be rearranged to form each other. For example,
 * “Eleven plus two” is an anagram of “Twelve plus one”. Each string contains one ‘v’, three ‘e’s,
 * two ‘l’s, etc.
 * Write a program that determines if two strings are anagrams. The program should not be case
 * sensitive and should disregard any punctuation or spaces. */

#include <iostream>
#include <cctype>
using namespace std;

void getString(char userString[], int& arrSize);

void parseText(char userString[], int arrSize, int letterCount[], int& wordCount);

void countLetters(char letter, int letterCount[]);

bool isWord(char str[], int strLength);

bool isIdentical(const int arr1[], const int arr2[]);

void initializeArrayToZero(int arr[], int arrSize);

int main() {
    const int ALPHABET = 26;
    const int LINE = 256;

    char userStringA[LINE], userStringB[LINE];
    int userStringSizeA = LINE, userStringSizeB = LINE;
    int letterCountA[ALPHABET], letterCountB[ALPHABET];
    int letterCountSize = ALPHABET;
    int wordCountA = 0, wordCountB = 0;

    initializeArrayToZero(letterCountA, letterCountSize);
    initializeArrayToZero(letterCountB, letterCountSize);

    // Get text for StringA from the user
    cout << "Anagram Tester" << endl;
    cout << "Enter two lines of text to test whether they are anagrams" << endl;
    cout << "Please enter line 1: " << endl;
    getString(userStringA, userStringSizeA);

    cout << "Please enter line 2:" << endl;
    getString(userStringB, userStringSizeB);

    // Read in the user's text, count the words and the letters, update letterCount and wordCount
    parseText(userStringA, userStringSizeA, letterCountA, wordCountA);
    parseText(userStringB, userStringSizeB, letterCountB, wordCountB);

    // Compare letter counts (anagrams have identical letter counts) and print results to user
    if (isIdentical(letterCountA, letterCountB))
        cout << "The two strings are anagrams" << endl;
    else
        cout << "The two strings are NOT anagrams" << endl;

    return 0;
}

void getString(char userString[], int& arrSize){
    using namespace std;

    char nextChar;
    cin.get(nextChar);
    int index = 0;
    arrSize = 255; //  Prevents overflow from user
    while (index < arrSize && nextChar != '\n'){
        userString[index] = nextChar;
        index++;
        cin.get(nextChar);
    }
    userString[index] = '\0';
    arrSize = index + 1;
}

void parseText(char userString[], int arrSize, int letterCount[], int& wordCount){
    using namespace std;

    char testString[256];

    int i = 0; // i counts total length of string
    int j = 0; // j counts length of each word

    while (i < arrSize){
        // Build testString until one of following character is encountered
        if (userString[i] != ' '
            && userString[i] != ','
            && userString[i] != '.'
            && userString[i] != '\0') {
            testString[j] = userString[i];
            // Add each letter count to an inventory
            countLetters(userString[i], letterCount);
            j++;
        }
        else {
            //Add word to wordCount
            if (isWord(testString, j))
                wordCount++;

            // Reset j to 0 (i.e. start a new word)
            j = 0;
        }
        i++;
    }
}

void countLetters(char letter, int letterCount[]){
    using namespace std;

    int asciiVal;
    int valLowerCaseA = tolower('a');

    // Convert letter to lowercase
    asciiVal = tolower(letter) - valLowerCaseA;

    // Increment letter count in the array
    letterCount[asciiVal] += 1;
}

bool isWord(char str[], int strLength){
    using namespace std;

    for (int i = 0; i < strLength; i++) {
        if (isalpha(str[i])){
            return true;
        }
    }
    return false;
}

void initializeArrayToZero(int arr[], int arrSize) {
    for (int i = 0; i < arrSize; i++)
        arr[i] = 0;
}

bool isIdentical(const int arr1[], const int arr2[]){
    using namespace std;

    const int ALPHABET = 26;

    for (int i = 0; i < ALPHABET; i++) {
        if (arr1[i] != arr2[i])
            return false;
    }
    return true;
}