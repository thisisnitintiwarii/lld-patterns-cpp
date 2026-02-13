// Tic Tac Toe Game 

#include <bits/stdc++.h>
using namespace std;

class Player {
public: 
    string name;
    char symbol;
    Player(string name, char symbol){
        this->name = name;
        this->symbol = symbol;
    }
};

// Now prepare Board 

class Board{

    vector<vector<char>> grid;

public:
    Board(){
        grid = vector<vector<char>>(3, vector<char>(3, ' '));
    }

    bool placeMove(int row, int col, char symbol){
        if(row < 0 || row >= 3 || col < 0 || col >= 3){
            return false;
        }
        if(grid[row][col] != ' '){
            return false;
        }
        grid[row][col] = symbol;

        for(auto i : grid){
            for(auto j : i){
                cout << j <<" ";
            }
            cout <<"\n";
        }
        cout <<"NextMove\n";

        return true;
    }

    bool checkWin(char symbol){
        for (int i = 0; i < 3; i++) {
            if (grid[i][0] == symbol && grid[i][1] == symbol && grid[i][2] == symbol)
                return true;
            if (grid[0][i] == symbol && grid[1][i] == symbol && grid[2][i] == symbol)
                return true;
        }

        if (grid[0][0] == symbol && grid[1][1] == symbol && grid[2][2] == symbol)
            return true;
        if (grid[0][2] == symbol && grid[1][1] == symbol && grid[2][0] == symbol)
            return true;

        return false;
    }

};

// Now create orchestra class 

class Game{
    Player A;
    Player B;
    Board board;
    bool turn;

public:
    Game() : A("playerA",'X') , B("playerB",'O'), turn(true){}

    void playMove(int row, int col){

        Player& current = turn ? A : B;

        if(board.placeMove(row,col,current.symbol) == false){
            cout << "Invalid Move \n";
            return;
        };

        if(board.checkWin(current.symbol)){
            cout << current.name << " Win this game \n";
            return;
        }
        turn = !turn;
    }

};



void solve() {

    Game game;

    game.playMove(0,0);  // PlayerA (X)
    game.playMove(1,1);  // PlayerB (O)
    game.playMove(0,1);  // PlayerA (X)
    game.playMove(1,0);  // PlayerB (O)
    game.playMove(0,2);  // PlayerA (X) -> WIN

}

int main() {
    solve();
    return 0;
}
