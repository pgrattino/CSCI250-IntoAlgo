#include <iostream>
//all of the infiles will have a blank line at the end. if cin == blank line exit loop.
//If the program is run within the loop of inputs we dont need to save all the variables just the last answer.

//line one of inputs will be n, m, p
//line two of inputs will be p number of ints
//the remaining lines will be m lines containing 3 ints
using namespace std;

int main(){
    int n, m, p;
    cin >> n >> m >> p;
    cout << n << m << p << endl;
	return 0;
}
