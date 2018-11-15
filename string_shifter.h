#include <string>
#include <list>
using namespace std;

class StringShifter {
  private:
    list<string> sentences_;
    list<string> shifted_sentences_;
    list<string> stop_words_;
    int ordering_;

    void filter_words(list<string>& words);
  public:

  static bool ascending (const string& s1, const string& s2) {
    return (s1 < s2);
  }

  static bool descending (const string& s1, const string& s2) {
    return (s1 > s2);
  }

  StringShifter(list<string> sentences, list<string> stop_words, int ordering);

  void shift();

  list<string> split(string sentence);

  string join(list<string> words);

  void print();
};
