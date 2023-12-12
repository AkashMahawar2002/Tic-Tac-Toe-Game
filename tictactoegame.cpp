#include <iostream>
#include <cstdlib>

using namespace std;

char CharMatrixDraw[10] = {'0', '1', '2',
                           '3', '4', '5',
                           '6', '7', '8', '9'};

int winner();
void GameChart(string, string);

int main()
{
    int choice;
    do
    {
        int Gamer = 1, i;
        string name1, name2;

        cout << "Enter First Gamer Name: ";
        cin >> name1;

        cout << "\nEnter Second Gamer Name: ";
        cin >> name2;

        char mark;

        do
        {
            GameChart(name1, name2);
            Gamer = (Gamer % 2) ? 1 : 2;

            if (Gamer == 1)
            {
                cout << name1 << " Your Turn, Enter a Number:  ";
                cin >> choice;
            }
            else
            {
                cout << name2 << " Your Turn, Enter a Number:  ";
                cin >> choice;
            }

            mark = (Gamer == 1) ? 'X' : '0';

            if (choice >= 1 && choice <= 9 && CharMatrixDraw[choice] == '0' + choice)
                CharMatrixDraw[choice] = mark;
            else
            {
                cout << "\nInvalid Choice. Try Again.\n";
                Gamer--;
                cin.ignore();
                cin.get();
            }

            i = winner();
            Gamer++;
        } while (i == -1);

        GameChart(name1, name2);

        if (i == 1)
        {
            cout << "\n=============================\n";
            cout << "\a" << name1 << " Is A Winner \n";
            cout << "=============================\n";
        }
        else
        {
            cout << "\n=============================\n";
            cout << "\aGame Is Draw\n";
            cout << "=============================\n";
        }

        cout << "Do you want to play again? (1 for Yes, 0 for No): ";
        cin >> choice;

        // Reset the game board for a new game
        for (int k = 1; k <= 9; k++)
        {
            CharMatrixDraw[k] = '0' + k;
        }

    } while (choice == 1);

    cout << "Ram Ram! Milte hai fir kabhi! _/\_ ." << endl;

    cin.ignore();
    cin.get();
    return 0;
}

int winner()
{
    if (CharMatrixDraw[1] == CharMatrixDraw[2] && CharMatrixDraw[2] == CharMatrixDraw[3])
        return 1;
    else if (CharMatrixDraw[4] == CharMatrixDraw[5] && CharMatrixDraw[5] == CharMatrixDraw[6])
        return 1;
    else if (CharMatrixDraw[7] == CharMatrixDraw[8] && CharMatrixDraw[8] == CharMatrixDraw[9])
        return 1;
    else if (CharMatrixDraw[1] == CharMatrixDraw[4] && CharMatrixDraw[4] == CharMatrixDraw[7])
        return 1;
    else if (CharMatrixDraw[2] == CharMatrixDraw[5] && CharMatrixDraw[5] == CharMatrixDraw[8])
        return 1;
    else if (CharMatrixDraw[3] == CharMatrixDraw[6] && CharMatrixDraw[6] == CharMatrixDraw[9])
        return 1;
    else if (CharMatrixDraw[1] == CharMatrixDraw[5] && CharMatrixDraw[5] == CharMatrixDraw[9])
        return 1;
    else if (CharMatrixDraw[3] == CharMatrixDraw[5] && CharMatrixDraw[5] == CharMatrixDraw[7])
        return 1;
    else if (CharMatrixDraw[1] != '1' && CharMatrixDraw[2] != '2' && CharMatrixDraw[3] != '3' &&
             CharMatrixDraw[4] != '4' && CharMatrixDraw[5] != '5' && CharMatrixDraw[6] != '6' &&
             CharMatrixDraw[7] != '7' && CharMatrixDraw[8] != '8' && CharMatrixDraw[9] != '9')
        return 0;
    else
        return -1;
}

void GameChart(string name1, string name2)
{
    system("cls");

    cout << "\n==========================";
    cout << "\n\tTic Tac Toe\n";
    cout << "\n==========================\n";

    string nam1 = name1;
    string nam2 = name2;

    cout << nam1 << "(X)" << "========" << nam2 << " (0)\n\n";

    cout << "     ||     ||     " << endl;
    cout << "  " << CharMatrixDraw[1] << "  ||  " << CharMatrixDraw[2] << "  ||  " << CharMatrixDraw[3] << endl;

    cout << "=====||=====||=====" << endl;
    cout << "     ||     ||     " << endl;

    cout << "  " << CharMatrixDraw[4] << "  ||  " << CharMatrixDraw[5] << "  ||  " << CharMatrixDraw[6] << endl;

    cout << "=====||=====||=====" << endl;
    cout << "     ||     ||     " << endl;

    cout << "  " << CharMatrixDraw[7] << "  ||  " << CharMatrixDraw[8] << "  ||  " << CharMatrixDraw[9] << endl;

    cout << "     ||     ||     " << endl
         << endl;
}
