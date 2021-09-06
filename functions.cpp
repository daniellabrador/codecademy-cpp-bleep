#include <bits/stdc++.h>
#include <cctype>
#include "head.hpp"
using namespace std;

// Bleep program --------------------------------
string bleep(string word, string sentence){
    vector<int> char_index;
    vector<string> words_for_checking;
    string lowercase_sentence;

    // Create lowercase version of sentence
    for (size_t i=0, max = sentence.size(); i != max; i++){
        lowercase_sentence += tolower(sentence[i]);
    }

    // Look for the first char of the string
    for(int i=0, max = lowercase_sentence.size(); i != max; i++){
        if (lowercase_sentence[i]==tolower(word[0])){
            char_index.push_back(i);
        }
    }

    // Store potential words to bleep
    string to_push_word_for_checking;
    for (size_t i=0, max = char_index.size(); i != max; i++){
        for (size_t j=0, max = word.size(); j != max; j++){
            to_push_word_for_checking.push_back(lowercase_sentence[char_index[i]+j]);
        }
        words_for_checking.push_back(to_push_word_for_checking);
        to_push_word_for_checking="";
    }

    // Bleep matching instances
    for (size_t i=0, max = char_index.size(); i != max; i++){
        if (words_for_checking[i]==word){
            for(size_t j=0, max=word.size(); j!=max; j++){
                sentence[j+char_index[i]]='*';
            }
        }
    }
    return sentence;
}