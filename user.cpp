#include "user.h"

User::User() : id(0), birthYear(0), zipCode(0) {}

User::User(int id, const std::string& name, int birthYear, int zipCode, const std::set<int>& friends)
    : id(id), name(name), birthYear(birthYear), zipCode(zipCode), friends(friends) {}

int User::getId() const { 
    return id;
}

std::string User::getName() const {
    return name; 
}

int User::getYear() const { 
    return birthYear; 
}

int User::getZip() const { 
    return zipCode; 
}

const std::set<int>& User::getFriends() const { 
    return friends; 
}

void User::addFriend(int friendId) {
    friends.insert(friendId);
}

void User::deleteFriend(int friendId) {
    friends.erase(friendId);
}