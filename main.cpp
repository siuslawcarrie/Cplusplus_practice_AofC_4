
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctype.h>
#include <stdio.h>
#include <cctype>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

void parseData(ifstream &in, vector<set<string>> &card, vector<vector<string>> &win_num);//data goes into parsedata
//vector map for card data, vector vector win data goes into
int score(vector<set<string>> &card, vector<vector<string>> &win_num);

int main() {
//VARIABLES
    vector<set<string>> card;//card
    vector<vector<string>> win_num;//win_num

    //input file variables & open input file
    ifstream in;//open txt file //creates a cursor that points to the very beginnning of the txt file
    in.open("C:\\Users\\siusl\\CLionProjects\\Cplusplus_practice_AofC_4\\input.txt");
    //if file opens
    if (in.good()) {
        parseData(in, card, win_num);
        cout << score(card, win_num) << endl;
        //if text file won't open
    } else {
        cout << "Could not read file";
        return -1;
    }
    return 0;
}

void parseData(ifstream &in, vector<set<string>> &card, vector<vector<string>> &win_num) {//must be reference
//while NOT end of file
    int counter = 0;
    while (!in.eof()) {//while loop is reading then putting stuff as indicated
        string input;
        in >> input;//put first token into input, move "cursor" to next token
//card.push_back(set())
        if (input == "Card") {//look for token matching "card" string
            set<string> temp; //creates a set called temp
            in >> input; //puts next token into input
            in >> input; //puts next token into input
            while (input != "|") {

                temp.insert(input); //puts the token from input into the set "temp"
                in >> input;//takes the next token in line (next # on the card) puts it inot variable input
            }
            card.push_back(temp);//pushes temp itno the vector "card"

            vector<string> temp1; //creates a set called temp
            in >> input; //puts next token into input
            while (input != "Card") {
                //create temp vector, fill it with numbers using pushback, read out winning numbers
                //loop ends
                //push vector to win num vector like set temp except it's a vector

                temp1.push_back(input);

                in >> input; //puts next token into input
            }
            win_num.push_back(temp1);
        }
        counter++;
    }
}

int score(vector<set<string>> &card, vector<vector<string>> &win_num) {
    return 0;
}
