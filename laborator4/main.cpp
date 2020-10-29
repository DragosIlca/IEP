#include <iostream>
#include <string>

using namespace std;

class User { 

public:
	User(const string& firstName, const string& lastName, const string& address)
	: firstName(firstName),
	lastName(lastName),
	address(address)
	{};
    	
	~User() {
		cout << "Object destructed\n";	
	};

	User& operator=(const User& rhs) {
		cout << "Object copy assignement\n";
		firstName = rhs.firstName;
		lastName = rhs.lastName;
		address = rhs.address;
		return *this;
	};


	void display() {
		cout << firstName << " " << lastName << " " << address << "\n";		
	}

private:
	string firstName;
	string lastName;
	string address;

	User(const User& rhs) {
		cout << "Object copy constructor\n";	
		firstName = rhs.firstName;
		lastName = rhs.lastName;
		address = rhs.address;
	};
};

int main() {
		
	User* sebi = new User("Sebi", "Haias", "Timisoara");
	User* sebi2 = new User("Sebi2", "Haias2", "Timisoara2");
	// User sebi3 = User("Sebi3", "Haias3", "Timisoara3"); not allowed due to private copy constructor

	sebi->display();
	sebi2->display();

	*sebi2 = *sebi;

	sebi2->display();

	delete sebi;
	delete sebi2;

	return 0;
}
