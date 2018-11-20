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

class InputReader {
private:
    list<string> list_of_strings_;
    list<int> erased_lines_;
    list<string> stop_words_;


public:
    list<string> getListOfStrings();

    list<string> getStopWords();

    list<int> getErasedLines();

    void readSentences();

    void clearBuffer();

    void stopWords();

    void eraseLines();


};

#endif /* input_reader_hpp */
