#include "ass4Head.h"
#include <iostream>
#include <chrono>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    ass4 r; //calling the ass4 Func
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
        
        //calling BruteForce
        int bfSort, bfComp;
        auto bfStart = chrono::steady_clock::now();
        bfSort = r.BruteForceStringMatch(rFile, searchTerm);
        bfComp = r.BruteForceCount();
        auto bfStop = chrono::steady_clock::now();
        chrono::duration<double> bfRunT = bfStop - bfStart;
        cout << "Brute Force: \n - Number of occurrences in the text is: " << bfSort << "\n - Number of Comparisons: " << bfComp << "\n - Time: " << bfRunT.count() << " milliseconds" << endl;
        
        //calling Horspool
        int hpSort, hpComp;
        auto hpStart = chrono::steady_clock::now();
        r.horspool(searchTerm, rFile);
        hpSort = r.horspoolTotal();
        hpComp = r.horspoolCount();
        auto hpStop = chrono::steady_clock::now();
        chrono::duration<double> hpRunT = hpStop - hpStart;
        cout << "Horspool: \n - Number of occurrences in the text is: " << hpSort << "\n - Number of Comparisons: " << hpComp << "\n - Time: " << hpRunT.count() << " milliseconds" << endl;
        
        //calling Boyer-Moore
        int bmSort, bmComp;
        auto bmStart = chrono::steady_clock::now();
        bmSort = r.boyerMoore(rFile, searchTerm);
        bmComp = r.boyerComp();
        auto bmStop = chrono::steady_clock::now();
        chrono::duration<double> bmRunT = bmStop - bmStart;
        cout << "Boyer-Moore: \n - Number of occurrences in the text is: " << bmSort << "\n - Number of Comparisons: " << bmComp << "\n - Time: " << bmRunT.count() << " milliseconds" << endl;
        
    } else if (userIn == 'q' || userIn == 'Q'){
        return 0;
    } else {
        cout << "Enter a valid letter." << endl;
    }
    return 0;
}
