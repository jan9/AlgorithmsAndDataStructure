//
//  main.cpp
//  CTCI
//
//  Created by Ju An on 7/18/18.
//  Copyright © 2018 juhye. All rights reserved.
// ch1.1: Implement an algorithm to determine if a string
// has all unique characters
// What if you cannot use additional data structures?
#include <iostream>
#include <cstdio>
#include <ctime>

using namespace std;

// 1. Brute Force Method O(n^2)
bool uniqueCharacters1(string str) {
    for (int i=0; i< str.length(); i++) {
        for (int j=i+1; j<str.length();j++) {
            //cout << str[i] << ", " << str[j] << endl;
            if (str[i] == str[j]) {
                return false;
            }
        }
    }
    return true;
}



//2. log(nlogn) sort first and then find it *** Uses STL
bool uniqueCharacters2(string str) {
    sort(str.begin(), str.end());
    for (int i=0; i<str.length(); i++){
        if (str[i] == str[i+1]) {
            //cout << str[i] << endl;
            return false;
        }
    }
    return true;
}

//3. hash table (java) == unordered map (c++) ????
bool uniqueCharacters3(string str) {
    // ASCII letters 256 unique characters (case sensitive)
    if (str.length() > 256) return false;
    bool checker[256] = {0};
    for (int i = 0; i < str.length(); i++) {
        // Using STL again; access element;
        //returns a reference to the element at position n in the vector
        int val = str.at(i);
        //cout << val << endl;
        if (checker[val] == true)
            return false;
        checker[val] = true;
    }
    return true;
}

// driver code
int main()
{
    
    clock_t start1, start2, start3;
    string input = "hela";
    start1 = clock();
    bool result1 = uniqueCharacters1(input);
    cout << clock() - start1 << endl;
    
    start2 = clock();
    bool result2 = uniqueCharacters2(input);
    cout << clock() - start2 << endl;
    
    start3 = clock();
    bool result3 = uniqueCharacters3(input);
    cout << clock() - start3 << endl;
    
    if (result1 == true && result2 == true && result3 == true) {
        cout << "All the characters are unique\n";
    } else {
        cout << "All the characters are NOT unique\n";
    }
    return 0;
}
