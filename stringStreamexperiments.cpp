#include <sstream>
#include <string>
#include <iostream>

using namespace std;

int main(){

    stringstream myStream("");

    string firstLine = "";

    myStream << "this is the first line\n";
    myStream << "this is my second line\n";
    myStream << "this is my third line\n";
    myStream.fill('~');
    myStream.width(10);

    cout << myStream.str();

    getline(myStream, firstLine);

    cout << "\n\n" << firstLine;

    getline(myStream, firstLine);

    cout << "\n\n" << firstLine; 

    return 0;
}