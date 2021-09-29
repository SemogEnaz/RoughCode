#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){

    int* myPtr = nullptr;
    string *nyPtr = nullptr;

    if (myPtr) cout << "cheese\n";
    else cout << "bees\n";

/*
    vector<string> aPtr(20, NULL);

    aPtr[0] = "monkey";
*/

    vector<string*> myVec{};

    for (int i = 0; i < 5; i++)
        if (i == 3)
            myVec.push_back(new string("cheese"));
        else
            myVec.push_back(nullptr);

    if (myVec[0] == nullptr) cout << "cheese\n";
    else cout << "bees\n";

    if (myVec[3] == nullptr) cout << "cheese\n";
    else cout << "bees\n";

    return 0;
}