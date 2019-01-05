//
//  main.cpp
//  CTCI
//
//  Created by Ju An on 1/4/19
//  Copyright © 2019 juhye. All rights reserved.

// 1.3 URLify: Write a method to replace all spaces in a string with '%20'.
// May assume that the string has sufficient space at the end to hold the additional characters
//            tha you are given the "true" length of the string
// Example: Input "Mr John Smith    ", 13
//          Output "Mr%20John%20Smith"

// Hint:
// it's easiest to modify strings by going from the end of the string to the beginning
// you might find you need to know the number of spaces. Can you just count them?

#include <iostream>
#include <string>
using namespace std;

string modifyStr(string s, int sLength) {
    // count the number of spaces within the true length of the string
    
    int spaces = 0;
    for (int i = 0; i < sLength; i++) {
        if(s[i] == ' ') {
            spaces++;
        }
    }
   
    // triple the number to include '%20' but WHY 2?
    //   b.c. there is already a space available for each '%20'
    //   so we need 2 more spaces each
    int newLength = sLength + spaces*2;
    
    if(sLength < s.length()) { s[sLength] = '\0'; } // terminante the excess spaces
    
    // backward
    for (int j = sLength -1; j >=0; j--) {
        if (s[j] == ' ') {
            cout << newLength << " (filling space)" << endl;
            s[newLength-1] = '0';
            s[newLength-2] = '2';
            s[newLength-3] = '%';
            newLength = newLength -3;
        } else {
            cout << newLength << endl;
            s[newLength-1] = s[j];
            newLength--;
        }
    }
    
    return s;
}

//driver
int main() {
    string input1 = "Mr John Smith    ";
    int str_true_len = 13;
    cout << modifyStr(input1, str_true_len) << endl;
    return 0;
}
