#include <bits/stdc++.h>
#include "head.hpp"
using namespace std;

int main(){
    ios::sync_with_stdio(0);

    // Ask user input -------------------------------
    string text, word;
    
    cout<<"ENTER THE TEXT YOU WISH TO FILTER:\n";
    cout<<"If you want to use a sample text, enter \"_broccoli\" (include underscore).\n";
    getline(cin, text);

    cout<<"Enter word to be bleeped (suggested: broccoli): ";
    cin>>word;

    cout<<"\n";

    // Check if user likes to use template ----------
    string const sample_text = "The next big thing are broccolis. I sometimes eat broccoli. There are three interesting things about broccoli. Number One. Nobody knows how to spell it. Number Two. No matter how long you boil it, it's always cold by the time it reaches your plate. Number Three. It's green. Broccolis are the next big thing. #bRoccoli #BROCCOLI #broccoli";

    if (text=="_broccoli"){
        text=sample_text;
        cout<<"Inputting sample text:\n"<<sample_text<<"\n\n";
    }

    // Run bleep program ----------------------------
    cout<<"Filtered text:\n"<<bleep(word, text);
    return 0;
}