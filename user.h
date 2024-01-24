#ifndef USER_H
#define USER_H

#include <string>
#include <set>

class User {
public:
    User();
    User(int id, const std::string& name, int birthYear, int zipCode, const std::set<int>& friends);

    int getId() const;
    std::string getName() const;
    int getYear() const;
    int getZip() const;
    const std::set<int>& getFriends() const;

    void addFriend(int friendId);
    void deleteFriend(int friendId);

private:
    int id;
    std::string name;
    int birthYear;
    int zipCode;
    std::set<int> friends;
};

#endif // USER_H