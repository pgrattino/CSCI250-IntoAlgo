//
//  ass4Head.hpp
//  ass4
//
//  Created by Peyton Grattino on 11/16/22.
//

#ifndef ass4Head_h
#define ass4Head_h

#include <stdio.h>
#include <string>


using namespace std;

class ass4 {
public:
    string readFile(string);
    int BruteForceStringMatch(string, string);
    int BruteForceCount();
    int *shiftTable(string);
    int horspool(string, string);
    int horspoolCount();
    int horspoolTotal();
    void badChars(string, int, int[]);
    int boyerMoore(string, string);
    int boyerComp();
};

#endif /* ass4Head_hpp */
