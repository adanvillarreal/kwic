#include <iostream>
#include <string>
#include <list>
#include "string_shifter.h"
#include "input_reader.h"
#include "filter.h"
using namespace std;

int main() {
     inputReader inputs;
     int c = 0;

    cout << "\nOraciones." << endl;
    // inputs.readSentences();
    list<string> oraciones = {"adan es azul","Gallo a 12", "a", "as sdf s f ", "juan es 123 4"};

    list<string> stop_words = {"a", "12"};

    int ordering = -1;
    while(ordering != 0 && ordering != 1) {
        cout << "Escribe 0 para ascendente, 1 para descendente\n";
        cin >> ordering;
    }

    for(string sentence : shifted_s) {
      cout << c++ << ": " << sentence << '\n';
    }
    c = 0;
    Filter filter;
    filter.filterWords(oraciones, stop_words);
    StringShifter shifter(oraciones, ordering);
    shifter.shift();
    list<string> shifted_s = shifter.shifted_sentences();
    for(string sentence : shifted_s) {
      cout << c++ << ": " << sentence << '\n';
    }
    list<int> indexes ={1, 3};
    c = 0;
    filter.filterIndexes(shifted_s, indexes);
    for(string sentence : shifted_s) {
      cout << c++ << ": " << sentence << '\n';
    }
    return 0;
}
