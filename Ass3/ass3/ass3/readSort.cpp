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

std::string readSort::readFile(std::string &fileName){
    auto start = chrono::steady_clock::now(); //starting the timer

    ifstream fin;
    fin.open(fileName);
    std::string rFile; //saving the file

    auto stop = chrono::steady_clock::now(); //stopping the timer
    if (!fin){
        cout << "Could not open file" << endl;
        cout << rFile;
    } else {
        chrono::duration<double> runD = stop - start;    //runD is the time it took to read
        cout << "Text read! Time to read:" << runD.count() << endl;
        return rFile;
    }
    fin.close();
//    ifstream fin(userInFile);
//    string rFile;
//    rFile.assign((istreambuf_iterator<char>(fin)),(istreambuf_iterator<char>()));
//    if (rFile == "")
//        cout << "No rFile" << endl;
    return rFile;
}
