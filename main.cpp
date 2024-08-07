/*
Carrie Bailey
Summer 2024 Practice
Program: You find cards with numbers on them, match them up with the winning numbers from each line. First match
is 1 point, each subsequent match doubles in points.
*/

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
#include <cstring>

using namespace std;
//**FUNCTION DECLARATIONS
void parseData(ifstream &in, vector<set<string>> &card, vector<vector<string>> &win_num);//data goes into parsedata
//vector set for card data, vector vector win data goes into
int
score(vector<set<string>> &card, vector<vector<string>> &win_num); //vector set for winning card data, vector vector
//to put winning numbers into
void display_set(set<string> temp1); //print a set
//**END FUNCTIONS

//**MAIN
int main() {
//VARIABLES
    vector<set<string>> card;//card
    vector<vector<string>> win_num;//winning numbers

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
}//main closing brace
//**END MAIN

//**FUNCTIONS**
//parseData splits up the card string of #s and the winning card string of #s and puts each in a set
void parseData(ifstream &in, vector<set<string>> &card, vector<vector<string>> &win_num) {//must be reference
    string line;//line is where we put the card data
    while (!in.eof())//while not end of file
    {
        getline(in,line);//passing in the stream, and an empty string called line, puts the first line of the txt file into line
        char *temp = &line[0];//creating a pointer called temp, putting a reference (address) of line, first character in line [0]
        string discard = strtok(temp, ":");//removes elements before : "Card" "1:" etc
        string card_nums = strtok(nullptr, "|");//strtok (string token) will split the string by the delimiter | ,
        // before | goes into card nums
        string win_nums = strtok(nullptr, "|");//pass in NULL and delimiter to capture what's after |
//        temp = &card_nums[0]; //reuses temp to put a reference to card nums, calling first character
//        strtok(temp, " ");//discards "Card"
//        strtok(NULL, " ");//discards "1:" etc
        char *temp2 = &card_nums[0];//puts card nums into a pointer

        set<string> temp1; //creates a set called temp1
        char *token = strtok(temp2, " "); //splits card nums by each space
        temp1.insert(token);
        while (line.empty()==1) {
            cout << "token: " << token << " ";
            temp1.insert(token);//inserts each token separated by a space into temp1
            token = strtok(nullptr, " ");//splits string temp2 (card nums) by spaces
//print each token

        }//closing brace - while strlen!=0
cout<<endl;
    }//closing brace while !eof
}//closing brace parse data

//Print what's in a set
/*void display_set(set<string> temp_set) {*//*
    for (int i = 0; i < temp_set.size(); i++) {
        cout << "print set:" << temp_set[i];
    }*/


//read each number from each card one at a time, then read each number from each winning card one at a time
//    int counter = 0;
//    while (!in.eof()) {//while loop is reading then putting stuff as indicated //while NOT end of file
//        string input;
//        in >> input;//put first token into input, move "cursor" to next token
//card.push_back(set())
    /*if (input == "Card") {//look for token matching "card" string
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
        while (input == "Card") {
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
*/

int score(vector<set<string>> &card, vector<vector<string>> &win_num) {
    return 0;
}
