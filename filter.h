#include <stdio.h>
#include <string>
#include <list>

using namespace std;
class Filter{
    public:
        Filter();
        void filterIndexes(list<string> &container, list<int> &indexes);
        void filterWords(list<string> &words, list<string> &stop_words);
};
