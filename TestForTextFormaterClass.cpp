#include "TextFormat.h"

int main(){

    stringstream testStream("@this is my test thing so let this be the longest line\n"
                            "@Let this be the second longest loine loine loine\n"
                            "left text#right text\n"
                            "$this can be the wrapped thing\n"
                            "this is just left justified");

    TextFormat testStuff(testStream, FINDTITLE, TOPTITLE);

    int titleBarLen = testStuff.getTitleBarLen(); 

    //clearing the string stream
    testStream.str(string());

    testStream << "$this should be in the wrapper\nit is a new object";

    TextFormat test2(testStream, USESETTITLE, titleBarLen, NOTITLE);

    testStream.str(string());

    testStream << "#this should be right justified";

    TextFormat test3(testStream, USESETTITLE, titleBarLen, BOTTOMTITLE);

    testStuff.display();
    test2.display();
    test3.display();
}