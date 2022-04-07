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

class Item
{
public:
    Item (string inName, int inWeight, float inValue);
    Item (string inName);
    string getName();
    string getDescription();
    int getWeight();
    void setWeight(int weightGrams);
    float getValue();
    void setValue(float value);
    // int getWeaponCheck();
    // void setWeaponCheck(int weaponCheck);

    virtual string use()
    {
        return "Nothing happened...";
    }

    // Programmer defined exception and inheritance
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

protected:
    string name;
    string description;
	int weightGrams;
	float value;
	bool weaponCheck;
};

class Lamp : Item
{
    Lamp();

    string use() override;
};

}

#endif /*ITEM_H_*/
