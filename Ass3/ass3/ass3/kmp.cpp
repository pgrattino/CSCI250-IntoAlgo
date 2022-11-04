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

void readSort::CPF(string searchTerm, int m, int* lps){
//    int m = searchTerm.length();
//    int lps[searchTerm.length()];
//    lps[0] = 0;
//    int k = 0;
//
//    for (int q = 2; q <= m; q++){
//        while (k > 0 && searchTerm[k + 1] != searchTerm[q]){
//            k = lps[k];
//        }
//        if (searchTerm[k+1] == searchTerm[q]){
//            k = k + 1;
//        }
//        lps[q] = k;
//    }
//    return lps[0];
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
//    int m = searchTerm.length();
//    int n = rFile.length();
//    int lps = CPF(searchTerm);
//    int q = 0;
//    for (int i = 1; i <= n; i++){
//        while (q > 0 && searchTerm[q + 1] != rFile[i]){
//            q = lps[q - 1];
//        }
//        if (searchTerm[q + 1] == rFile[i]){
//            q++;
//        }
//        if (q == m){
//            cout << "pattern occurs with shift " << i - m << endl;
//            q = lps[q];
//        }
//    }
//    return -1;
    int m = (int) searchTerm.length();
    int n = (int) rFile.length();
    int kmpCount;
    
    int lps[m];
    
    CPF(searchTerm, m, lps);
    
    int i = 0; //point in text file
    int j = 0; //point in pattern
    while ((n - i) >= (m - j))
    {
        if (searchTerm[j] == rFile[i])
        {
            j++;
            i++;
        }
        if (j == m)
        {
            cout << "Found pattern at point: " << i - j;
            kmpCount++;
            j = lps[j - 1];
        }
        else if (i < n && searchTerm[j] != rFile[i])
        {
            if (j != 0)
                j = lps[j-1];
            else
                i = i + 1;
        }
    }
    return kmpCount;
}
