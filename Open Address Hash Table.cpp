//including everything I need for the program
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <typeinfo>

using namespace std;
//making a templated class that I will need later on
template<class T>
class HashTable
{	
	
	

		public:
//prototyping methods

	void initaliseTable();
	void readAndInput();
	T convert(string);
	void showElement();
	void printString();
	void NumberOfElements();
	void DeleteFromTable();
	void menu();
//constructor
	HashTable(){

	initaliseTable();

			}

//initializing parameters and data structures I will need later on.
		private:
	int size, sum, finalSum, searchFinal, searchSum;
	T  last_element ;	
	string STR, userinput, userSearchput;
	vector<T> Table;
	bool * boolArray;
	

};
//seting up the size of the table, as big as the user wishes
//templating
template<typename T>
void HashTable<T>::initaliseTable(){

	cout << " Please enter the size that you want the table to be " << endl;
	cin >> size;
	Table.resize(size);
//also setting up a array to go along with the vector, so i can check if the index is empty or not
	boolArray = new bool[size];
	for (int i = 0; i<size ; i++)
		boolArray[i]=false;
	}

//templating
template<typename T>
void HashTable<T>::readAndInput()
{
	// asking the user for element insertion.
	 cout << " Please enter the element you wish to insert " << endl;
	 getline( cin, userinput );
  	 STR = userinput;
	

	// taking the ASCII value of the user input
  	for (unsigned int i = 0; i < STR.size(); i++) {
    	sum += STR[i];
	
  }
	
	finalSum = sum % size;
	// converting user input to template using a function that you will see later in the code.
	T newName = convert(STR);
	

 
//for loop to check if the index in the array is true or false
	for(int j=finalSum ; j < (size+finalSum) ; j++){
	//adds element to the table if the slot is free
	if(boolArray[finalSum] == false){
        Table.at(j%size) = newName;
	boolArray[j%size] = true;
	finalSum = 0;
	sum = 0;

			
	break;
			}
	// checks if the slot in the table is full
	if( (boolArray[finalSum] == true))
	{
		// if the element is full and the same as the user input, go out of the for loop and print out a message to the user for error.
		if(Table.at(finalSum) == newName){
			
			cout << "The element is already in the table, you can't put it in again"<< endl; 
			finalSum = 0;
			sum = 0;
			return;
			}
				
		}
		}
	
	}




//templating
template<typename T>
//looking up an element that the user wants to find.
void HashTable<T>::showElement()
{
	cout << "Please input the name of the element that you wish to find " << endl;
	cin.ignore();
	getline( cin, userSearchput );
  	 STR = userSearchput;
	
	
	//same as the insert method, taking the hash key and making it 
  	for (unsigned int i = 0; i < STR.size(); i++) {
    	searchSum += STR[i];
	
	}
	searchFinal = searchSum % size;
	T newName = convert(STR);

	
	// comparing whatever the user inputed to the same thing in the index of the vector, showing the results on screen.
	if(Table.at(searchFinal) == newName){
	cout << " Found the element " << userSearchput << endl;
	searchFinal = 0;
	searchSum = 0;
	return;
	}
	
	cout << " Element is missing ";
	searchFinal = 0;
	searchSum = 0;

}


//templating
template<typename T>
//print out the table to the screen with the elements in the indexes 
void HashTable<T>::printString()
{
	//simple for loop that goes thruough the whole vector
	for(unsigned int i = 0; i < size; i++)		
	{ 

			//check if the array is empty, if it is, print the element as empty.
		if(boolArray[i] == false){
		cout << "Position " << i  << " is empty " << endl;
	
		// if the array is not empty(true), print the element in that position from the vector 				
	}else{
	
		cout << "Position " << i  << " has the element " << Table[i] << endl;		

		}
	}
}

