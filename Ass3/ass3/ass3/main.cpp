//
//  main.cpp
//  ass3
//
//  Created by Peyton Grattino on 10/29/22.
//

#include "readSort.h"
#include <iostream>
#include <chrono>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    readSort r; //calling the readSort Func
    char userIn;
    string fileName;
    //string rFile;
    string sortName;
    cout << "Press S for Search or Q for quit: ";
    cin >> userIn;
    
    if (userIn == 's' || userIn == 'S'){
        cout << "Please specify input text file name: ";
        cin >> fileName;
        string rFile = r.readFile(fileName);
        cout << rFile;
        cout << "Please specify the sort: ";
        cin >> sortName;
    } else if (userIn == 'q' || userIn == 'Q'){
        return 0;
    } else {
        cout << "Enter a valid letter." << endl;
    }
    return 0;
}
