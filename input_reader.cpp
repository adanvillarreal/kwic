#include "input_reader.h"

#include <iostream>
#include <stdio.h>
#include <string>
#include <list>
#include <fstream>
#include <cctype>

using namespace std;

list<string> InputReader::getListOfStrings(){
    return list_of_strings_;
}

list<int> InputReader::getErasedLines(){
    return erased_lines_;
}

list<string> InputReader::getStopWords(){
    return stop_words_;
}

void InputReader::clearBuffer() {
    stop_words_.clear();
    erased_lines_.clear();
    list_of_strings_.clear();
}

void InputReader::readSentences(){
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
        while(sentence != "exit"){
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
            cout << "no esta abierto" << endl;
        }

        /*
        myfile.open(nameOfFile);
        cout << nameOfFile + "\n";
        while(getline(cin, line) && line != EOF){
            cout << line + "\n";
            list_of_strings_.push_back(line);

        }
          */

        myfile.close();
    }
}

void InputReader::stopWords(){
    string stop_word = "";
    string nameOfFile;
    int type;


    cout << "En que formato quieres ingresar tus stop words 1-Terminal , 2-Archivo";
    cin >> type;

    if(type == 1){
        cout << "Ingresa tus stop words use 0 para parar \n";
        cin >> stop_word;
        while(stop_word != "0"){
            int i =0;
            while(stop_word[i]){
                stop_word[i] = tolower(stop_word[i]);
                i++;
            }
            stop_words_.push_back(stop_word);
            cin >> stop_word;
        }
    }
    else{
        cout << "Ingresa nombre de archivo";
        cin >> nameOfFile;
        cin.ignore();
        string line;

        ifstream myfile(nameOfFile);

        if(myfile.is_open()) {
            while(getline(myfile, line)) {
                int i = 0;
                while(line[i]){
                    line[i] = tolower(line[i]);
                    i++;
                }
                cout << line + "\n";
                stop_words_.push_back(line);
            }
        }

    }
}

void InputReader::eraseLines(){

    list<int> list_lines;
    cout << "Escribe el numero de linea que desees borrar ingresa 0 para terminar \n";
    int line;
    cin >> line;

    while(line != 0){
        erased_lines_.push_back(line-1);
        cin >> line;
    }
}
