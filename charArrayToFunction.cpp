#include <iostream>
#include <string>

using namespace std;

void assigenChar(char*, char);

int main(){

    char mapArr[20][20] = {' '};

    //deference once to send address of [0][0]
    assigenChar(*mapArr, '0');

return 0;
}
/**
function logic:
If you are having difficulty understanding:
    make 2 diagrams:
        one of a 4x4 array;
        one of the array as it is stored in memory, i.e. in a line (see web for more)
    try to see how the indexes change between the 2 or follow the next steps

How to index an array with pointers like a 2d
    you need 3 variables:
    i: keeps track of the NUMBER OF ROWS
    j: keeps track of the NUMBER OF COLUMNS
    l: MAINTAINS COLUMN PROGRESS after j is reset.

after j loop is over, l will maintain the linear progress made along the memory
and i can be used to understand the linear progression as you would the progression
of a 2-D array
**/
void assigenChar(char *myArr, char charToAssign)
{
    for (int k = 0; k < 2; k++)
    {
        for (int l = 0, i = 0; i < 20; i++, l += 20)
        {
            for (int j = 0; j < 20; j++)
            {
                if (k == 0)
                    if (i == j)
                        *(myArr + l + j) = '$';
                    else
                        *(myArr + l + j) = charToAssign;
                else
                    cout << *(myArr + l + j);
            }
            if(k == 1) cout << endl;
        }
    }
}
