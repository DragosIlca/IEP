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
    	
	~User()
	{
		cout << "Object destructed\n";	
	};

	string firstName;
	string lastName;

private:
	string address;

	User(const User& rhs)
	{
		cout << "Object copy constructor\n";	
	};

	User& operator=(const User& rhs)
	{
		cout << "Object copy assignement\n";
	};
};

int main() {
		
	User* user = new User("Sebi", "Haias", "Timisoara");

	cout << user->firstName << "\n" << user->lastName << "\n";		

	return 0;
}
