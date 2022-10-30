//
//  readSort.cpp
//  ass3
//
//  Created by Peyton Grattino on 10/29/22.
//

#include "readSort.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <string>

using namespace std;

string readSort::readFile(string fileName){
    auto start = chrono::steady_clock::now(); //starting the timer

    ifstream input (fileName); //reading the file
    string rFile; //saving the file

    auto stop = chrono::steady_clock::now(); //stopping the timer

    if (!input){
        cout << "Could not open file" << endl;
        return 0;
    } else {
        chrono::duration<double> runD = stop - start;    //runD is the time it took to read
        cout << "Text read! Time to read:" << runD.count() << endl;
        return rFile;
    }
    cout << "I got here" << endl;
    return fileName;
}
