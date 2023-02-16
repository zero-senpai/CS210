#include "Item_list.h"
#include <iostream>
#include <iomanip>
#include <sstream>

/*
	@func		- When called, adds a new item to our Item List object's map member.
	@params		- Item *item: Item pointer is set to an object Item reference in main.cpp. This lets us dynamically get each one's name and count during loop when we add the product.
*/
void ItemList::addItem(Item *item) {
	items.insert(make_pair(item->getName(), item->getCount()));
	oItems.insert(make_pair(item->getName(), item->getCount()));
}


/*
*	@func		- When called, returns a list of all the items currently in the Item List object's map
*	@params		- None
*/
void ItemList::returnItems() {
	for (auto& elem : items) {
		cout << fixed << setw(45) << setfill(' ') << right;
		cout << elem.first << "         " << elem.second << endl;
	}
}

/*
*	@func		- When called, returns the list of all items but the numeric value becomes represented by a string with corresponding * symbols for a histogram
*	@params		- None
*/
void ItemList::returnHistogram() {
	string bar = "";
	for (auto& elem : items) {
		for (int i = 0; i < elem.second; i++) {
			bar = bar + "*";
		}
		cout << fixed << setw(45) << setfill(' ') << right;
		cout << elem.first << "         " << bar << endl;
		bar = "";
	}
}

/*
*	@func		- Checks the parameter string against the entire Item List object's map member to see if it exists. Returns true if it does, false otherwise.
*	@params		- string t_name: Passed name of the object to match against current map's keys.
*/
bool ItemList::checkIfExist(string t_name) {
	if (items.find(t_name) == items.end()) {
		return false;
	}
	else {
		return true;
	}
}


/*
*	@func		- Increases the count of the key's value in the current map when called.
*	@params		- string product: string passed from call during the program's while loop. Used to match entries in the map.
*/
void ItemList::countItem(string product) {
	items[product]++;
	oItems[product]++;
}


/*
*	@func		- Searches the member map of the object for the passed word and returns the number of matches (which is stored in the value of the pair)
*	@params		- string product: user string passed from main()
*/
int ItemList::singleItemFreq(string product) {
	map<string, int>::iterator it = items.find(product);
	if (it != items.end()) {
		return it->second;
	}
	else {
		return 0;
	}
}