#include "service.h"

int service::getId() const {
    return id;
}

void service::setId(int id) {
    service::id = id;
}

const string& service::getName() const {
    return name;
}

void service::setName(const string& name) {
    service::name = name;
}

const string& service::getPrice() const {
    return price;
}

void service::setPrice(const string& price) {
    service::price = price;
}

