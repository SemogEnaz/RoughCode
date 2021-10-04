#include <iostream>
#include <stdlib.h>

using namespace std;

void notMain();
int findSum(int, int);

int main(){

    notMain();

    return 0;
}

void notMain()
{
    int sum = findSum(1, 2); 

    printf("\nresult of program: %i\n\n", sum);
}

int findSum(int firstVariable, int secondVariable)
{
    int sum = firstVariable + secondVariable;

    return sum;
}
