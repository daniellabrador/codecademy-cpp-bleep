#include <vector>
#include <iostream>
#include <string>
#include "head.hpp"
using namespace std;

// Store sample data for testing. ---------------
string const sample_text = "The next big thing are broccolis. I sometimes eat broccoli. There are three interesting things about broccoli. Number One. Nobody knows how to spell it. Number Two. No matter how long you boil it, it's always cold by the time it reaches your plate. Number Three. It's green. Broccolis are the next big thing. bRoccoli! bROCCOLi! #broccoli";

// Ask user for a string to go through the linter
string text_to_check, &text_to_filter = text_to_check;
void ask_string(){
    cout<<"ENTER THE TEXT YOU WISH TO FILTER:\n";
    cout<<"If you want to use a sample text, enter \"_broccoli\" (include underscore).\n";
    getline(cin, text_to_check);
    cout<<"\n";

    if (text_to_check=="_broccoli"){
        text_to_check=sample_text;
        cout<<"Inputting sample text:\n"<<sample_text<<"\n\n";
    }
}

// Look for the index of the word "broccoli" ----
vector<int> b_index;
vector<string> words_for_checking;

void locate_broccoli(){
    // Look for char `B`
    for(int i=0; i<text_to_check.size();i++){
        if (text_to_check[i]=='b'||text_to_check[i]=='B'){
            b_index.push_back(i);
        }
    }

    // Store potential "broccoli"
    string word_to_push_for_checking;
    for (int i=0; i<b_index.size(); i++){
        for (int j=0; j<8; j++){
            word_to_push_for_checking.push_back(text_to_check[b_index[i]+j]);
        }
        words_for_checking.push_back(word_to_push_for_checking);
        word_to_push_for_checking="";
    }
}

// Filter the word is broccoli ------------------
void bleep_text(){
    for (int i=0; i<b_index.size(); i++){
        if (words_for_checking[i]=="broccoli" || words_for_checking[i]=="Broccoli" || words_for_checking[i]=="BROCCOLI"){
            for(int j=0; j<8; j++){
                text_to_filter[j+b_index[i]]='*';
            }
        }
    }

    // Output result
    cout<<"Filtered text:\n"<<text_to_filter;
}

int main(){
    ask_string();
    locate_broccoli();
    bleep_text();
}