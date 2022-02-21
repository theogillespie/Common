#pragma once

#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <cctype>
#include <stdlib.h>
#include <iostream>

#include "Console.h"
#include "../Misc.h"

using namespace std;

// configuration format:
// name (key) = value (string or double)
// # means comment and is ignored


#define _COMMENT "#"
#define _ASSIGN "="

struct configElement {
    string name;
    string value;
    
    string getString() {
        ostringstream os;
        os << this->name << ":" << this->value;
        return os.str();
    };
};

class ConfigParseError : public exception
{
public:
    const string descriptionBase = "Error encountered when parsing config";
    string description;

    ConfigParseError(string file, unsigned int lineNumber) {
        this->description = descriptionBase + "(" + file + ", line: " + to_string(lineNumber) + ")";
    };

    const char* what()
    {
        return this->description.c_str();
    };
};

class ConfigReader {
string filePath;
public:

    vector<configElement> elements = vector<configElement>();

    ConfigReader(string location) {
        this->filePath = location;
    };

    ConfigReader() {}

    vector<configElement>* parse() {
        ifstream ifs(this->filePath, ifstream::in);
        vector<string> lines;

        string line;
        while (getline(ifs, line)) {
            if (line.empty()) {
                continue;
            }
            lines.push_back(line);
        }

        for(int i = 0; i < lines.size(); i++) {
            try {
                line = lines[i];
                if (line.find(_COMMENT) != string::npos) {
                    continue;
                }
                if (line.find(_ASSIGN) == string::npos) {
                    Console::error(ConfigParseError(this->filePath, i).what());
                    continue;
                }
                
                configElement element;
                element.name = line.substr(0, line.find("="));
                element.value = line.substr(line.find("=")+1, line.length());

                removeStringWhitespace(&element.name);
                removeStringWhitespace(&element.value);

                this->elements.push_back(element);

            } catch (const std::exception& e) {
                Console::error(ConfigParseError(this->filePath, i).what());
            };
        }
        
        return &this->elements;
    };
};

