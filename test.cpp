
#include <string>
#include <iomanip>
#include <sstream>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

enum TextFormatEnum{
FINDTITLE,
USESETTITLE
};

namespace TextFormater {

    int titleBarLength = 0;

    char titleBarChar = '~';

    string centerChar = "@";
    string justifyChar = "#";
    string wrapChar = "$";

    stringstream originalInputString("");
    stringstream outputString("");

    //this is the main function
    string processInput(string unformattedText, TextFormatEnum titleChoise)
    {
        //save input to the global
        originalInputString << unformattedText;

        string lineData = "";

        bool isToCenter = true;
        bool isToJustify = true;
        bool isToWrap = true;

        //when using, you can set the title pre function call and mention it in the second argument and then just the hard value or you can opt for the deduction by the program (5% larger)
        if (titleChoise == FINDTITLE)
            calculateBarLength();

        appendTitleBar();

        while (getline(originalInputString, lineData))
        {
            //now we search the string for the commands

            //the int recast of the find functions will retrun -1 if the character/string is not found else it will return the index of the substr

            isToCenter = (int)lineData.find("@") + 1;
            isToCenter = (int)lineData.find("#") + 1;
            isToWrap = (int)lineData.find("#") + 1;

            //center command
            if (isToCenter)
                centerText(lineData);
            else if (isToJustify)
                justifyText(lineData);
            else if (isToWrap)
                centerTextWrapper(lineData);
        }

        appendTitleBar();
    }

    //find the bar length needed and 
    void calculateBarLength()
    {
        titleBarLength = 0;

        stringstream inputString(originalInputString.str());
        string lineData = "";

        //finding the longest line in the input string
        while (getline(inputString, lineData))
            if ((int)lineData.length() > titleBarLength)
                titleBarLength = (int)lineData.length();

        //title 5% > longest line, so:
        titleBarLength = round(titleBarLength + (titleBarLength * 0.05));
    }

    void appendTitleBar()
    {
        stringstream titleBar("");

        titleBar.fill(titleBarChar);
        titleBar.width(titleBarLength);

        outputString << titleBar.str() << "\n";

    }

    void centerText(string text2Center)
    {
        text2Center = removeCmdChar(text2Center, "@");

        int textLength = (int)text2Center.length();

        //this calculates the space needed to shift the text to center it relative to the titleBar
        int spaceToCenter = round((titleBarLength - textLength) / 2);

        putSpace(textLength, spaceToCenter);

        outputString << text2Center << "\n";
    }

    void justifyText(string text2Justify)
    {
        //example argument: "this is my left text#this is my right text"

        //-1 because the "#" character will be replaced with ""
        int textLength = (int)text2Justify.length() - 1;

        //index of the left text = 0
        int lenLeftText = text2Justify.find("#") - 1;

        //we will not add one as that character will be replaced with "" later
        int indexRightText = text2Justify.find("#");
        int lenRightText = textLength - indexRightText;

        text2Justify = removeCmdChar(text2Justify, "#");

        int space2end = floor(titleBarLength - (2 * textLength));

        //left text
        outputString << text2Justify.substr(0, lenLeftText);

        putSpace(textLength, space2end);

        //right text
        outputString << right << text2Justify.substr(indexRightText, lenRightText);
    }

    void centerTextWrapper(string text2center)
    {
        //this is centerText but with next lines on the top and bottom
        outputString << "\n";
        centerText(text2center);
        outputString << "\n";
    }

    string removeCmdChar(string lineData, string commandStr)
    {
        int indexOfCommand = lineData.find(commandStr);
        lineData.replace(indexOfCommand, 1, "");

        return lineData;
    }

    void putSpace(int textLength, int space2insert)
    {
        //this controle structure checks to prevent negative width
        if (titleBarLength > textLength)
        {
            outputString.fill(' ');
            outputString.width(space2insert);
        }
        else
            cout << "title bar too short for this operation" << endl;
    }
}
