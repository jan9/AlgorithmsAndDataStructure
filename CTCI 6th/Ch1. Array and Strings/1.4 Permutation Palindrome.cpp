//
//  main.cpp
//  CTCI
//
//  Created by Ju An on 1/4/19
//  Copyright © 2019 juhye. All rights reserved.

// 1.4 Palindrome Permutation:
// Given a string, write a functino to check if it is a permutation of a palindrome.
// A palindrome is a word or phrase that is the same forwards and backwards.
// A permutation is a rearrangement of lettters. The palindrome does not need to be limited to just dicitonary words
// Example: Input Tact Coa
//          Output True (permutations: "taco cat", "atco cta", etc)

// Hints:
// 106: you shouldn't generate all permutations
// 121: what characteristics would a string that is a permutation of a palindrome have?
// 134: Hash table will get to O(n)
// 136: Can you reduce the space usage by using a bit vector?

// Reference: https://github.com/careercup/CtCI-6th-Edition-cpp/blob/master/Ch%201.Arrays%20And%20Strings/4.Palindrome_Permutation/4-pallindrome-permutations.cpp

#include <iostream>
#include <string>
using namespace std;

// My version O(n^2)
// my algorithm is not correct
// trying to found the number of letters
bool checkPermutationPalindrome (string s) {
    int pairCount = 0;
    string newS = s;
    //sort(newS.begin(), newS.end());
    char currentChar;
    for (int i=0; i < 2; i++) {
        currentChar = newS[i];
        for (int j= i+1; j < newS.length(); j++) {
            cout << currentChar << ", " << newS[j] << endl;
            if (newS[j] == currentChar) {
                pairCount++;
                
            }
        }
    }
    cout << pairCount << endl;
    
    if (2*pairCount+1 == s.length() || 2*pairCount == s.length()) {
        return true;
    }
    return false;
}

/*
int getCharIndex (char c) {
    int idx = -1;
    if (c >= 'a' && c <= 'z') {
        idx = c-'a';
    } else if (c >= 'A' && c <= 'Z') {
        idx = c-'A';
    }
    return idx;
}

void countFrequencey (const string & str, int *frequency) {
    int idx;
    for (const char & c: str) {
        idx = getCharIndex(c);
        if (idx != -1) {
            ++frequency[idx];
        }
    }
}
bool checkPermutationPalindrome (const string & str) {
    int frequency[26]={0};
    countFrequencey(str, frequency);
    
    bool oddAppeared = false;
    cout << endl;
    for (int i = 0; i < 26; ++i) {
        if (frequency[i]%2 && oddAppeared) {
            return false;
        } else if (frequency[i]%2&&!oddAppeared) {
            oddAppeared = true;
        }
    }
    return true;
}
*/

//driver
int main() {
    string input1 = "tactcoapapa";
   
    if (checkPermutationPalindrome(input1)) {
        cout << "It is a permutation palindrome" << endl;
    } else {
        cout << "It is NOT a permutation palindrome" << endl;
    }
    return 0;
}
