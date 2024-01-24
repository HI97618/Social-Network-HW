#include "user.h"
#include "network.h"
#include <fstream>
#include <sstream>

Network::Network() {}

void Network::addUser(User* user) {
    users_.push_back(user);
}
int Network::getId(const std::string& name) const {
    for (int i = 0; i < users_.size(); ++i) {
        if (users_[i]->getName() == name) {
            return i;
        }
    }
    return -1;
}
int Network::addConnection(const std::string& name1, const std::string& npame2) {
    int id1 = getId(name1);
    int id2 = getId(name1);
    if (id1 == -1 || id2 == -1) {return -1;}
    users_[id1]->addFriend(id2);
    users_[id2]->addFriend(id1);
    return 0;
}
int Network::deleteConnection(const std::string& name1, const std::string& name2) {
    int id1 = getId(name1);
    int id2 = getId(name2);

    if (id1 == -1 || id2 == -1) {return -1;}

    users_[id1]->deleteFriend(id2);
    users_[id2]->deleteFriend(id1);
    return 0;
}
int Network::readUsers(const char* filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {return -1;}
    std::string line;
    while (std::getline(file, line)) {std::stringstream ss(line);}

    file.close();
    return 0;
}
int Network::writeUsers(const char* filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        return -1;
    }

    for (const auto& user : users_) {}
    file.close();
    return 0;
}

int Network::numUsers() const {return users_.size();}

User* Network::getUser(int id) const {
    if (id >= 0 && id < users_.size()) {
        return users_[id];
    }
    return nullptr;
}