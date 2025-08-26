#include <iostream>
#include<random>
#include <ctime>

using namespace std;

char field[9] = {' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
bool game = true;
char winSide;
int stepCount{0};
int prevPlayerStep;
int prevBotStep;
int tactic;

// |  |  |  |
//-+--+--+--+
// |  |  |  |
//-+--+--+--+
// |  |  |  |

void traningStep() {
    cout << "  " << '1' << " |" << '2' << " |" << '3' << endl;
    cout << " +--+--+--+" << endl;
    cout << "  " << '4' << " |" << '5' << " |" << '6' << endl;
    cout << " +--+--+--+" << endl;
    cout << "  " << '7' << " |" << '8' << " |" << '9' << endl;
}

void makeField() {
    cout << "  " << field[0] << " |" << field[1] << " |" << field[2] << endl;
    cout << " +--+--+--+" << endl;
    cout << "  " << field[3] << " |" << field[4] << " |" << field[5] << endl;
    cout << " +--+--+--+" << endl;
    cout << "  " << field[6] << " |" << field[7] << " |" << field[8] <<endl;
}
void winCheck() {
    if (field[0] == field[1] and field[1] == field[2] and field[0]!=' ') {
        winSide = field[0];
        game = false;
    }
    else if (field[3] == field[4] and field[4] == field[5] and field[3] != ' ') {
        winSide = field[3];
        game = false;
    }
    else if (field[6] == field[7] and field[7] == field[8] and field[6] != ' ') {
        winSide = field[6];
        game = false;
    }
    else if (field[0] == field[4] and field[4] == field[8] and field[0] != ' ') {
        winSide = field[0];
        game = false;
    }
    else if (field[2] == field[4] and field[4] == field[6] and field[2] != ' ') {
        winSide = field[2];
        game = false;
    }
    else if (field[0] == field[3] and field[3] == field[6] and field[0] != ' ') {
        winSide = field[0];
        game = false;
    }
    else if (field[1] == field[4] and field[4] == field[7] and field[1] != ' ') {
        winSide = field[1];
        game = false;
    }
    else if (field[2] == field[5] and field[5] == field[8] and field[2] != ' ') {
        winSide = field[2];
        game = false;
    }
};
void botStep(int playerChoose) {

    if (playerChoose != 4 and stepCount == 0) {
        field[4] = 'O';
        prevPlayerStep = playerChoose;
        tactic = 0;
    }
    if (tactic == 0) {
    if (stepCount == 1) {
        if (playerChoose == 0 or playerChoose == 2 or playerChoose == 6 or playerChoose == 8) {
            switch (playerChoose)
            {
            case 0: if (prevPlayerStep == 6) {
                field[3] = 'O';
                prevBotStep = 3;
                break;
            }
                  else {
                field[1] = 'O';
                prevBotStep = 1;
                break;
            }
            case 2: if (prevPlayerStep == 0) {
                field[1] = 'O';
                prevBotStep = 1;
                break;
            }
                  else {
                field[7] = 'O';
                prevBotStep = 7;
                break;
            }
            case 6: if (prevPlayerStep == 0) {
                field[3] = 'O';
                prevBotStep = 3;
                break;
            }
                  else {
                field[7] = 'O';
                prevBotStep = 7;
                break;
            }
            case 8: if (prevPlayerStep == 2) {
                field[5] = 'O';
                prevBotStep = 5;
                break;
            }
                  else {
                field[7] = 'O';
                prevBotStep = 7;
                break;
            }
            }
            prevPlayerStep = playerChoose;
        }
        else if (playerChoose == 1 or playerChoose == 2 or playerChoose == 6 or playerChoose == 8) {
            if (field[0] == 'X' and field[1] == 'X') {
                field[2] = 'O';
            }
            else if (field[1] == 'X' and field[2] == 'X') {
                field[0] = 'O';
            }
            else if (field[0] == 'X' and field[3] == 'X') {
                field[6] = 'O';
            }
            else if (field[3] == 'X' and field[6] == 'X') {
                field[0] = 'O';
            }
            else if (field[6] == 'X' and field[7] == 'X') {
                field[8] = 'O';
            }
            else if (field[7] == 'X' and field[8] == 'X') {
                field[6] = 'O';
            }
            else if (field[8] == 'X' and field[5] == 'X') {
                field[2] = 'O';
            }
            else if (field[2] == 'X' and field[5] == 'X') {
                field[8] = 'O';
            }
        }
    }
    else if (stepCount == 2) {
        if (field[1] == 'O' and field[4] == 'O' and field[7] == ' ') {
            field[7] = 'O';
        }
        else if (field[3] == 'O' and field[4] == 'O' and field[5] == ' ') {
            field[5] = 'O';
        }
        else if (field[7] == 'O' and field[4] == 'O' and field[1] == ' ') {
            field[1] = 'O';
        }
        else if (field[5] == 'O' and field[4] == 'O' and field[3] == ' ') {
            field[3] = 'O';
        }
        else
            if (field[0] == 'X' and field[1] == 'X') {
                field[2] = 'O';
            }
            else if (field[1] == 'X' and field[2] == 'X') {
                field[0] = 'O';
            }
            else if (field[0] == 'X' and field[3] == 'X') {
                field[6] = 'O';
            }
            else if (field[3] == 'X' and field[6] == 'X') {
                field[0] = 'O';
            }
            else if (field[6] == 'X' and field[7] == 'X') {
                field[8] = 'O';
            }
            else if (field[7] == 'X' and field[8] == 'X') {
                field[6] = 'O';
            }
            else if (field[8] == 'X' and field[5] == 'X') {
                field[2] = 'O';
            }
            else if (field[2] == 'X' and field[5] == 'X') {
                field[8] = 'O';
            }
            else {
                if (field[0] == ' ') {
                    field[0] = 'O';
                }
                else if (field[2] == ' ') {
                    field[2] = 'O';
                }
                else if (field[6] == ' ') {
                    field[6] = 'O';
                }
                else {
                    field[8] = 'O';
                }
            }
        /* switch (prevBotStep)
         {
         case 1:
             if (playerChoose != 7) {
                 field[7] = 'O';
                 break;
             }
         case 3:
             if (playerChoose != 5) {
                 field[5] = 'O';
                 break;
             }
         case 7:
             if (playerChoose != 1) {
                 field[1] = 'O';
                 break;
             }
         case 5:
             if (playerChoose != 3) {
                 cout << prevBotStep << endl;
                 field[3] = 'O';
                 break;
             }
         }*/
        if (playerChoose == 0 or playerChoose == 2 or playerChoose == 6 or playerChoose == 8) {
            if (field[0] == 'X' and field[6] == 'X') {
                field[3] = 'O';
            }
            else if (field[0] == 'X' and field[2] == 'X') {
                field[1] = 'O';
            }
            else if (field[6] == 'X' and field[8] == 'X') {
                field[7] = 'O';
            }
            else if (field[8] == 'X' and field[2] == 'X') {
                field[5] = 'O';
            }
            else {
                if (field[0] == ' ') {
                    field[0] = 'O';
                }
                else if (field[2] == ' ') {
                    field[2] = 'O';
                }
                else if (field[6] == ' ') {
                    field[6] = 'O';
                }
                else if (field[8] == ' ') {
                    field[8] = 'O';
                }
            }
        }
        prevPlayerStep = playerChoose;
    }
    else if (stepCount == 3) {
        if (field[0] == ' ') {
            field[0] = 'O';
        }
        else if (field[2] == ' ') {
            field[2] = 'O';
        }
        else if (field[6] == ' ') {
            field[6] = 'O';
        }
        else if (field[8] == ' ') {
            field[8] = 'O';
        }
        else {
            if (playerChoose == 0 or playerChoose == 2 or playerChoose == 6 or playerChoose == 8) {
                if (field[8] == 'X' and field[2] == 'X') {
                    field[5] = 'O';
                }
                else if (field[8] == 'X' and field[6] == 'X') {
                    field[7] = 'O';
                }
                else if (field[6] == 'X' and field[0] == 'X') {
                    field[3] = 'O';
                }
                else if (field[0] == 'X' and field[2] == 'X') {
                    field[1] = 'O';
                }
            }
            prevPlayerStep = playerChoose;
        }
    }
    }
    
    if (playerChoose == 4 and stepCount == 0) {
        field[0] = 'O';
        tactic = 1;
    }
    if(tactic == 1){
        if (stepCount > 0) {
            if (field[1] == 'X' and field[4] == 'X' and field[7] == ' ') {
                field[7] = 'O';
            }
            else if (field[7] == 'X' and field[4] == 'X' and field[1] == ' ') {
                field[1] = 'O';
            }
            else if (field[2] == 'X' and field[4] == 'X' and field[6]==' ') {
                field[6] = 'O';
            }
            else if (field[6] == 'X' and field[4] == 'X' and field[2] == ' ') {
                field[2] = 'O';
            }
            else if (field[3] == 'X' and field[4] == 'X' and field[5] == ' ') {
                field[5] = 'O';
            }
            else if (field[5] == 'X' and field[4] == 'X' and field[3] == ' ') {
                field[3] = 'O';
            }
            else if (field[2] == 'X' and field[5] == 'X' and field[8] == ' ') {
                field[8] = 'O';
            }
            else if (field[8] == 'X' and field[5] == 'X' and field[2] == ' ') {
                field[2] = 'O';
            }
            else if (field[6] == 'X' and field[7] == 'X' and field[8] == ' ') {
                field[8] = 'O';
            }
            else if (field[7] == 'X' and field[8] == 'X' and field[6] == ' ') {
                field[6] = 'O';
            }
            else if (field[2] == 'X' and field[8] == 'X' and field[5] == ' ') {
                field[5] = 'O';
            }
            else if (field[6] == 'X' and field[8] == 'X' and field[7] == ' ') {
                field[7] = 'O';
            }
            else {
                if (field[1] == ' ') {
                    field[1] = 'O';
                }
                else if (field[2] == ' ') { field[2] = 'O'; }
                else if (field[3] == ' ') { field[3] = 'O'; }
                else if (field[5] == ' ') { field[5] = 'O'; }
                else if (field[6] == ' ') { field[6] = 'O'; }
                else if (field[7] == ' ') { field[7] = 'O'; }
                else if (field[8] == ' ') { field[8] = 'O'; }
            }
        }
    }
   
}

int main()
{
    srand(time(0));
    std::cout << "Hello here is start of a game!\n";
    traningStep();
    while (game) {
        int playerChoose;

        cout << "Choose your field 1-9 : ";
        cin >> playerChoose;

        if ((playerChoose > 0 and playerChoose < 10)and field[playerChoose - 1] == ' ') {

                field[playerChoose - 1] = 'X';
                botStep(playerChoose-1);
                makeField();
                winCheck();
                stepCount++;
        }
        else {
            cout << "Incorect input, please choose between 1 and 9 ;)"<<endl;
        }
        if (stepCount == 5) {
            cout << "Draw!";
            game = false;
        }
    }
    if (stepCount != 5) {
        winSide == 'X' ? cout << "Player is win, congratulation!" : cout << "Player is lose!";
    }
}
