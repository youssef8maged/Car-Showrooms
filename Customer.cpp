

#include "Customer.h"

const string& Customer::getUsername() const {
    return username;
}

void Customer::setUsername(const string& username) {
    Customer::username = username;
}

const string& Customer::getPassword() const {
    return password;
}

void Customer::setPassword(const string& password) {
    Customer::password = password;
}

int Customer::getId() const {
    return id;
}

void Customer::setId(int id) {
    Customer::id = id;
}