//templating
template<typename T>
//converting user input using string stream 
T HashTable<T>::convert(string converter){

	T converted;
	stringstream stream;
    stream.str("");
    stream.clear();
 
    (stream)<<converter;
    (stream)>>converted;

    return converted;

} 
//templating
template<typename T>
void HashTable<T>::DeleteFromTable()
{
	
	 cout << "Please enter the element you wish to delete. " << endl;
	 getline( cin, userinput ); 
  	 STR = userinput;
	

	//does the same thing as the inserting element method
  	for (unsigned int i = 0; i < STR.size(); i++) {
    	sum += STR[i];
	
  }
	
	finalSum = sum % size;
	T newName = convert(STR);

		
	//looks for true values in the array.
	if(boolArray[finalSum] == true)
	{
		//if you find the element that the user is looking for, delete it by switching it with the last index of the vector and pop it.
		if(Table.at(finalSum) == newName){
			
			Table.at(finalSum) = Table.back();
			Table.pop_back();
			boolArray[finalSum] = false;
			}else if(Table.at(finalSum) == Table.at(size))
{
					Table.pop_back();
					boolArray[finalSum] = false;
}			
				
			return;
		}
	


	//if the element is not in the vector just go out of the function 
	if(boolArray[finalSum] == false){
		
		finalSum = 0;
		sum = 0;
		return;
	} 
	
	for(int j=finalSum ; j < (size+finalSum) ; j++){

		if(boolArray[finalSum] == false){
			
			boolArray[j%size] = true;
	
			finalSum = 0;
			sum = 0;
	
			break;
			}
		}
	
}
//templating
template<typename T>
//simple method to find the number of elements in the table, i don't think it needs commenting.
void HashTable<T>::NumberOfElements(){

		int elements = 0; 

		for(unsigned int i = 0; i < size; i++)		
		{
		
		if(boolArray[i] == false){

		elements = elements + 0;
	
						
		}else{
		
		elements = elements + 1;		

		}
		
	}


	cout << "The elements in the table are " << elements << endl;

}
//Menu in a menu, Menuception. Calling this class from the main method so I don't make a mess there. I decided to make a mess here.
void menu(){
	string myChoice1;
	string myChoice;

//basically makes a object of Hash Table class of whatever the user wants, and goes to that part of the second menu.
do{
	cout << "=============================" << endl;
	cout << "     Input your Choice" << endl;
	cout << "        Chose a table" << endl;
	cout << "i)      Integer table " << endl;
	cout << "s)      String table" << endl;
	cout << "f)      Float table" << endl;
	cout << "d)      Double table " << endl;
	cout << "c)      Char table " << endl;
	cout << "x)      Exit" << endl;
	getline ( cin, myChoice1);

	if(myChoice1 == "i"){
	HashTable<int> intObject;
do{	
	cout << "=============================" << endl;
	cout << "Input your Choice" << endl;
	cout << "i) Add an element to the table" << endl;
	cout << "p) Print out the table " << endl;
	cout << "d) Delete an element from the table." << endl;
	cout << "l) Find an element in the table" << endl;
	cout << "s) Show number of elements in the table " << endl;
	cout << "c) create a new table " << endl;
	cout << "q) Exit" << endl;
	
	getline( cin, myChoice );

	cout << "Your choice was " << myChoice << endl;
	
  	if(myChoice == "i"){
	intObject.readAndInput();
	cout << " Insertion of an element completed. " << endl;
	
	}
  	if(myChoice == "p"){
	intObject.printString();
	cout << " Printing of elements completed. " << endl;
	
	}

  	if(myChoice == "d"){
	
	intObject.DeleteFromTable();
	
	}
	if(myChoice == "l"){
	
	intObject.showElement();
	cout << " Looking up an element completed. " << endl;
	}

	if(myChoice == "s"){
	intObject.NumberOfElements();
	cout << " Size of the table completed. " << endl;
	
	
	}
	if(myChoice == "c"){
		break;
		
	}
	}while(myChoice != "q");
	
	cout << " Your journey through the mystic lands of this code has ended. Have a good day. " << endl;
		}
	if(myChoice1 == "s"){
	HashTable<string> strObject;
do{	
	cout << "=============================" << endl;
	cout << "Input your Choice" << endl;
	cout << "i) Add an element to the table" << endl;
	cout << "p) Print out the table " << endl;
	cout << "d) Delete an element from the table." << endl;
	cout << "l) Find an element in the table" << endl;
	cout << "s) Show number of elements in the table " << endl;
	cout << "c) create a new table " << endl;
	cout << "q) Exit" << endl;
	
	getline( cin, myChoice );

	cout << "Your choice was " << myChoice << endl;
	
  	if(myChoice == "i"){
	strObject.readAndInput();
	cout << " Insertion of an element completed. " << endl;
	
	}
  	if(myChoice == "p"){
	strObject.printString();
	cout << " Printing of elements completed. " << endl;
	
	}

  	if(myChoice == "d"){
	
	strObject.DeleteFromTable();
	
	}
	if(myChoice == "l"){
	
	strObject.showElement();
	cout << " Looking up an element completed. " << endl;
	}

	if(myChoice == "s"){
	strObject.NumberOfElements();
	cout << " Size of the table completed. " << endl;
	
	
	}
	if(myChoice == "c"){
		
		break;
	}
	}while(myChoice != "q");
	
	cout << " Your journey through the mystic lands of this code has ended. Have a good day. " << endl;
		}
	if(myChoice1 == "f"){
	HashTable<float> floatObject;
do{	
	cout << "=============================" << endl;
	cout << "Input your Choice" << endl;
	cout << "i) Add an element to the table" << endl;
	cout << "p) Print out the table " << endl;
	cout << "d) Delete an element from the table." << endl;
	cout << "l) Find an element in the table" << endl;
	cout << "s) Show number of elements in the table " << endl;
	cout << "c) create a new table " << endl;
	cout << "q) Exit" << endl;
	
	getline( cin, myChoice );

	cout << "Your choice was " << myChoice << endl;
	
  	if(myChoice == "i"){
	floatObject.readAndInput();
	cout << " Insertion of an element completed. " << endl;
	
	}
  	if(myChoice == "p"){
	floatObject.printString();
	cout << " Printing of elements completed. " << endl;
	
	}

  	if(myChoice == "d"){
	
	floatObject.DeleteFromTable();
	
	}
	if(myChoice == "l"){
	
	floatObject.showElement();
	cout << " Looking up an element completed. " << endl;
	}

	if(myChoice == "s"){
	floatObject.NumberOfElements();
	cout << " Size of the table completed. " << endl;
	
	
	}
	if(myChoice == "c"){
		break;
		
	}
	}while(myChoice != "q");
	
	cout << " Your journey through the mystic lands of this code has ended. Have a good day. " << endl;
		}
	if(myChoice1 == "d"){
	HashTable<double> dblTable;
do{	
	cout << "=============================" << endl;
	cout << "Input your Choice" << endl;
	cout << "i) Add an element to the table" << endl;
	cout << "p) Print out the table " << endl;
	cout << "d) Delete an element from the table." << endl;
	cout << "l) Find an element in the table" << endl;
	cout << "s) Show number of elements in the table " << endl;
	cout << "c) create a new table " << endl;
	cout << "q) Exit" << endl;
	
	getline( cin, myChoice );

	cout << "Your choice was " << myChoice << endl;
	
  	if(myChoice == "i"){
	dblTable.readAndInput();
	cout << " Insertion of an element completed. " << endl;
	
	}
  	if(myChoice == "p"){
	dblTable.printString();
	cout << " Printing of elements completed. " << endl;
	
	}

  	if(myChoice == "d"){
	
	dblTable.DeleteFromTable();
	
	}
	if(myChoice == "l"){
	
	dblTable.showElement();
	cout << " Looking up an element completed. " << endl;
	}

	if(myChoice == "s"){
	dblTable.NumberOfElements();
	cout << " Size of the table completed. " << endl;
	
	
	}
	if(myChoice == "c"){
		
		break;
	}
	}while(myChoice != "q");
	
	cout << " Your journey through the mystic lands of this code has ended. Have a good day. " << endl;
		}
	if(myChoice1 == "c"){
	HashTable<char> charObject;
	
do{	
	cout << "=============================" << endl;
	cout << "Input your Choice" << endl;
	cout << "i) Add an element to the table" << endl;
	cout << "p) Print out the table " << endl;
	cout << "d) Delete an element from the table." << endl;
	cout << "l) Find an element in the table" << endl;
	cout << "s) Show number of elements in the table " << endl;
	cout << "c) create a new table " << endl;
	cout << "q) Exit" << endl;
	
	getline( cin, myChoice );

	cout << "Your choice was " << myChoice << endl;
	
  	if(myChoice == "i"){
	charObject.readAndInput();
	cout << " Insertion of an element completed. " << endl;
	
	}
  	if(myChoice == "p"){
	charObject.printString();
	cout << " Printing of elements completed. " << endl;
	
	}

  	if(myChoice == "d"){
	
	charObject.DeleteFromTable();
	
	}
	if(myChoice == "l"){
	
	charObject.showElement();
	cout << " Looking up an element completed. " << endl;
	}

	if(myChoice == "s"){
	charObject.NumberOfElements();
	cout << " Size of the table completed. " << endl;
	
	
	}
	if(myChoice == "c"){
		break;
		
	}
	}while(myChoice != "q");
	
	cout << " Your journey through the mystic lands of this code has ended. Have a good day. " << endl;
		}
	

}while(myChoice1 != "x");
}

int main(){

menu();
	
}
	

