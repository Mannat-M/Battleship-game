#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unistd.h>

using namespace std;

class Board {
public:
    int size=10;
    string name;

    int hits = 0;
    vector<vector<char>> board;
    vector<vector<char>> guess;

    Board(string name_){
        name = name_;

        for(int i=0; i<size; i++){
            board.push_back(vector<char>(size,'.'));
            guess.push_back(vector<char>(size,'.'));
        }
        add_ships(take_input());

    }

    vector<string> take_input(){
        int A_ct=5, B_ct=4, C_ct=2, D_ct = 4;
        cout<<"\nEnter Ship Coordindates in Format [A-I][0-9] for "<<name<<":\n";

        string inp;
        vector<string> out;
        while(A_ct--){
            cout<<"\nenter A ship coordinates: ";
            cin>>inp;
            out.push_back(inp);
        }
        while(B_ct--){
            cout<<"\nenter B ship coordinates: ";
            cin>>inp;
            out.push_back(inp);
        }
        while(C_ct--){
            cout<<"\nenter C ship coordinates: ";
            cin>>inp;
            out.push_back(inp);
        }
        while(D_ct--){
            cout<<"\nenter D ship coordinates: ";
            cin>>inp;
            out.push_back(inp);
        }
        return out;
    }

    void add_ships(vector<string>inp){

        for (int i=0; i<5; i++){
            string mem = inp[i];
            board[mem[1]-'0'][mem[0]-'A']='A';
        }
        for(int i=5; i<5+4;i++){
            string mem = inp[i];
            board[mem[1]-'0'][mem[0]-'A']='B';
        }
        for(int i=5+4; i<5+4+2;i++){
            string mem = inp[i];
            board[mem[1]-'0'][mem[0]-'A']='C';
        }
        for(int i=5+4+2; i<5+4+2+4;i++){
            string mem = inp[i];
            board[mem[1]-'0'][mem[0]-'A']='D';
        }
    }

    // string play(){
    //     // take a guess
    //     string coo;
    //     cout<<"\nenter guessing coordinates: ";
    //     cin>>coo;
    //     return coo;
    // }

    // bool check(string guess){
    //     // true if hit, else false
    //     string mem = guess;
    //     if ( board[mem[1]-'0'][mem[0]-'A']=='A'|| board[mem[1]-'0'][mem[0]-'A']=='B' || 
    //     board[mem[1]-'0'][mem[0]-'A']=='C' || board[mem[1]-'0'][mem[0]-'A']=='D'){
    //         // hit
    //         hits++;
    //         // update board
    //         board[mem[1]-'0'][mem[0]-'A']='H';
    //         return true;
    //     }
    //     else{
    //         // miss
    //         board[mem[1]-'0'][mem[0]-'A']='*';
    //         return false;
    //     }
    // }

    // void update_guess_board(string mem, bool val){
    //     if (val){
    //         guess[mem[1]-'0'][mem[0]-'A']='H';
    //     }
    //     else{
    //         guess[mem[1]-'0'][mem[0]-'A']='*';
    //     }
    // }


    void print_board(){
        cout<< "Board for user: "<<name<<endl;
        for(int i=0; i<size; i++){
            for(auto mem: board[i]) cout<<mem<<" ";
            cout<<endl;
        }
        cout<<"--------------------------------";
    }

    // void print_guess_board(){
    //     cout<< "\nGuess board for user: "<<name<<endl;
    //     for(int i=0; i<size; i++){
    //         for(auto mem: guess[i]) cout<<mem<<" ";
    //         cout<<endl;
    //     }
    //     cout<<"--------------------------------";
    // }

};

// void play_turn(Board p1, Board p2){
//     int turn =0;

//     while(p1.hits!=10 || p2.hits!=10){
//         if (turn%2==0){
//             // p1 plays
//             sleep(3);
//             system("clear");
//             cout<<"TURN FOR "<<p1.name<<"\n";
//             p1.print_board(); p1.print_guess_board();
//             string guess_by_p1= p1.play();
//             // check for p2
//             bool out = p2.check(guess_by_p1);
//             out ? cout<<"\n==========\nNice guess!\n==========\n" : cout<<"\n==========\nMiss :(\n==========\n";
//             // update the guess board for p1
//             p1.update_guess_board(guess_by_p1, out);

            
//         }
//         else{
//             sleep(3);
//             // p2 plays
//             system("clear");
//             cout<<"TURN FOR "<<p2.name<<"\n";
//             p2.print_board(); p2.print_guess_board();
            
//             string guess_by_p2= p2.play();
//             // check for p1
//             bool out = p1.check(guess_by_p2);
//             out ? cout<<"\n==========\nNice guess!\n==========\n" : cout<<"\n==========\nMiss :(\n==========\n";
//             // update the guess board for p1
//             p2.update_guess_board(guess_by_p2, out);

            
//         }
//         turn ++;
//     }
//     if (p1.hits>=10 && p2.hits>=10)
//         cout<<"DRAW"<<endl;
//     else if (p1.hits>=10){
//         cout<<"HIT AND SUNK BY WINNER: "<<p2.name<<endl;
//     }
//     else {
//         cout<<"HIT AND SUNK BY WINNER: "<<p1.name<<endl;
//     }
//     return;

// }



int main(){
    // vector<vector<char>> board (10, vector<char>(10,'.'));
    string mem1, mem2;
    cout<<"Enter name of two players (separated by space): ";
    cin>> mem1>> mem2;
    
    Board player1 = Board(mem1);
    player1.print_board();

//     cout<<"-----------------\nProceed to "<<mem2<<"? [Y]: ";
//     string y; cin>>y;
//     while(y!="Y"){
//         cin>>y;
//     }
//     system("clear");

//     Board player2 = Board(mem2);
//     player2.print_board();
// //=--------------------------------------------------------------------
//     cout<<"-----------------\nType \"Y\" to start the game: ";
//     cin>>y;
//     while(y!="Y"){
//         cin>>y;
//     }
//     system("clear");
//     play_turn(player1, player2);

    return 0;
}