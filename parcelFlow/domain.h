#pragma once
#include <exception>
#include <string>
#include <vector>

class DeliveryException : public std::exception
{
private:
    std::string message;
public:
    DeliveryException(const std::string& msg) : message(msg) {}
    const char* what() const noexcept override { return message.c_str(); }

};

class Parcel {
private:
    std::string recipient;
    std::string street;
    int number;
    int x;
    int y;
    bool status;
public:
    Parcel(std::string rec = "", std::string str = "", int num = 0, int x = 0, int y = 0, bool stat = false);

    std::string getRecipient() const;
    std::string getStreet() const;
    int getNumber() const;
    int getX() const;
    int getY() const;
    bool isDelivered() const;

    void deliver();
    std::string toString() const;
};

class Agent {
private:
    std::string name;
    std::vector<std::string> assignedStreets;
    int zoneX;
    int zoneY;
    int radius;
public:
    Agent(std::string name = "", std::vector<std::string> streets = {}, int zX = 0, int zY = 0, int r = 0);

    std::string getName() const;
    std::vector<std::string> getStreets() const;
    int getZoneX() const;
    int getZoneY() const;
    int getRadius() const;

    bool canDeliver(const Parcel& p) const;
};

