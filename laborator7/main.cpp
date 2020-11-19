#include <iostream>
#include <string>
#include <memory>
#include <string.h>

using namespace std;

// item 18
struct NrOfPages {
	explicit NrOfPages(int nrOfPages)
	: val(nrOfPages) {}
	int val;
};

// item 18
struct NrOfChapters {
	explicit NrOfChapters(int nrOfChapters)
	: val(nrOfChapters) {}
	int val;
};

// item 18
class Book {
public:
	Book(const NrOfPages& nrOfPages, const NrOfChapters& nrOfChapters)
		: nrOfPages(nrOfPages),
		  nrOfChapters(nrOfChapters)
	{};

private:
	NrOfChapters nrOfChapters;
	NrOfPages nrOfPages;
};


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
	};

	string getAddress() const {
		return address;
	};

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

User::~User()
{
	cout << "Destructing User\n";
}

class Admin : public User
{
public:
	Admin(const string &firstName, const string &lastName, const string &address, const string &gender, const int somer)
		: User(firstName, lastName, address, gender),
		  somer(somer)
	{
		cout << "Constructing Admin\n";
	}

	~Admin()
	{
		cout << "Destructing Admin\n";
	};

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

	Admin* getAdmin() {
		return admin;
	}

private:
	Admin *admin;
};

void provideAccess(Admin *admin)
{
	admin->display();
};


int validateUser(const User& u) {
	return strcmp(u.getAddress().c_str(), "") != 0;
}

int main()
{
	std::auto_ptr<Admin> admin(new Admin("Dragos", "Ilca", "TM", "male", 0));

	std::shared_ptr<Admin> admin1(new Admin("Sebastian", "Haias", "TM", "male", 0));
	std::shared_ptr<Admin> admin2(admin1);
	admin1 = admin2;
	
	// item 15
	provideAccess(admin.get());

	// item 18
	Book *book = new Book(NrOfPages(100), NrOfChapters(10));

	cout << validateUser(*admin.get()) << "\n";

	admin1->display();
	admin2->display();

	return 0;
}