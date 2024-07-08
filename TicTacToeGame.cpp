//
//  main.cpp
//  Tic-Tac-Toe
//
//  Created by Jeremy Andrews on 7/7/24.
//

#include <iostream>
#include <vector>
using namespace std;

//Classes

class Board {
    public:
    
    void printBoard() {
        cout << board[0][0] << board[0][1] << board[0][2] << endl;
        cout << board[1][0] << board[1][1] << board[1][2] << endl;
        cout << board[2][0] << board[2][1] << board[2][2] << endl;
    }
    
    void updateBoard(char _00, char _01, char _02, char _10, char _11, char _12, char _20, char _21, char _22) {
        board[0][0] = _00;
        board[0][1] = _01;
        board[0][2] = _02;
        board[1][0] = _10;
        board[1][1] = _11;
        board[1][2] = _12;
        board[2][0] = _20;
        board[2][1] = _21;
        board[2][2] = _22;
    }
    
    void boardEntry(string choice, int num) {
        char sym;
        if (num == 1) {
            sym = 'X';
        }
        else {
            sym = 'O';
        }
        
        if (choice == "00") {
            updateBoard(sym, checkBoard(board[0][1]), checkBoard(board[0][2]), checkBoard(board[1][0]), checkBoard(board[1][1]), checkBoard(board[1][2]), checkBoard(board[2][0]), checkBoard(board[2][1]), checkBoard(board[2][2]));
        }
        else if (choice == "01") {
            updateBoard(checkBoard(board[0][0]), sym, checkBoard(board[0][2]), checkBoard(board[1][0]), checkBoard(board[1][1]), checkBoard(board[1][2]), checkBoard(board[2][0]), checkBoard(board[2][1]), checkBoard(board[2][2]));
        }
        else if (choice == "02") {
            updateBoard(checkBoard(board[0][0]), checkBoard(board[0][1]), sym, checkBoard(board[1][0]), checkBoard(board[1][1]), checkBoard(board[1][2]), checkBoard(board[2][0]), checkBoard(board[2][1]), checkBoard(board[2][2]));
        }
        else if (choice == "10") {
            updateBoard(checkBoard(board[0][0]), checkBoard(board[0][1]), checkBoard(board[0][2]), sym, checkBoard(board[1][1]), checkBoard(board[1][2]), checkBoard(board[2][0]), checkBoard(board[2][1]), checkBoard(board[2][2]));
        }
        else if (choice == "11") {
            updateBoard(checkBoard(board[0][0]), checkBoard(board[0][1]), checkBoard(board[0][2]), checkBoard(board[1][0]), sym, checkBoard(board[1][2]), checkBoard(board[2][0]), checkBoard(board[2][1]), checkBoard(board[2][2]));
        }
        else if (choice == "12") {
            updateBoard(checkBoard(board[0][0]), checkBoard(board[0][1]), checkBoard(board[0][2]), checkBoard(board[1][0]), checkBoard(board[1][1]), sym, checkBoard(board[2][0]), checkBoard(board[2][1]), checkBoard(board[2][2]));
        }
        else if (choice == "20") {
            updateBoard(checkBoard(board[0][0]), checkBoard(board[0][1]), checkBoard(board[0][2]), checkBoard(board[1][0]), checkBoard(board[1][1]), checkBoard(board[1][2]), sym, checkBoard(board[2][1]), checkBoard(board[2][2]));
        }
        else if (choice == "21") {
            updateBoard(checkBoard(board[0][0]), checkBoard(board[0][1]), checkBoard(board[0][2]), checkBoard(board[1][0]), checkBoard(board[1][1]), checkBoard(board[1][2]), checkBoard(board[2][0]), sym, checkBoard(board[2][2]));
        }
        else if (choice == "22") {
            updateBoard(checkBoard(board[0][0]), checkBoard(board[0][1]), checkBoard(board[0][2]), checkBoard(board[1][0]), checkBoard(board[1][1]), checkBoard(board[1][2]), checkBoard(board[2][0]), checkBoard(board[2][1]), sym);
        }
    }

    char checkBoard(char check) {
        if (check == '_') {
            return '_';
        }
        else {
            return check;
        }
    }
    
    int winCondition(Board gameBoard) {
        for (int count = 0; count < 2; count++) {
            if (board[count][0] == board[count][1]  &&  board[count][0] == board[count][2]  &&  board[count][0] != '_') {
                return 1;
            }
            else if (board[0][count] == board[1][count]  &&  board[0][count] == board[2][count]  &&  board[0][count] != '_') {
                return 1;
            }
            else if (board[0][0] == board[1][1] &&  board[0][0] == board[2][2]  &&  board[0][0] != '_') {
                return 1;
            }
            else if (board[2][0] == board[1][1] &&  board[0][0] == board[0][2]  &&  board[2][0] != '_') {
                return 1;
            }
        }
        return 0;
    }
    
    private:
    char board[3][3] = {{'_', '_', '_'},
                        {'_', '_', '_'},
                        {'_', '_', '_'}};
};


//Functions

void boardHelp() {
    cout << "Enter the two numbers corresponding to the space on the board:" << endl;
    cout << "00 01 02" << endl;
    cout << "10 11 12" << endl;
    cout << "20 21 22" << endl;
}


void turn(Board gameBoard, int num) {
    cout << "The current board is as follows:" << endl;
    
    gameBoard.printBoard();
    
    cout << endl;
    cout << "What slot would you like to change?" << endl;
    cout << "enter column number, then row number, of the spot you are changing" << endl;
    cout << "Enter help for assistance" << endl;
    string choice;
    cin >> choice;
    
    if (choice == "help" || choice == "Help") {
        boardHelp();
        turn(gameBoard, num);
    }
    else {
        gameBoard.boardEntry(choice, num);
    }
    
    if (gameBoard.winCondition(gameBoard) == 1) {   //checks win condiiton
        gameBoard.printBoard();
        cout << "Player " << num << " Is the winner!" << endl;
    }
    else {          //reruns turn function for next player
        if (num == 1) {
            turn(gameBoard, 2);
        }
        else {
            turn(gameBoard, 1);
        }
    }
}



//MAIN

int main() {
    
    cout << "Player one is 'X', player 2 is 'O'" << endl;
    int num = 1;    //represents the player who's current turn is being processed
    Board gameBoard;
    turn(gameBoard, num);
    
    return 0;
}
