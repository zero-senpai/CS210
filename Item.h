using namespace std;
#include <string>
#ifndef Item_H
#define Item_H

class Item {
	public:
		Item();
		string getName();
		void setName(string t_name);
		int getCount();
		void setCount(int t_count);
	protected:
		string itemName;
		int count;
};



#endif
