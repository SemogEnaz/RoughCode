#include "TextFormat.h"

int main(){

    stringstream testStream("@this is my test thing so let this be the longest line\n"
                            "Let this be the second longest loine loine loine\n"
                            "left text#right text\n"
                            "$this can be the wrapped thing\n"
                            "this is just left justified");

    string inputString = testStream.str();

    TextFormat testStuff(inputString, FINDTITLE);

    testStuff.display();
}