/*
*       Corner Grocer Inventory Frequency Report Console Application
*       Written by Jake E. Brunton, 2023.
*       For CS-210, SNHU Computer Science
*       Version 1.0 2/16/2023 2:47 PM
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <iomanip>
#include "Item.h"
#include "Item_list.h"
using namespace std;


/*
*   @func       - When called, creates or updates date for the given 'list' object's map member.
*   @params     - ItemList& list: reference of the ItemList object declared in main().
*                 Item* Itm: a pointer for Item type, see main()
*                 string productName: Filled in from a filestream and passed to send to ItemList member function calls.
*/
void createData(ItemList& list, Item* Itm, string productName) {

    if (list.checkIfExist(productName) == true) {
        list.countItem(productName);
    }
    else if (list.checkIfExist(productName) == false) {
        Itm->setName(productName);
        Itm->setCount(1);
        list.addItem(Itm);
    }
    else {
        return;
    }
}

/*
*   @func       - Prints the user menu to clear up main()
*/
void printMenu() {
    cout << fixed << setw(125) << left;
    cout << "Welcome to the Corner Grocer sales report program. Input the number corresponding to the menu option you wish to select." << endl;
    cout << "[1] Search for Item and its Frequency in the report" << endl;
    cout << "[2] Print list of Items and their Frequeuncy of Sales" << endl;
    cout << "[3] Print histogram of Items and their Freuquency of Sales" << endl;
    cout << "[4] Exit Program." << endl;
    cout << "*****************************************************************************************\n" << endl;
}

/*
*   @func       - Used to confirm that at least one alpha character is in the search string. Elsewise throw error on false return (see main while loop)
*   @params     - string input: string passed by user input in call to check for alpha characters.
*/
bool confirmInput(string input) {
    if (any_of(begin(input), end(input), isalpha)) {
        return true;
    }
    else {
        return false;
    }
}


/*
*   @func       - Begin main() program
*/
int main()
{
    ItemList list;
    ifstream file;
    ofstream ofile;
    Item* Itm;              // @pointer - Allocate our data for our Item objects to dynamically add new objects into our map object
    Item product;
    Itm = &product;         // Pass a reference of each new actual Item object "product" to our pointer
    string productName;
    int select = 0;
    cin.exceptions(ios_base::failbit);      // Handler for misinput in the user menus

    /*
    *   Before anything else, we delete the current backup file to create a new one (assuming the Input_File.txt has new content before starting)
    */
    file.open("frequency.dat");
    if (file.good()) {
        file.close();
        remove("frequency.dat");
    }

    try {
        file.open("Input_File.txt");
        if (file.fail()) {
            throw runtime_error("Could not open file. Program must have a \"Input_File.txt\" file in directory to run.");
        }
        ofile.open("frequency.dat");
    }
    catch (runtime_error& err) {
        cout << err.what() << endl;
        return 0;
    }

    /*
        Import data from the text file and populate the ItemList object's map member with the data. See void createData()
    */
    file >> productName;
    while (!file.fail()) {
        createData(list, Itm, productName);
        file >> productName;
    }
    file.close(); //Close input file
    for (auto& elem : list.oItems) {
        ofile << elem.first << " " << elem.second << "\n";
    }
    ofile.close(); // Close our output file
    
    cout << "Current text file imported and processed! Backup   frequency.dat   has been created!" << endl;
    cout << "*****************************************************************************************" << endl;
    printMenu();


    while (select != 4) {
        try {
            cout << "\nPlease input menu choice:   ";
            cin >> select;
            if (select == 1) {
                string itemQuery = "none";
                while (itemQuery != "exit") {
                    try {
                        cout << "Type the name of the item you wish to find (case sensitive) Type \"exit\" to return to menu:    ";
                        cin >> itemQuery;
                        if (confirmInput(itemQuery)) {
                            cout << "*********************************************" << endl;
                            cout << "\"" << itemQuery << "\" Frequency in report: " << list.singleItemFreq(itemQuery) << " sales." << endl;
                            cout << "*********************************************" << endl;
                            continue;
                        }
                        else {
                            throw runtime_error("invalid");
                        }
                    }
                    catch (runtime_error err) {
                        cout << "Invalid input. Try again." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                    
                }

            }
            if (select == 2) {
                cout << "\nCurrent filed report of Items with their sales frequency:" << endl;
                list.returnItems();
            }
            if (select == 3) {
                list.returnHistogram();
            }
            
        }
        catch (exception ex) {
            cout << "Invalid input -- try again" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    cout << "Goodbye." << endl;
    return 0;


    //USED FOR TESTING OUR DATA: list.returnItems();


}
