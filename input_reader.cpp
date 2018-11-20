#include "input_reader.h"

#include <iostream>
#include <stdio.h>
#include <string>
#include <list>
#include <fstream>



using namespace std;

list<string> inputReader::getListOfStrings(){
    return list_of_strings_;
}

void inputReader::clearBuffer() {
    list_of_strings_.clear();
}

void inputReader::readSentences(){
    int type_of_read;
    string sentence = "";
    cout << "Selecciona un tipo: \n";
    cout << "1 - leer de consola \n";
    cout << "2 - leer de archivo \n";

    cin >> type_of_read;
    cin.ignore();

    if (type_of_read == 1) {
        cout << "Escriba sus oraciones use exit para parar: \n";
        getline(cin, sentence);
        int counter = 0;
        while(sentence != "exit"){
            cout << counter << ": ";
            list_of_strings_.push_back(sentence);
            getline(cin, sentence);

        }
    }
    else{
        string nameOfFile;
        string line;
        cout << "Introduce nombre de archivo \n";
        cin >> nameOfFile;
        cin.ignore();

        ifstream myfile(nameOfFile);

        if(myfile.is_open()) {
            while(getline(myfile, line)) {
                cout << line << endl;
            }
        }
        else {
            cout << "No se pudo abrir." << endl;
        }
        myfile.close();
    }

}
