//
//  horspool.cpp
//  ass4
//
//  Created by Peyton Grattino on 11/16/22.
//

#include "ass4Head.h"
#include <stdio.h>

int hpComp; //This is the number of compairs
int hpTable[26]; //this is the table for the shiftTable
int hpTotal;

int* ass4::shiftTable(string searchTerm) //this was pulled from the textbook
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

int ass4::horspool(string searchTerm, string rFile)
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
            hpTotal++;
            (j - searchTerm.length() + 1);
            break; //this prevents the infinite loop
        }else
            j = j + table[rFile[j]];
    }
    return hpTotal;
}
int ass4::horspoolCount(){
    return hpComp; //returning the number of compairisons
}
int ass4::horspoolTotal(){
    return hpTotal;
}
