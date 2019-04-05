
#include <iostream>
#include <set>
#include <unordered_map>
#include <map>

using namespace std;

enum GENDER {
	Male,
	Female
};

class User
{
	std::string name;
	int age;
	int height;
	set<std::string> hobbies;
	map<int, User> friends;
	int gender;
	int id;
public:
	User(std::string name, int age, set<std::string>&hobbies, int id, int gender=Male, int height=170)
	{
		this->name = name;
		this->age = age;
		this->hobbies = hobbies;
		this->id = id;
		this->gender = gender;
		this->height = height;
	}
	std::string getName()
	{
		return name;
	}
	int getAge()
	{
		return age;
	}
	set<std::string>& gethobbies()
	{
		return hobbies;
	}
	int getId()
	{
		return id;
	}
	map<int, User>& getfriends()
	{
		return friends;
	}
	/*fill in*/
};

class SocialNetwork
{
public:
	void addUser(User user)
	{
		//Maintin a map with user id and user object
		serachById.insert({ user.getId(), user });
		//Maintain a mutimap_map for age and id
		serachByAge.insert(std::pair<int, int>(user.getAge(), user.getId()));
		//Maintain a mutimap_map for name and id
		serachByName.insert(std::pair<std::string, int>(user.getName(), user.getId()));

		//Maintain a mutimap_map for hobbies and id
		for (auto it = user.gethobbies().begin(); it != user.gethobbies().end(); it++)
			serachByHobbies.insert(std::pair<string, int>(*it, user.getId()));
	}
	void addFriend(User &user, User &friends)
	{
		auto it = serachById.find(user.getId());
		auto it2 = serachById.find(friends.getId());
		if (it != serachById.end() && it2 != serachById.end())
		{
			auto itFriend = (*it).second.getfriends().find(friends.getId());
			if (itFriend == (*it).second.getfriends().end())
			{
				(*it).second.getfriends().insert(std::pair<int, User>(friends.getId(), friends));
			}
		}
	}
	void deleteUser(User &user)
	{
		//Remove user from all map if it exist in any map/multimap with id
		auto it = serachById.find(user.getId());
		if (it != serachById.end())
		{
			serachById.erase(user.getId());
			auto it = serachByAge.find(user.getAge());
			if (it != serachByAge.end())
			{
				auto it1 = serachByAge.lower_bound((*it).first);
				auto it2 = serachByAge.upper_bound((*it).first);
				while (it1 != it2)
				{
					if ((*it1).second == user.getId())
					{
						it1 = serachByAge.erase(it1);
						break;
					}
					it++;
				}
			}
			auto itN = serachByName.find(user.getName());
			if (itN != serachByName.end())
			{
				auto it1 = serachByName.lower_bound((*itN).first);
				auto it2 = serachByName.upper_bound((*itN).first);
				while (it1 != it2)
				{
					if ((*it1).second == user.getId())
					{
						it1 = serachByName.erase(it1);
						break;
					}
					it1++;
				}
			}
			for (auto its = user.gethobbies().begin(); its != user.gethobbies().end(); its++)
			{
				auto itH = serachByHobbies.find(*its);
				if (itH != serachByHobbies.end())
				{
					auto it1 = serachByHobbies.lower_bound((*itH).first);
					auto it2 = serachByHobbies.upper_bound((*itH).first);
					while (it1 != it2)
					{
						if ((*it1).second == user.getId())
						{
							it1 = serachByHobbies.erase(it1);
							break;
						}
						it1++;
					}
				}				
			}
		}
	}
	vector<int> searchUserByName(std::string name)
	{
		vector<int> userIds;
		auto itN = serachByName.find(name);
		if (itN != serachByName.end())
		{
			auto it1 = serachByName.lower_bound((*itN).first);
			auto it2 = serachByName.upper_bound((*itN).first);
			while (it1 != it2)
			{
				userIds.push_back((*it1).second);
				it1++;
			}
		}
		return userIds;
	}
	std::string searchUserid(int id)
	{
		string name;
		auto it = serachById.find(id);
		if (it != serachById.end())
		{
			name = (*it).second.getName();
		}
		return name;
	}
	vector<int> searchUserByAge(int age)
	{
		vector<int> userIds;
		auto itN = serachByAge.find(age);
		if (itN != serachByAge.end())
		{
			auto it1 = serachByAge.lower_bound((*itN).first);
			auto it2 = serachByAge.upper_bound((*itN).first);
			while (it1 != it2)
			{
				userIds.push_back((*it1).second);
				it1++;
			}
		}
		return userIds;
	}
	vector<int> searchUserByHobbies(std::string hobbies)
	{
		vector<int> userIds;
		auto itN = serachByHobbies.find(hobbies);
		if (itN != serachByHobbies.end())
		{
			auto it1 = serachByHobbies.lower_bound((*itN).first);
			auto it2 = serachByHobbies.upper_bound((*itN).first);
			while (it1 != it2)
			{
				userIds.push_back((*it1).second);
				it1++;
			}
		}
		return userIds;
	}
	vector<int> getFriendsOfUser(User &user)
	{
		vector<int> userIds;
		for (auto it = user.getfriends().begin(); it != user.getfriends().end(); it++)
			userIds.push_back((*it).first);
		return userIds;
	}

private:
	/*fill in*/
	unordered_map<int, User>serachById;
	unordered_multimap<int, int>serachByAge;
	unordered_multimap<std::string, int>serachByName;
	unordered_multimap<std::string, int>serachByHobbies;
};

