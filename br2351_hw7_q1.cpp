/* Question 1:
 * Write a program that will read in a line of text and output the number of words in the line and
 * the number of occurrences of each letter.
 * Define a word to be any string of letters that is delimited at each end by either whitespace, a
 * period, a comma, or the beginning or end of the line.
 * You can assume that the input consists entirely of letters, whitespace, commas, and periods.
 * When outputting the number of letters that occur in a line, be sure to count upper and
 * lowercase versions of a letter as the same letter.
 * Output the letters in alphabetical order and list only those letters that do occur in the input line.
 * Your program should interact with the user exactly as it shows in the following example:
 * Please enter a line of text:
 * I say Hi.
 * 3 words
 * 1 a
 * 1 h
 * 2 i
 * 1 s
 * 1 y
 */

void getString(char userString[], int& arrSize);

void parseText(char userString[], int arrSize, int letterCount[], int& wordCount);

void countLetters(char letter, int letterCount[]);

bool isWord(char str[], int strLength);

void initializeArrayToZero(int arr[], int arrSize);

#include <iostream>
#include <cctype>
using namespace std;

int main() {
    const int ALPHABET = 26;
    const int LINE = 256;

    char userString[LINE];
    int userStringSize = LINE;
    int letterCount[ALPHABET];
    int letterCountSize = ALPHABET;
    int wordCount = 0;
    char currChar;

    initializeArrayToZero(letterCount, letterCountSize);

    // Get text from the user
    cout << "Please enter a line of text:" << endl;
    getString(userString, userStringSize);

    // Read in the user's text, count the words and the letters
    parseText(userString, userStringSize, letterCount, wordCount);

    // Output word count and letter count
    cout << wordCount << "\twords" << endl;
    for (int i = 0; i < ALPHABET; i++){
        if (letterCount[i] != 0){
            currChar = static_cast<char>(i + 97); // 97 is ascii val for 'a'
            cout << currChar << '\t' << letterCount[i] << endl;
        }
    }
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

void initializeArrayToZero(int *arr, int arrSize) {
    for (int i = 0; i < arrSize; i++)
        arr[i] = 0;
}
