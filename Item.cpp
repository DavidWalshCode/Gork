#include "Item.h"

using namespace zork;

Item::Item (string InName, int inWeightGrams, float inValue/**, int weaponCheck*/)
{
    name = InName;
    setWeight(inWeightGrams);
    value = inValue;
    /**weaponCheck(isWeapon);*/
}

Item::Item(string inName)
{
    name = inName;
}

// Setting weight which includes programmer defined exception
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

// Setting value which includes programmer defined exception
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

string Item::getName()
{
    return name;
}

string Item::getDescription()
{
    return " item(s), " + name + ".\n";
}

Lamp::Lamp() : Item("Lamp", 1000, 10)
{
}

string Lamp::use()
{
    return "The room lit up!";
}
