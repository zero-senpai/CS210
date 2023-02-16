using namespace std;
#ifndef Item_list_H
#define Item_list_H
#include "Item.h"
#include <map>

class ItemList : public Item {
	public:
		void addItem(Item *item);
		void returnItems();
		bool checkIfExist(string t_name);
		void countItem(string product);
		int singleItemFreq(string product);
		void returnHistogram();					
		map<string, int> oItems;				// This is a simple copy of the protected map only for the output file
	protected:
		map<string, int> items;
		map<string, int>::iterator it;
};



#endif

