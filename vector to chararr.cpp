
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void assignChar(char*, char);
void printChar(char*);
void fillVecWithStuff(vector<string>&);
void printVector(vector<string>&);
void copyVecToArr(vector<string>&, char*);

int main(){

    char charArr[20][20] = {' '};

    //deference once to send address of [0][0]
    assignChar(*charArr, '0');

    printChar(*charArr);

    vector<string> charVec(0, " ");

    fillVecWithStuff(charVec);

    printVector(charVec);

    copyVecToArr(charVec, *charArr);

    if (charVec[0][0] == 'a')
        cout<<charVec[0][0];

    cout << endl << endl;

    printChar(*charArr);

    return 0;
}

void copyVecToArr(vector<string>&chrVec, char*charArr)
{
    int numColumns = 20;
    int numRows = numColumns;

    for (int l = 0, i = 0; i < numRows; i++, l += numColumns)
    {
        for (int j = 0; j < numColumns; j++)
        {
        *(charArr + l + j) = chrVec[i][j];
        }
    }
}

void printVector(vector<string>&vectorToCopy)
{
    for (int i = 0; i < 20; i++)
    {
        cout << vectorToCopy[i] << endl;
    }
}

void fillVecWithStuff(vector<string>&vectorToCopy)
{
    for (int i = 0; i < 20; i++)
    {
        vectorToCopy.push_back("abcdefghijklmnopqrst");
    }
}


void printChar(char *charArr)
{
    int numColumns = 20;
    int numRows = numColumns;

    for (int l = 0, i = 0; i < numRows; i++, l += numColumns)
    {
        for (int j = 0; j < numColumns; j++)
        {
        cout << *(charArr + l + j);
        }
        cout << endl;
    }
}

void assignChar(char *myArr, char charToAssign)
{
    int numColumns = 20;
    int numRows = numColumns;

    //l will maintain the progress along the array
    for (int l = 0, i = 0; i < numRows; i++, l += numColumns)
    {
        for (int j = 0; j < numColumns; j++)
        {
            if (i == j)
                *(myArr + l + j) = '$';
            else
                *(myArr + l + j) = charToAssign;
        }
    }

}
