
#include "TextFormat.h"

//this is for calculating the title bar
TextFormat::TextFormat(stringstream& inputStr, TextFormatEnum barLenChoice, TextFormatEnum barChoice)
: originalInputString(inputStr.str())
{
    processInput(barLenChoice, barChoice);
}

//this is to use a pre-set value, the user can specify the length to set in the constructor
TextFormat::TextFormat(stringstream& inputStr, TextFormatEnum barLenChoice, int lenOfBar2Set, TextFormatEnum barChoice)
: originalInputString(inputStr.str()),
  titleBarLength(lenOfBar2Set)
{
    processInput(barLenChoice, barChoice);
}

void TextFormat::processInput(TextFormatEnum titleChoise, TextFormatEnum barChoice)
{
    string lineData = "";

    size_t indexCenter = 0;
    size_t indexJustify = 0;
    size_t indexWrap = 0;

    bool wantTopTitle = (barChoice == TOPTITLE || barChoice == BOTHTITLE);
    bool wantBottomTitle = (barChoice == BOTTOMTITLE || barChoice == BOTHTITLE);

    //when using, you can set the title pre function call and mention it in the second argument and then just the hard value or you can opt for the deduction by the program (5% larger) MAKE CONSTRUCTOR OPTION TO BE ABLE TO CHANGE THE %INCREASE
    if (titleChoise == FINDTITLE)
        calculateBarLength();

    if (wantTopTitle) appendTitleBar();

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
        else
            outputString << lineData << "\n";
    }

    if (wantBottomTitle) appendTitleBar();
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
    //THERE IS A MINOR ERROR IN THIS FUNCTION, THE LENGTH OF THE TITLE BAR IS FOUND USING THE INPUT WITH COMMAND CHARACTERS, THESE WILL BE REMOVED LATER, THEN THE CENTERING WILL BE OFF BY +/- ONE CHAR, YOU NEED TO FIX THAT LATER BY MAKING THE removeAllCmdChar() function in this class;
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

    for (int i = 0; i < titleBarLength; i++)
        outputString << titleBarChar;

    outputString << "\n";

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

    int lenLeftText = 0;

    if (text2Justify.substr(0, 1) != justifyChar)
        //index of the left text = 0
        lenLeftText = text2Justify.find(justifyChar) - 1; 
    
    //we will not add one as that character will be replaced with "" later
    int indexRightText = text2Justify.find(justifyChar);
    int lenRightText = textLength - indexRightText;

    removeCmdChar(text2Justify, justifyChar);

    int space2end = (titleBarLength - (lenLeftText + lenRightText));

    //left text
    outputString << text2Justify.substr(0, lenLeftText);

    putSpace(textLength, space2end);

    //right text
    outputString << right << text2Justify.substr(indexRightText, lenRightText) << "\n";
}

void TextFormat::centerTextWrapper(string& text2center)
{
    //this is centerText but with next lines on the top and bottom
    outputString << "\n";
    centerText(text2center);
    outputString << "\n";
}

void TextFormat::removeCmdChar(string& lineData, string commandStr)
{
    int indexOfCommand = lineData.find(commandStr);
    lineData.replace(indexOfCommand, 1, "");
}

void TextFormat::putSpace(int textLength, int space2insert)
{
    //this controle structure checks to prevent negative width
    if (titleBarLength > textLength)
    {    
        for(int i = 0; i < space2insert; i++)
            outputString << " ";
    }
    else
        cout << "title bar too short for this operation" << endl;
}

void TextFormat::display()
{
    cout << outputString.str();
}    

int TextFormat::getTitleBarLen()
{
    return titleBarLength;
}