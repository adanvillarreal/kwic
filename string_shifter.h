#include <string>
#include <list>
using namespace std;

class StringShifter {
  private:
    list<string> sentences_;
    list<string> shifted_sentences_;
    int ordering_;

  public:
      static bool ascending (const string& s1, const string& s2) {
        return (s1 < s2);
      }

      static bool descending (const string& s1, const string& s2) {
        return (s1 > s2);
      }

      StringShifter(list<string> sentences, int ordering);

      void shift();

      list<string> split(string sentence);

      string join(list<string> words);

      list<string> shifted_sentences();
};
