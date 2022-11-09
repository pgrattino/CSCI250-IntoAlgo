//
//  horspool.cpp
//  ass3
//
//  Created by Peyton Grattino on 10/30/22.
//

//The sorting algo in this file is from Introduction to the Design and Analysis of Algorithms by Anany Levitin

#include <stdio.h>
#include "readSort.h"

int hpComp; //This is the number of compairs
//int hpTable[26]; //this is the table for the shiftTable
int hpTotal;

int* readSort::shiftTable(string searchTerm) //this was pulled from the textbook
{
    int hpTable[searchTerm.length() - 1];
    for(int i = 0; i <= searchTerm.length() - 1; i++)
    {
        hpTable[i] = (int)searchTerm.length();
    }
    for(int j = 0; j <= searchTerm.length() - 2; j++)
    {
        hpTable[searchTerm[j]] = (int)searchTerm.length() - 1 - j;
    }
    return (int*) hpTable[searchTerm.length() - 1];
}

int readSort::horspool(string searchTerm, string rFile) //found the code in the book
{
    int* hpTable = shiftTable(searchTerm);
    int i = (int)searchTerm.length() - 1;
    while (i <= rFile.length() - 1) {
//        hpComp++; //Increase the number of compairisons
        int k = 0;
        while (k <= searchTerm.length() - 1 && searchTerm[searchTerm.length() - 1 - k] == rFile[i - k]){
            hpComp++;
            k++;
        }
        if (k == searchTerm.length()){
            //hpComp++;
            //return i - searchTerm.length() + 1;
            hpTotal++;
        }
        else
        {
            //hpComp++;
            i = i + hpTable[rFile[i]];
        }
    }
    return hpTotal;
}

int readSort::horspoolCount(){
    return hpComp; //returning the number of compairisons
}
