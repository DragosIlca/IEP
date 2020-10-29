#include <iostream>
#include <string>

using namespace std;

class User { 

public:
	User(const string& firstName, const string& lastName, const string& address, const string& gender)
	: firstName(firstName),
	lastName(lastName),
	address(address),
	gender(gender)
	{};
    	
	~User() {
		cout << "Object destructed\n";	
	};

	User& operator=(const User& rhs) {
		cout << "Object copy assignement\n";
		firstName = rhs.firstName;
		lastName = rhs.lastName;
		address = rhs.address;
		gender = rhs.gender;
		return *this;
	};


	void display() {
		cout << firstName << " " << lastName << " " << address << " " << gender <<"\n";		
	}

private:
	string firstName;
	string lastName;
	string address;
	string gender;

	User(const User& rhs) {
		cout << "Object copy constructor\n";	
		firstName = rhs.firstName;
		lastName = rhs.lastName;
		address = rhs.address;
		gender = rhs.gender;
	};
};

int main() {
		
	User* sebi = new User("Sebi", "Haias", "Timisoara", "male");
	User* sebi2 = new User("Sebi2", "Haias2", "Timisoara2", "male");
	// User andrei = User("Andrei", "Micle", "Bihor", "male"); not allowed due to private copy constructor

	sebi->display();
	sebi2->display();

	*sebi2 = *sebi;

	sebi2->display();

	delete sebi;
	delete sebi2;

	return 0;
}
