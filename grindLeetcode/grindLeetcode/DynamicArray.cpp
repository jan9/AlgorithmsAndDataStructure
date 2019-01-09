//
//  main.cpp
//  grindLeetcode
//
//  Created by Ju An on 1/9/19.
//  Copyright © 2019 juhye. All rights reserved.
//

#include <iostream>
#include <new>  // for dynamic array
using namespace std;

int main(int argc, const char * argv[]) {
    // regular array
    const int elements = 9;
    int regFoo[elements] = {0};
    for (int i = 0; i < elements; i++) {
        cout << "Enter a number (number " << i+1 << " of 9): ";
        cin >> regFoo[i];
    }
    cout << "You have entered the following 9 numbers: ";
    for (int i = 0; i < elements; i++) {
        cout << regFoo[i] << " ";
    }
    cout << endl;
    
    // dynamic array from scratch
    int *foo, num;
    cout << "How many numbers would you like to type?";
    cin >> num;
    
    foo = new (nothrow) int[num];
    if (foo == nullptr) {
        cout << "ERROR: null pointer returned, memory couldn't be allocated/n";
    } else {
        for (int i = 0; i < num; i++) {
            cout << "Enter number: ";
            cin >> foo[i];
        }
        cout << "You have entered: ";
        for (int i = 0; i < num; i++) {
            if (i == num-1) {
                cout << foo[i] << endl;
            } else {
                cout << foo[i] << ", ";
            }
        }
        delete[] foo;
    }
    return 0;
}
