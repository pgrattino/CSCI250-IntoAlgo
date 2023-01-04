//
//  ass4Head.cpp
//  ass4
//
//  Created by Peyton Grattino on 11/16/22.
//

#include "ass4Head.h"
#include <iostream>

using namespace std;

int BFcount = 0;
int BFTotal = 0;

int ass4::BruteForceStringMatch(string fileIn, string patternIn){
    for (int i = 0; i <= (fileIn.length() - patternIn.length()); i++){
        int j = 0;
        while (j < patternIn.length() && patternIn[j] == fileIn[i + j]){
            j++;
        }
        if (j == patternIn.length()){
            BFcount++;
            BFTotal ++;
            return i;
        }
    }
    return BFTotal;
}

int ass4::BruteForceCount(){
    return BFcount;
}
