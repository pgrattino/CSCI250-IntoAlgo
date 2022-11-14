//
//  kmp.cpp
//  ass3
//
//  Created by Peyton Grattino on 10/30/22.
//

//got the code for this out of the class notes

#include <stdio.h>
#include <string>
#include "readSort.h"

using namespace std;

int kmpComp;

void readSort::CPF(string searchTerm, int m, int* lps){
    int len = 0;
    
    lps[0] = 0;
    
    int i = 1;
    while (i < m)
    {
        if (searchTerm[i] == searchTerm[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
                len = lps[len - 1];
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int readSort::kmp(string searchTerm, string rFile){
    int m = (int) searchTerm.length();
    int n = (int) rFile.length();
    int kmpCount =0;
    
    int lps[m];
    
    CPF(searchTerm, m, lps);
    
    int i = 0; //point in text file
    int j = 0; //point in pattern
    while ((n - i) >= (m - j))
    {
        if (searchTerm[j] == rFile[i])
        {
            kmpComp++;
            j++;
            i++;
        }
        if (j == m)
        {
            kmpComp++;
            //cout << "Found pattern at point: " << i - j;
            kmpCount++;
            j = lps[j - 1];
        }
        else if (i < n && searchTerm[j] != rFile[i])
        {
            kmpComp++;
            if (j != 0)
                j = lps[j-1];
            else
                i = i + 1;
        }
    }
    return kmpCount;
}

int readSort::kmpCompair(){
    return kmpComp;
}
