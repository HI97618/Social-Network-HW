#ifndef NETWORK_H
#define NETWORK_H

#include "user.h"
#include <vector>
#include <string>

class Network {
public:
    Network();

    void addUser(User* user);
    int addConnection(const std::string& name1, const std::string& name2);
    int deleteConnection(const std::string& name1, const std::string& name2);
    int getId(const std::string& name) const;
    int readUsers(const char* filename);
    int writeUsers(const char* filename) const;
    int numUsers() const;
    User* getUser(int id) const;
    int writeUser(const std::string& userName, const std::string& filePath);
    int shortestPath(int from, int to);
    int distanceUser(int from, int& to, int distance);
    int writeUser2(const std::string& userName, const std::string& filePath);
private:
    std::vector<User*> users_;
    
};

#endif // NETWORK_H