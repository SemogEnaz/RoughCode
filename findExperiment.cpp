#include <string>
#include <iostream>


using namespace std;

int main(){

    string myStr("swaggyBoi");

    cout << myStr.find("Boi") << endl;

    int wrongIndex = myStr.find("mcMac");

    //wrong index from find when cast as a int is -1
    cout << (int)wrongIndex << endl;

}
