#include <iostream>
#include <string>
#include <list>
#include "string_shifter.h"
#include "input_reader.h"
using namespace std;

int main() {
    inputReader inputs;

    cout << "\nOraciones." << endl;
    inputs.readSentences();
    list<string> oraciones = inputs.getListOfStrings();

    cout << "\nStop words." << endl;
    inputs.readSentences();
    list<string> stop_words = inputs.getListOfStrings();

    int ordering = -1;
    while(ordering != 0 && ordering != 1) {
        cout << "Escribe 0 para ascendente, 1 para descendente\n";
        cin >> ordering;
    }

    StringShifter shifter(oraciones, stop_words, ordering);
    shifter.shift();
    shifter.print();

    return 0;
}
