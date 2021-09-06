#include <bits/stdc++.h>
#include "head.hpp"
using namespace std;

// Bleep program --------------------------------
string bleep(string word, string text){
    vector<int> char_index;
    vector<string> words_for_checking;
    string lowercase_text;

    // Create lowercase version of text
    for (size_t i=0, max = text.size(); i!=max; ++i){
        lowercase_text += tolower(text[i]);
    }

    // Look for the first char of the string
    for(int i=0, max = lowercase_text.size(); i!=max; ++i){
        if (lowercase_text[i]==tolower(word[0])){
            char_index.push_back(i);
        }
    }

    // Store potential words to bleep
    string to_push_word_for_checking;
    for (size_t i=0, max = char_index.size(); i!=max; ++i){
        for (size_t j=0, max = word.size(); j!=max; ++j){
            to_push_word_for_checking.push_back(lowercase_text[char_index[i]+j]);
        }
        words_for_checking.push_back(to_push_word_for_checking);
        to_push_word_for_checking="";
    }

    // Bleep matching instances
    for (size_t i=0, max = char_index.size(); i!=max; ++i){
        if (words_for_checking[i]==word){
            for(size_t j=0, max=word.size(); j!=max; ++j){
                text[j+char_index[i]]='*';
            }
        }
    }
    return text;
}