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

<<<<<<< HEAD
User::~User()
{
=======
User::~User() {
>>>>>>> 464cff039c839c61fb158e6504c12eb0f0184ee9
	cout << "Destructing User\n";
}

class Admin : public User
{
public:
<<<<<<< HEAD
	Admin(const string &firstName, const string &lastName, const string &address, const string &gender, const int somer)
		: User(firstName, lastName, address, gender),
		  somer(somer)
=======
	Admin(const string &firstName, const string &lastName, const string &address, const string &gender)
		: User(firstName, lastName, address, gender)
>>>>>>> 464cff039c839c61fb158e6504c12eb0f0184ee9
	{
		cout << "Constructing Admin\n";
	}

	~Admin()
	{
		cout << "Destructing Admin\n";
	};
<<<<<<< HEAD

	Admin(const Admin &t) : User(t), somer(t.somer){};

	Admin &operator=(const Admin &t)
	{
		User::operator=(t);
		somer = t.somer;
		return *this;
	}

	void display()
	{
		cout << firstName << " " << lastName << " " << address << " " << gender << " " << somer << "\n";
	}

private:
	// 0 sau 1
	int somer;
};

class Group
{
public:
	Group(Admin *admin) : admin(admin) { cout << "Group constructor\n"; };

	Group &operator=(const Group &gr)
	{
		cout << "Operator called\n";

		Admin *aux = admin;
		delete aux;
		admin = new Admin(*gr.admin);

		return *this;
	}

	~Group()
	{
		cout << "Deleting group\n";
	}

private:
	Admin *admin;
};

int main()
{
	Admin *admin = new Admin("admin", "admin", "zeu", "zeu", 0);
	User *user = admin;

	Admin *admin2 = new Admin("admin2", "admin2", "zeu2", "zeu2", 0);

	Group *group1 = new Group(admin);
	Group *group2 = new Group(admin2);

	Admin *admin3 = new Admin(*admin);

	admin->display();
	admin3->display();

	*group1 = *group1;
	*group2 = *group2;

	delete group1;
	delete group2;

=======
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

>>>>>>> 464cff039c839c61fb158e6504c12eb0f0184ee9
	delete user;
	delete admin2;

	return 0;
}