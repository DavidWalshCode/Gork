#include "Item.h"

using namespace zork;

Item::Item (string inDescription, int inWeightGrams, float inValue/**, int weaponCheck*/)
{
    description = inDescription;
    setWeight(inWeightGrams);
    value = inValue;
    /**weaponCheck(isWeapon);*/
}

Item::Item(string inDescription)
{
    description = inDescription;
}

// Programmer defined exception for setting weight
void Item::setWeight(int inWeightGrams)
{
    if (inWeightGrams > 9999 || inWeightGrams < 0)
    {
        throw InvalidWeightException(inWeightGrams);
    }
    else
    {
        weightGrams = inWeightGrams;
    }
}

int Item::getWeight()
{
    return weightGrams;
}

// Programmer defined exception for setting value
void Item::setValue(float inValue)
{
    if (inValue > 9999 || inValue < 0)
    {
        throw InvalidValueException(inValue);
    }
    else
    {
        value = inValue;
    }
}

float Item::getValue()
{
    return value;
}

/**void Item::setWeaponCheck(int isWeapon)
{
    if(isWeapon > 0 || isWeapon < 0)
        cout << "Item not a weapon" ;
    else
        cout << "Item is a weapon" ;
}*/

string Item::getShortDescription()
{
    return description;
}

string Item::getLongDescription()
{
    return " item(s), " + description + ".\n";
}

