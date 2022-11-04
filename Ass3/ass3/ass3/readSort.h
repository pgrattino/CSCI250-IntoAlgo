//
//  readSort.hpp
//  ass3
//
//  Created by Peyton Grattino on 10/29/22.
//

#ifndef readSort_h
#define readSort_h

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class readSort{
public:
    string readFile(string);
    int kr(string, string, int);
    int krCount();
    int shiftTable(string);
    int horspool(string, string);
    int horspoolCount();
    int kmp(string, string);
    void CPF(string, int, int*);
};

#endif /* readSort_hpp */
