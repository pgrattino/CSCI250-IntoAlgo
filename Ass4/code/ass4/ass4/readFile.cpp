//
//  readFile.cpp
//  ass4
//
//  Created by Peyton Grattino on 11/16/22.
//

#include "ass4Head.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <string>

string ass4::readFile(string fileName){
    auto start = chrono::steady_clock::now(); //starting the timer

    ifstream fin;
    string rFile; //saving the file
    int fileSize = 0;
    char* data;
    
    fin.open(fileName, ios::in | ios::binary);
    if (fin.good()){
        fin.seekg(0, ios::end);
        fileSize = (int)fin.tellg();
        data = new char [fileSize];
        fin.seekg(ios::beg);
        fin.read(data, fileSize);
        rFile = static_cast<string>(data);
    }
    auto stop = chrono::steady_clock::now(); //stopping the timer
    if (!fin){
        cout << "Could not open file" << endl;
        return 0;
    } else {
        chrono::duration<double> runD = stop - start;    //runD is the time it took to read
        cout << "Text read! Time to read:" << runD.count() << endl;
        return rFile;
    }
    return 0;
}
