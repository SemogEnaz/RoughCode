
#include <chrono>
#include <iostream>
#include <cstring>
#include <thread>
//#include <unistd.h>

using namespace std;

int main(){

    //setbuf(stdout, NULL);

    const char* testStr = "This";

    for (int i = 0; i < strlen(testStr); i++)
    {     
        cout << testStr[i];// << endl;
        fflush(stdout);
        //sleep(0.75);//sleeps for 1 second
        this_thread::sleep_for(0.65s);
    }

    return 0;
}
