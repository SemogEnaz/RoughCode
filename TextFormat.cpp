
#include "TextFormat.h"

//this is for calculating the title bar
TextFormat::TextFormat(stringstream& inputStr, TextFormatEnum barChoice)
: originalInputString(inputStr.str())
{
    processInput(barChoice);
}

//this is to use a pre-set value, the user can specify the length to set in the constructor
TextFormat::TextFormat(stringstream& inputStr, TextFormatEnum barChoice, int lenOfBar2Set)
: originalInputString(inputStr.str()),
  titleBarLength(lenOfBar2Set)
{
    processInput(barChoice);
}

void TextFormat::processInput(TextFormatEnum titleChoise)
{
    string lineData = "";

    size_t indexCenter = 0;
    size_t indexJustify = 0;
    size_t indexWrap = 0;

    //when using, you can set the title pre function call and mention it in the second argument and then just the hard value or you can opt for the deduction by the program (5% larger)
    if (titleChoise == FINDTITLE)
        calculateBarLength();

    appendTitleBar();

    while(getline(originalInputString, lineData))
    {
        //now we search the string for the commands

        //the int recast of the find functions will retrun -1 if the character/string is not found else it will return the index of the substr

        indexCenter = lineData.find(centerChar);
        indexJustify = lineData.find(justifyChar);
        indexWrap = lineData.find(wrapChar) ;

        //center command
        if (indexCenter != std::string::npos)
        { 
            removeCmdChar(lineData, centerChar);
            centerText(lineData);
        }
        else if (indexJustify != std::string::npos)
            justifyText(lineData);
        else if (indexWrap != std::string::npos)
        {
            removeCmdChar(lineData, wrapChar);
            centerTextWrapper(lineData);
        }
    }

    appendTitleBar();
}

bool checkForEven(int num)
{
    if(num % 2 == 0)
        return true;
    
    return false;
}

//find the bar length needed and 
void TextFormat::calculateBarLength()
{
    titleBarLength = 0;

    bool isTitleBarLenEven = false;
    bool isLineLenEven = false;

    stringstream inputString(originalInputString.str());
    string lineData = "";

    //finding the longest line in the input string
    while (getline(inputString, lineData))
        if ((int)lineData.length() > titleBarLength)
            titleBarLength = (int)lineData.length();

    isLineLenEven = checkForEven((int)lineData.length());

    //title 5% > longest line, so:
    titleBarLength = round(titleBarLength + (titleBarLength*0.05));

    isTitleBarLenEven = checkForEven(titleBarLength);

    if (!isTitleBarLenEven && isLineLenEven)
        titleBarLength++;
}

void TextFormat::appendTitleBar()
{
    stringstream titleBar("");

    titleBar.fill(titleBarChar);
    titleBar.width(titleBarLength);

    outputString << titleBar.str() << "\n";

}

void TextFormat::centerText(string& text2Center)
{
    int textLength = (int)text2Center.length();

    //this calculates the space needed to shift the text to center it relative to the titleBar
    int spaceToCenter = round((titleBarLength - textLength) / 2);

    putSpace(textLength, spaceToCenter);

    outputString << text2Center << "\n";
}

void TextFormat::justifyText(string& text2Justify)
{
    //example argument: "this is my left text#this is my right text"

    //-1 because the justifyChar character will be replaced with ""
    int textLength = (int)text2Justify.length() - 1;

    //index of the left text = 0
    int lenLeftText = text2Justify.find(justifyChar) - 1; 
    
    //we will not add one as that character will be replaced with "" later
    int indexRightText = text2Justify.find(justifyChar);
    int lenRightText = textLength - indexRightText;

    removeCmdChar(text2Justify, justifyChar);

    int space2end = floor(titleBarLength - (2*textLength));

    //left text
    outputString << text2Justify.substr(0, lenLeftText);

    putSpace(textLength, space2end);

    //right text
    outputString << right << text2Justify.substr(indexRightText, lenRightText);
}

void TextFormat::centerTextWrapper(string& text2center)
{
    //this is centerText but with next lines on the top and bottom
    outputString << "\n";
    centerText(text2center);
    outputString << "\n";
}

void TextFormat::removeCmdChar(string& lineData, string& commandStr)
{
    int indexOfCommand = lineData.find(commandStr);
    lineData.replace(indexOfCommand, 1, "");
}

void TextFormat::putSpace(int textLength, int space2insert)
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

void TextFormat::display()
{
    cout << outputString.str();
}    