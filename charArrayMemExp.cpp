#include <string>
#include <iostream>
#include <malloc.h>

using namespace std;

int main(){

    //static, is assigned at run time
    //cannot use delete or free
    const char* str = "cheese";

    //dynamicly allocating memory
    char* name= (char*)malloc((sizeof(char) * 4));

    name[0] = 'c';
    name[1] = 'a';
    name[2] = 't';
    name[3] = '\0';

    cout << name << '\n';

    free(name);

    return 0;
}