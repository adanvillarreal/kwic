#include <string>
#include <list>
#include <iostream>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>
using namespace std;

class StringShifter {
  private:
    list<string> sentences_;
    list<string> shifted_sentences_;
    list<string> stop_words_;
    int ordering_;

    void filter_words(list<string>& words) {
      for(string stop_word : stop_words_) {
        words.remove(stop_word);
      }
    }

  public:
    static bool ascending (const string& s1, const string& s2) {
      return (s1 < s2);
    }

    static bool descending (const string& s1, const string& s2) {
      return (s1 > s2);
    }

    StringShifter(list<string> sentences, list<string> stop_words, int ordering) {
      sentences_ = sentences;
      stop_words_ = stop_words;
      ordering_ = ordering;
    }

    void shift() {
      for(string sentence : sentences_) {
        list<string> words = split(sentence);
        string aux;
        for(int i = 0; i < words.size(); i++) {
          shifted_sentences_.push_back(join(words));
          aux = words.back();
          words.pop_back();
          words.push_front(aux);
        }
      }
    }

    list<string> split(string sentence) {
      istringstream ss(sentence);
      list<string> words;
      string word;
      while(ss >> word) {
        words.push_back(word);
      }
      filter_words(words);
      return words;
    }

    string join(list<string> words) {
      stringstream ss;
      copy(words.begin(), words.end(), ostream_iterator<string>(ss, " "));
      return ss.str();
    }

    void print() {
      if(ordering_ == 0) {
        shifted_sentences_.sort(ascending);
      } else if(ordering_ == 1) {
        shifted_sentences_.sort(descending);
      }
      for(string sentence : shifted_sentences_) {
        cout << sentence << '\n';
      }
    }
};
