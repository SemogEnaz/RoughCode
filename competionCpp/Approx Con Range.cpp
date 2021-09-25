//https://vjudge.net/contest/427165#problem/C

#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> VecInt;

int main()

{
    int lengthOfSeq = 0;
    int seqComponent = 0;
    VecInt Sequence(0, 0);

    VecInt outputVec(0, 0);

    int highScore = 0;

    int currentMax = 0, currentMin = 0;

    int diffrnece = 0;

    cin >> lengthOfSeq;

    for (int i = 0; i < lengthOfSeq; i++)
    {
        cin >> seqComponent;
        Sequence.push_back(seqComponent);
    }

    for (int i = 0;; i++)
    {
        int currentElement = Sequence[i];

        if (i == ((int)Sequence.size() - 1))
        {
            break;
        }
        //first case
        else if (i == 0)
        {
            currentMax = Sequence[i];
            currentMin = Sequence[i];


            diffrnece = Sequence[i + 1] - Sequence[i];

            if (diffrnece == 1)
                currentMax = Sequence[i + 1];
            else if (diffrnece == -1)
                currentMin = Sequence[i + 1];

            if (highScore < 2)
                highScore = 2;
        }
        //second case
        else if (i == 1)
        {
            if (highScore < 3)
                highScore++;
        }
        else //middle stuff
        {
            if (i == 2)
                highScore == i;

            if (Sequence[i + 1] > currentMax || Sequence[i + 1] < currentMin)
            {
                if (i >= highScore)
                    highScore = ++i;

                Sequence.erase(Sequence.begin());
                i = -1;
            }
        }
    }
    cout << highScore;

    return 0;
}