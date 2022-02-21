#pragma once

#include<vector>
#include<algorithm>
#include<string>

using namespace std;

    int vectorIncludes(vector<double>* vec, double n) {
        auto i = find(vec->begin(), vec->end(), n);
        if (i != vec->end())
        {
            return i - vec->begin();
        }
        return -1;
    };

    int vectorClosest(vector<double>* vec, double n) {
        auto i = std::lower_bound(vec->begin(), vec->end(), n);
        if (i == vec->end()) { return -1; }

        return *i;
    };

    bool isNumber(string val) {
        for (unsigned int i = 0; i < val.size(); i++) {
            char c = val.at(i);
            if (isdigit(c) == 0)  {
                return false;
            }
        }
        return true;
    }

    double toNumber(string val) {
        return stod(val);
    };

    void removeStringWhitespace(string* str) {
        str->erase(remove_if(str->begin(), str->end(), ::isspace), str->end());
    };
