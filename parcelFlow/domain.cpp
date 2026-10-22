#include "domain.h"
#include <cmath>
#include <algorithm>

Parcel::Parcel(std::string rec, std::string str, int num, int x, int y, bool stat)
    : recipient(rec), street(str), number(num), x(x), y(y), status(stat) {
}

std::string Parcel::getRecipient() const { return recipient; }
std::string Parcel::getStreet() const { return street; }
int Parcel::getNumber() const { return number; }
int Parcel::getX() const { return x; }
int Parcel::getY() const { return y; }
bool Parcel::isDelivered() const { return status; }

void Parcel::deliver() { status = true; }

std::string Parcel::toString() const {
    return recipient + "," + street + "," + std::to_string(number) + "," + std::to_string(x) + "," + std::to_string(y) + "," + (status ? "1" : "0");
}

Agent::Agent(std::string name, std::vector<std::string> streets, int zX, int zY, int r)
    : name(name), assignedStreets(streets), zoneX(zX), zoneY(zY), radius(r) {
}

std::string Agent::getName() const { return name; }
std::vector<std::string> Agent::getStreets() const { return assignedStreets; }
int Agent::getZoneX() const { return zoneX; }
int Agent::getZoneY() const { return zoneY; }
int Agent::getRadius() const { return radius; }

bool Agent::canDeliver(const Parcel& p) const {
    if (std::find(assignedStreets.begin(), assignedStreets.end(), p.getStreet()) != assignedStreets.end()) {
        return true;
    }

    int dx = p.getX() - zoneX;
    int dy = p.getY() - zoneY;
    double distanceSquared = (dx * dx) + (dy * dy);

    return distanceSquared <= (radius * radius);
}

