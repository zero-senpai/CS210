using namespace std;
#include "Item.h"
#pragma once
#include <string>

// Default constructor overload
Item::Item() {
	itemName = "NoName";
	count = 1;
}

/*
*	@func		- Returns the string name of the current item object
*	@params		- None
*/
string Item::getName(){
	return itemName;
}

/*
*	@func		- Sets the name for the item object
*	@params		- strings t_name: String passed from data input received from program's input file
*/
void Item::setName(string t_name) {
	itemName = t_name;
}

/*
*	@func		- Returns an int of the total count of the item object
*	@params		- None
*/
int Item::getCount() {
	return count;
}

/*
*	@func		- Sets the count of the item object
*	@params		- int t_count: int set by the program's input file
*/
void Item::setCount(int t_count) {
	count = t_count;
}