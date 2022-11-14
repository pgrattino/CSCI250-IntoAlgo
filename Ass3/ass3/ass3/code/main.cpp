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
    string searchTerm;
    cout << "Press S for Search or Q for quit: ";
    cin >> userIn;
    
    if (userIn == 's' || userIn == 'S'){
        cout << "Please specify input text file name: ";
        cin >> fileName;
        string rFile = r.readFile(fileName);
        //cout << rFile << endl;
        cout << "Please specify the search term: ";
        cin >> searchTerm;
        
        //calling Karp Rabin
        int krSort, krComp;
        int q = INT_MAX; //got this off the gfg
        auto krStart = chrono::steady_clock::now();
        krSort = r.kr(searchTerm, rFile, q);
        krComp = r.krCount();
        auto krStop = chrono::steady_clock::now();
        chrono::duration<double> krRunT = krStop - krStart;
        cout << "Karp Rabin: \n - Number of occurrences in the text is: " << krSort << "\n - Number of Comparisons: "<< krComp << "\n - Time: " << krRunT.count() << " milliseconds" << endl;
        
        //calling Horspool
        int hpSort, hpComp;
        auto hpStart = chrono::steady_clock::now();
        //cout<<sizeof(rFile)<<endl;
        
        hpSort = r.horspool(searchTerm, rFile);
        hpComp = r.horspoolCount();
        auto hpStop = chrono::steady_clock::now();
        chrono::duration<double> hpRunT = hpStop - hpStart;
        cout << "Horspool: \n - Number of occurrences in the text is: " << hpSort << "\n - Number of Comparisons: " << hpComp << "\n - Time: " << hpRunT.count() << " milliseconds" << endl;
        
        //calling KMP
        int kmpSort, kmpComp;
        auto kmpStart = chrono::steady_clock::now();
        kmpSort = r.kmp(searchTerm, rFile);
        kmpComp = r.kmpCompair();
        auto kmpStop = chrono::steady_clock::now();
        chrono::duration<double> kmpRunT = kmpStop - kmpStart;
        cout << "KMP: \n - Number of occurrences in the text is: " << kmpSort << "\n - Number of Comparisons: "<< kmpComp << "\n - Time: " << kmpRunT.count() << " milliseconds" << endl;
        
    } else if (userIn == 'q' || userIn == 'Q'){
        return 0;
    } else {
        cout << "Enter a valid letter." << endl;
    }
    return 0;
}
