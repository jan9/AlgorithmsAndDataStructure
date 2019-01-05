//
//  main.cpp
//  CTCI
//
//  Created by Ju An on 1/4/19
//  Copyright © 2019 juhye. All rights reserved.

// 1.2 Check Permutation:
// Given two strings, write a amethod to decide if one is
// a permutation of the other

// hints:
//  hashtable; two strings that are permutations should have the same characters,
//  but in different orders. Can you make the orders the same?

#include <iostream>
using namespace std;

bool checkPermutation(string s1, string s2) {
    // if the lengths of the two strings are not equal
    // return false;
    if (s1.length() != s2.length()) { return false; }
    
    // sort each string and compare the two strings
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    //cout << s1 << endl << s2 << endl;
    if (s1 == s2) { return true; }
    for(int i = 0; i < s1.length(); i++) {
        if(s1[i] != s2[i]) { return false; }
    }
    return false;
}

//driver
int main() {
    string input1 = "tella";
    string input2 = "tella";
    if (checkPermutation(input1, input2)) {
        cout << "The strings are permutations of the other" << endl;
    } else {
        cout << "The strings are not permutations of the other" << endl;
    }
    
    return 0;
}
