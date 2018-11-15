#include <list>
#include <string>
#include <stdio.h>
#include <fstream>
#include <iostream>
using namespace std;

class inputReader {
	private:
		list<string> list_of_strings_;


	public:
		list<string> getListOfStrings(){
			return list_of_strings_;
		}

		void readSentences(){
			int type_of_read = 0;
			string sentence = "";

			while(type_of_read != 1 && type_of_read != 2) {
				cout << "Selecciona un tipo: \n";
				cout << "1 - leer de consola \n";
				cout << "2 - leer de archivo \n";

				cin >> type_of_read;
			}
			cin.ignore();

			if (type_of_read == 1) {
				cout << "Escriba sus oraciones use exit para parar: \n";
				getline(cin, sentence);
				while(sentence != "exit" && sentence != "Exit"){
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

				ifstream myfile(nameOfFile.c_str());

				if(myfile.is_open()) {
					while(getline(myfile, line)) {
						cout << line << endl;
					}
					myfile.close();
				}
				else {
					cout << "No se encontró el archivo" << endl;
				}
			}
		}

    void clearBuffer() {
    	list_of_strings_.clear();
    }



};