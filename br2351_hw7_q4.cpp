/*Question 4:
 * Implement the function:
 * string* createWordsArray(string sentence, int& outWordsArrSize)
 * This function gets a string sentence containing a sentence.
 * When called, it should create and return a new array (of strings), that contains all the
 * words in sentence. The function should also update the output parameter,
 * outWordsArrSize, with the logical size of the new array that was created.
 * Note: Assume that the words in the sentence are separated by a single space.
 * For example, if sentence=”You can do it”, after calling
 * createWordsArray(sentence, outWordsArrSize), the function should create
 * and return an array that contains [”You” , ”can” , ”do” , ”it”], and update the
 * value in outWordsArrSize to be 4.
 * Implementation requirements:
 * 1. You may want to use some of the string methods, such as find, substr, etc.
 * 2. Your function should run in linear time. That is, if sentence contains n characters,
 * your function should run in 𝜃(𝑛).
 * 3. Write a main() program that tests this function..*/

#include <iostream>
#include <string>
using namespace std;

string* createWordsArray(string sentence, int& outWordsArrSize);
/* Take a sentence and splits the words at the white space. Returns a pointer to a string array
 * where each element is a word from the sentence. Updates outWordsArrSize to number of words in the
 * sentence.
 */

int main() {

    string inputStr;
    string *parseArray;
    int wordCount;

    cout << "Please enter a sentence: " << endl;
    getline(cin, inputStr);

    parseArray = createWordsArray(inputStr, wordCount);

    cout << "[";
    for (int i = 0; i < wordCount; i++) {
        if (i == wordCount - 1)
            cout << "\"" << parseArray[i] << "\"]" << endl;
        else
            cout << "\"" << parseArray[i] << "\", ";
    }

    cout << "Word count: " << wordCount << endl;

    return 0;
}

string* createWordsArray(string sentence, int& outWordsArrSize){

    unsigned int strLength = sentence.length();
    string tempString;
    outWordsArrSize = 0;

    // Get the word count in the sentence
    for (int i = 0; i < strLength; i++){
        if (sentence.at(i) == ' ' || i == strLength - 1){
            outWordsArrSize += 1;
        }
    }

    // Create and fill wordsArray
    string *wordsArray;
    wordsArray = new string[outWordsArrSize];
    for (int i = 0, j = 0; i < strLength; i++){
        if (sentence.at(i) != ' '){
            tempString += sentence.at(i);
            if (i == strLength - 1){
                wordsArray[j] = tempString;
            }
        } else {
            wordsArray[j] = tempString;
            tempString = "";
            j++;
        }
    }
    return wordsArray;
}
