#include <string>
#include <iostream>

using namespace std;

int main(){

    const char* name= "suppi";

    //giving the first elements's address
    string mystring = string(name);

    cout << mystring << '\n';

    string str2 = name;

    string* str3 = &str2;

    cout << *str3;

    //delete str3;

    cout << str3;

    return 0;
}