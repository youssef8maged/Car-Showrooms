#include "Car.h"
int Car::getId() const {
    return id;
}

void Car::setId(int id) {
    Car::id = id;
}

const string& Car::getMake() const {
    return make;
}

void Car::setMake(const string& make) {
    Car::make = make;
}

const string& Car::getModel() const {
    return model;
}

void Car::setModel(const string& model) {
    Car::model = model;
}

int Car::getYear() const {
    return year;
}

void Car::setYear(int year) {
    Car::year = year;
}

int Car::getPrice() const {
    return price;
}

void Car::setPrice(int price) {
    Car::price = price;
}

const string& Car::getInstallment() const {
    return installment;
}

void Car::setInstallment(const string& installment) {
    Car::installment = installment;
}

