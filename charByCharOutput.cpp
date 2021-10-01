//https://stackoverflow.com/a/7891251
#include <chrono>
#include <iostream>
#include <thread>

using namespace std;

int main(){

    const char* testStr =    

    "\n//https://stackoverflow.com/a/7891251\n"
    "#include <chrono>\n"
    "#include <iostream>\n"
    "#include <thread>\n\n"
    "using namespace std;\n\n"
    "int main(){\n\n"
        "\t//setbuf(stdout, NULL);\n\n"
        "\tconst char* testStr = \"Hope you enjoy this program!\";\n\n"
        "\tfor (int i = 0; testStr[i] != \"\\0\"; i++)\n"
        "\t{\n" 
        "\t\tcout << testStr[i];\n"
        "\t\tfflush(stdout);\n"
        "\t\tthis_thread::sleep_for(0.08s);\n"
        "\t}\n\n"
        "\tcout  << \"\\n\";\n\n"
    "return 0;\n"
    "}\n\n"
    "/*\nYou can add some style changes by including a controle\n"
    "structure in the for loop that, if a \\n or ' ' is\n"
    "encountered, you skip the time delay and it makes the text\n"
    "output look more snappy.\n"
    "Also, I have compiled this with the -g argument so if you\n"
    "have gdb setup on your computer, you can use it to check out\n"
    "the source code\n"
    "Hope this comes in handy :]\n*/\n";

    //cout << testStr << "\n\n";

    for (int i = 0; testStr[i] != '\0'; i++)
    {   
        if (testStr[i] != '\n' || testStr[i] == '\t')  
        {
            cout << testStr[i];
            fflush(stdout);
            this_thread::sleep_for(0.08s);
        }
        else if (testStr[i] == '\n')
            cout << '\n';
        else
            cout << '\t';
    }

    cout  << '\n';

    return 0;
}
