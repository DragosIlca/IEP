#include <iostream>
#include <string>

using namespace std;

class User
{

public:
	User(const string &firstName, const string &lastName, const string &address, const string &gender)
		: firstName(firstName),
		  lastName(lastName),
		  address(address),
		  gender(gender)
	{
		cout << "Constructing User \n";
	};

	virtual ~User() = 0;

	User &operator=(const User &rhs)
	{
		cout << "Object copy assignement\n";
		firstName = rhs.firstName;
		lastName = rhs.lastName;
		address = rhs.address;
		gender = rhs.gender;
		return *this;
	};

	void display()
	{
		cout << firstName << " " << lastName << " " << address << " " << gender << "\n";
	}

protected:
	string firstName;
	string lastName;
	string address;
	string gender;

	User(const User &rhs)
	{
		cout << "Object copy constructor\n";
		firstName = rhs.firstName;
		lastName = rhs.lastName;
		address = rhs.address;
		gender = rhs.gender;
	};
};

User::~User() {
	cout << "Destructing User\n";
}

class Admin : public User
{
public:
	Admin(const string &firstName, const string &lastName, const string &address, const string &gender)
		: User(firstName, lastName, address, gender)
	{
		cout << "Constructing Admin\n";
	}

	~Admin()
	{
		cout << "Destructing Admin\n";
	};
};

class Group {
public:
	Group(Admin* admin) : admin(admin) {cout << "Group constructor\n";};

	Group& operator=(const Group& gr) {
		cout << "Operator called\n";

		Admin *aux = admin;
		delete aux;
		admin = new Admin(*gr.admin);

		return *this;
	}

	~Group() {
		cout << "Deleting group\n";
	}
	
private:
	Admin *admin;
};

int main()
{
	Admin *admin = new Admin("admin", "admin", "zeu", "zeu");
	User *user = admin;
	
	Admin *admin2 = new Admin("admin2", "admin2", "zeu2", "zeu2");

	Group *group1 = new Group(admin); 
	Group *group2 = new Group(admin2);
	
	*group1=*group1;
	*group2=*group2;

	delete group1;
	delete group2;

	delete user;
	delete admin2;

	return 0;
}
