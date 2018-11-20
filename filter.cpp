#include <stdio.h>
#include <string>
#include <list>
#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>
#include "filter.h"
using namespace std;

Filter::Filter(){

}

void Filter::filterIndexes(list<string> &container, list<int> &indexes) {
    indexes.sort();
    int c = 0;
    auto it = container.begin();
    while(it != container.end()) {
      if(find(indexes.begin(), indexes.end(), c) != indexes.end()) {
        *it = "";
      }
        it++;
        c++;
    }
    it = container.begin();
    while(it != container.end()) {
      if(*it == "") {
        it = container.erase(it);
      } else {
        it++;
      }
    }
}

void Filter::filterWords(list<string> &sentences, list<string> &stop_words) {
  list<string> filtered;
  for(string &sentence : sentences) {
    istringstream ss(sentence);
    list<string> words;
    string word;
    while(ss >> word) {
      auto it = std::find(stop_words.begin(), stop_words.end(), word);
      if( it == stop_words.end()) {
        words.push_back(word);
      }
    }


    stringstream oss;
    copy(words.begin(), words.end(), ostream_iterator<string>(oss, " "));
    sentence = oss.str();
  }
}
