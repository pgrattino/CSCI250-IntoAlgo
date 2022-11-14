//
//  karpRabin.cpp
//  ass3
//
//  Created by Peyton Grattino on 10/30/22.
//

//This solution was found on Geeks For Geeks. I used this website as a study tool and a reference for how to write the code. After studing the algorithm and understanding the concept I wrote the code. I did make modifications to the code from Geeks for Geeks to better suit this project. Here is the link to the website: https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/

#include "readSort.h"
#include <stdio.h>
#include <string>

using namespace std;

#define d 256 //d is the number of chars in the input alphabet

int krComp;
int krOccr;

int readSort::kr(string searchTerm, string rFile, int q){
    int M = (int) searchTerm.length();
    int N = (int) rFile.length();
    int p = 0; //hash val for searchTerm
    int t = 0; //hash val for rFile
    int j, i; //for the for loop
    int h = 1;
    
    for (i = 0; i < M - 1; i++)
    h = (h * d) % q;
    for (i = 0; i < M; i++){
        p = (d * p + searchTerm[i]) % q;
        t = (d * t + rFile[i]) % q;
    }
    for (i = 0; i <= N - M; i++){
        if (p == t){
            krComp++;
            for (j = 0; j < M; j++) {
                if (rFile[i + j] != searchTerm[j]){
                    krComp++;
                    break;
                }
            }
            if (j == M){
                krOccr++;
                krComp++;
                //return i - searchTerm.length() + 1;
            }
            
        }
        if (i < N - M) {
            krComp++;
            t = (d * (t - rFile[i] * h) + rFile[i + M]) % q;
            if (t < 0)
            t = (t + q);
        }
    }
    return krOccr;
}

int readSort::krCount(){
    return krComp;
}
