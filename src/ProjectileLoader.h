#pragma once

#include "ConfigReader.h"

#include <string>
#include <vector>

using namespace std;

class FieldMissingError: public exception
{
public:
    const string base = "Missing Field in Projectile Configuration: ";
    string var;
    FieldMissingError(string field) {
       this->var = field;
    };

    const char* what()
    {
        return (this->base + this->var).c_str();
    };
};

struct ProjectileConfigField {
    string name;
    string valueS;
    double valueD;

    ProjectileConfigField(string label) {
        this->name = label;
    }
};

class ProjectileLoader {
public: 

    ConfigReader cr;

    vector<ProjectileConfigField*> fields;

    ProjectileLoader(string filepath, vector<ProjectileConfigField*> configFields) {
        cr = ConfigReader(filepath);
        this->fields = configFields;
    };
    
    void load() {
        try {
            this->cr.parse();
          
        } catch(const std::exception& e) {
           Console::error("Error while loading projectile configuration: " + *e.what());
        }

 
        for(int i = 0; i < this->cr.elements.size(); i++) {
           configElement element = cr.elements[i];
           bool found = false;
           for (int j = 0; j < this->fields.size(); j++) {
               ProjectileConfigField* field = this->fields[j];
               if(element.name == field->name) {
                   if(configElement::isNumber(element.value)) {
                       field->valueD = configElement::toNumber(element.value);
                   }
                   else {
                       field->valueS = element.value;
                   }
                   found = true;
                   break;
               }
           }
           if(!found) {
               Console::error(FieldMissingError(element.name).what());
           }
        }

        
    }
};