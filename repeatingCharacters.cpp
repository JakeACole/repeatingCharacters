// Author: Jake A. Cole, Date: 8/29/2015
// repeatingCharacters finds the word with the most repeated characters in a sample of text

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
void findRpt(string txtFile);

int main() {
	cout << "Jake A. Cole, repeating characters programming problem: " << endl << endl;
    findRpt("input.txt");
	return 0;
}

// ------------------------------------------------------------------
// findRpt finds the word with the most repeating characters
// parameter txtFile: a string with the name of an input text file
void findRpt(string txtFile) {
    ifstream infile;

    string load = "";
    string input = "";
    string outputStr = "";

    //starts at -1 because the substr() can use the index 0 for the first word in the sample
    int wordStart = -1;
    int wordLen = 0, curRpt = 0, maxRpt = 0;
    int alphaCount[26] = {0};

    //Opens the input file input.txt
    infile.open(txtFile);
    while(!infile.eof()) {
        getline(infile, load);
        input.append(load);
    }
    input.append("\n");

    for (int i = 0; i < input.length(); i++ ) {

        //if the input is a character, the respective letter is incremented
        if (isalpha(input[i])) {
            alphaCount[tolower(input[i]) - 97]++;
            if (wordStart == -1) {
                wordStart = i;
            }
            wordLen++;
        }

        //45 is ascii for hyphen and 96 is ascii for apostrophe
        else if (input[i] == 96 || input[i] == 45) {
            wordLen++;
        }

        //accounts for all ascii characters that are not letters, hyphens, or apostrophes
        else if (input[i] < 45 || (input[i] > 45 && input[i] < 96) || (input[i] > 122 && input[i] < 127)) {

            for (int j = 0; j < 26; j++ ) {
                if (alphaCount[j] > curRpt) {
                    curRpt = alphaCount[j];
                }
            }

            //if a word has more repeated characters than the
            //previous max it is chosen as the new max
            if (curRpt > maxRpt) {
                maxRpt = curRpt;
                outputStr = input.substr(wordStart, wordLen);
            }

            curRpt = 0;
            wordStart = -1;
            wordLen = 0;

            //zeroes out the array alphaCount
            memset(alphaCount, 0, sizeof(alphaCount));
        }
    }

    if (outputStr == "") {
        cout << "No valid input was found" << endl;
    }

    else {
        cout << "The output word is: " << outputStr << endl;
    }

    return;
}

/* ----------------------------------------------
Results for both examples:

Input: "O Romeo, Romeo, wherefore art thou Romeo?"

Jake A. Cole, repeating characters programming problem:

The output word is: wherefore

Process returned 0 (0x0)   execution time : 0.014 s
Press any key to continue.

Input: "Some people feel the rain, while others just get wet."

Jake A. Cole, repeating characters programming problem:

The output word is: people

Process returned 0 (0x0)   execution time : 0.011 s
Press any key to continue.
----------------------------------------------- */


