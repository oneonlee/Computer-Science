#pragma once
#include <string>
using std::string;

class CreateAndDestory {
public:
    CreateAndDestory(int, string);
    ~CreateAndDestory();

private:
    int objectID;
    string message;
};