//
//  boyerMoore.cpp
//  ass4
//
//  Created by Peyton Grattino on 11/16/22.
//  Code was found at https://www.geeksforgeeks.org/boyer-moore-algorithm-for-pattern-searching/ small changes were made to make the algorithm work for this assignment.

#include <stdio.h>
#include <iostream>
#include "ass4Head.h"

#define NO_OF_CHARS 256

int bmCount = 0;
int bmComp = 0;

void ass4::badChars(string str, int size, int badChar[NO_OF_CHARS]){
    int i;
    
    for (i = 0; i < NO_OF_CHARS; i++)
        badChar[i] = -1;
    for (i = 0; i < size; i++)
        badChar[(int) str[i]] = -1;
}

int ass4::boyerMoore(string file, string pattern){
    int m = (int) pattern.size();
    int n = (int) file.size();
    
    int badChar[NO_OF_CHARS];
    
    badChars(pattern, m, badChar);
    
    int s = 0;
    
    while(s <= (n - m)){
        int j = m - 1;
        while(j >= 0 && pattern[j] == file[s + j]){
            j--;
            bmComp++;
        }
        if (j < 0)
        {
            //cout << "Pattern at shift = " << s << endl;
            bmCount++;
            s += (s + m < n) ? m-badChar[file[s + m]] : 1;
        }
        else
            s += max(1, j - badChar[file[s + j]]);
    }
    return bmCount;
}

int ass4::boyerComp(){
    return bmComp;
}
