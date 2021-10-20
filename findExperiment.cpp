#include <string>
#include <iostream>


using namespace std;

int main(){

/*
    string myStr("swaggyBoi");

    cout << myStr.find("Boi") << endl;

    int wrongIndex = myStr.find("mcMac");

    //wrong index from find when cast as a int is -1
    cout << (int)wrongIndex << endl;
*/

    string directions("N;S;E;W;NE");

    string currDir("");

    for (size_t index = 0; index != std::string::npos;)
    {
        index = directions.find(';');

        currDir = directions.substr(0, index);

        cout << currDir << '\n';

        directions = directions.substr(index+1, directions.length());
    }

}
