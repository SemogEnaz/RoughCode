#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

int main(){

    //will not work with string stream

    stringstream myStream("");

    //or myStream.fill('~');
    myStream << setfill('~');

    //or myStream.width(20);
    myStream << setw(20);

    string output = myStream.str();

    cout << myStream.str();

    cout << output;

    //this works
    
    cout.fill('~'); cout.width(20);

    cout << "\n";

    return 0;

}