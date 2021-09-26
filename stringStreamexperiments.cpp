#include <sstream>
#include <string>
#include <iostream>

using namespace std;

int main(){

    stringstream myStream("");

    string firstLine = "";

    myStream << "\tthis is the first line\n";
    myStream << "\tthis is my second line\n";
    myStream << "\tthis is my third line\n\n";
/*
    //dose not work
    myStream.fill('~');
    myStream.width(10);
*/
/*
    cout << myStream.str();

    getline(myStream, firstLine);

    cout << "\n\n" << firstLine;

    getline(myStream, firstLine);

    cout << "\n\n" << firstLine; 
*/
    cout << "first output normal:\n\n" << myStream.str();

    myStream.clear();

    cout << "second output, after myStream.clear() call:\n\n" << myStream.str();

    myStream.str(string());

    cout << "third output, after doing the myStream.str(string()):\n\n"<< myStream.str();

    return 0;
}