void displayIDs(vector<int>ids)
{
	cout << endl;
	for (auto it = ids.begin(); it != ids.end(); it++)
		cout << *it << " ";
	cout << endl;
}

int main()
{
	set<std::string>hobbies1{ "tt", "badminton", "movies" };
	set<std::string>hobbies2{ "swimming", "badminton", "drive" };
	set<std::string>hobbies3{ "drive", "book" };
	set<std::string>hobbies4{ "hillClimbing", "scating", "tt" };

	//Initialise Users
	//============================================================
	User yaten("yaten", 35, hobbies1, 100); // "tt", "badminton", "movies"
	User ravi("ravi", 35, hobbies2, 101);   // "swimming", "badminton", "drive"
	User rawat("rawat", 33, hobbies3, 102); // "drive", "book"
	User prasad("prasad", 39, hobbies4, 103); // "tt" "hillClimbing", "scating"
	User ravi_prakash("ravi_prakash", 33, hobbies3, 104); // "drive", "book"
	User deepesh("deepesh", 35, hobbies1, 105);           // "tt", "badminton", "movies"
	//=============================================================

	//Adding Users
	//=========================================================
	SocialNetwork socialNetwork;
	socialNetwork.addUser(yaten);
	socialNetwork.addUser(ravi);
	socialNetwork.addUser(rawat);
	socialNetwork.addUser(prasad);
	socialNetwork.addUser(ravi_prakash);
	socialNetwork.addUser(deepesh);
	//==========================================================

	cout << "Search by Hobbies tt";
	vector<int>ids = socialNetwork.searchUserByHobbies("tt");
	displayIDs(ids);
	cout << "Search by Hobbies book";
	ids = socialNetwork.searchUserByHobbies("book");
	displayIDs(ids);
	cout << "Search by age 35";
	ids = socialNetwork.searchUserByAge(35);
	displayIDs(ids);
	cout << "Search by name yaten";
	ids = socialNetwork.searchUserByName("yaten");
	displayIDs(ids);

	//Deleteing user
	//============================================================
	User deleteUser = prasad;
	int id = deleteUser.getId();
	cout << "Delete user " << deleteUser.getName().c_str() << " with id " << deleteUser.getId() << endl;
	socialNetwork.deleteUser(prasad);
	//===========================================================

	cout << "Search by Hobbies tt";
	ids = socialNetwork.searchUserByHobbies("tt");
	displayIDs(ids);
	cout << "Search by Hobbies book";
	ids = socialNetwork.searchUserByHobbies("book");
	displayIDs(ids);
	cout << "Search by age 35";
	ids = socialNetwork.searchUserByAge(35);
	displayIDs(ids);
	cout << "Search by name " << deleteUser.getName().c_str();
	ids = socialNetwork.searchUserByName(deleteUser.getName());
	displayIDs(ids);

	string name = socialNetwork.searchUserid(id);
	name.empty() ? (cout << id << " Not Found ") : (cout << name.c_str());


	getchar();
	return 0;
}