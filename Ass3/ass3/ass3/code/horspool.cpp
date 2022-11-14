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
int hpTable[26]; //this is the table for the shiftTable
int hpTotal;

int* readSort::shiftTable(string searchTerm) //this was pulled from the textbook
{
    for(int i = 0; i <= searchTerm.length() - 1; i++)
    {
        hpTable[i] = (int)searchTerm.length();
    }
    for(int j = 0; j <= searchTerm.length() - 2; j++)
    {
        hpTable[searchTerm[j]] = (int)searchTerm.length() - 1 - j;
    }
    return (int*) hpTable;
}

int readSort::horspool(string searchTerm, string rFile)
{
    int* table = shiftTable(searchTerm);    //gen of shift table
    int j = (int) searchTerm.length() - 1;  //position at the right end of pattern
    while(j <= rFile.length() - 1){
        int k = 0;
        while((k <= rFile.length() - 1) /*&& (searchTerm[searchTerm.length() - 1 - k]) == rFile[j - k]*/){
            k = k + 1;
            hpComp++;
        }
        if ((k = searchTerm.length())){ //this line is causing the infinate loop
            /*If you use the way currently layed about as the if statement it does not enter the if ever. But if you call it correnctly if k == searchTerm.length() then it repeats for ever in a necer ending loop */
//            return (j - searchTerm.length() + 1);
            hpTotal++;
            break;; //this prevents the infinite loop
        }else
            j = j + table[rFile[j]];
    }
    return hpTotal;
}
int readSort::horspoolCount(){
    return hpComp; //returning the number of compairisons
}
