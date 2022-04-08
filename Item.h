#ifndef ITEM_H_
#define ITEM_H_

#include <map>
#include <string>
#include <iostream>
#include <exception>

using std::string;
using std::exception;

namespace zork
{

// Programmer defined exception and inheritance
// Exception throw when attempting to set the weight of an item with an invalid weight
class InvalidWeightException : exception
{
public:

    InvalidWeightException(int weight) : exception(), weight(weight)
    {
    }

    const char* what() const throw ()
    {
        return "Weight invalid, must be 0 < weight < 9999";
    }

    const int weight;
};

// Exception throw when attempting to set the value of an item with an invalid value
class InvalidValueException : exception
{
public:
    InvalidValueException(float value) : exception(), value(value)
    {
    }

    const char* what() const throw ()
    {
        return "Value invalid, must be 0 < value < 9999";
    }

    const float value;
};

class Item
{
public:
    Item (string inName, int inWeight, float inValue);
    Item (string inName);
    string getName();
    string getDescription();

    void setWeight(int weightGrams); // can throw InvalidWeightException!
    void setValue(float value); // can throw InvalidValueException!

    float getValue();
    int getWeight();

    // Virtual function, in order to define how subclasses of Item behave when used, this method is marked as virtual.
    virtual string use()
    {
        return "Nothing happened...";
    }

protected:
    string name;
    string description;
    int weightGrams;
    float value;
    bool weaponCheck;
};

// Example of a subclass of Item
class Lamp : Item
{
    Lamp();

    // Define how the Lamp behaves when used, 'overriding' the original behaviour
    string use() override;
};

}

#endif /*ITEM_H_*/
