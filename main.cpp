#include <iostream>
#include <string>
#include <list>
#include "string_shifter.h"
#include "input_reader.h"
#include "filter.h"
using namespace std;

int main() {
     InputReader inputs;
     Filter filter;
     cout << "\nOraciones." << endl;
     inputs.readSentences();
     list<string> filtered_list;
     list<int> indexes;
     int c = 1;


    // inputs.readSentences();
    list<string> oraciones = inputs.getListOfStrings();

    inputs.stopWords();

    list<string> stop_words = inputs.getStopWords();

    cout << "\nLineas a ignorar\n";

    inputs.eraseLines();
    indexes = inputs.getErasedLines();
    filter.filterIndexes(oraciones, indexes);

    int ordering = -1;
    while(ordering != 0 && ordering != 1) {
        cout << "Escribe 0 para ascendente, 1 para descendente\n";
        cin >> ordering;
    }

    filter.filterWords(oraciones, stop_words);
    StringShifter shifter(oraciones, ordering);
    shifter.shift();

    list<string> shifted_s = shifter.shifted_sentences();
    for(string sentence : shifted_s) {
      cout << c++ << ": " << sentence << '\n';
    }
    inputs.clearBuffer();

    cout << "\nLineas a ignorar\n";
    inputs.eraseLines();
    c = 1;
    indexes = inputs.getErasedLines();
    filter.filterIndexes(shifted_s, indexes);
    for(string sentence : shifted_s) {
      cout << c++ << ": " << sentence << '\n';
    }
    return 0;
}
