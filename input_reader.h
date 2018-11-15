//  input_reader.hpp
//  KIWIC
//
//  Created by Hal Perry Cardenas on 11/14/18.
//  Copyright © 2018 Hal Perry Cardenas. All rights reserved.
//

#ifndef input_reader_h
#define input_reader_h

#include <stdio.h>
#include <string>
#include <list>

using namespace std;

class inputReader {
private:
    list<string> list_of_strings_;


public:
    list<string> getListOfStrings();

    void readSentences();

    void clearBuffer();



};

#endif /* input_reader_hpp */
