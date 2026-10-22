#include "controller.h"

Controller::Controller(Repository& r) : repo(r) {}

std::vector<Agent> Controller::getAgents() const { return repo.getAgents(); }
std::vector<Parcel> Controller::getParcels() const { return repo.getParcels(); }

void Controller::addPackage(const std::string& recipient, const std::string& street, int number, int x, int y) {
    if (recipient.empty() || street.empty()) {
        throw DeliveryException("Please enter recipient and street, they cannot be empty.");
    }

    Parcel newPackage(recipient, street, number, x, y, false);
    repo.addParcel(newPackage);
    notifyObservers();
}

void Controller::deliverPackage(const std::string& recipient, const std::string& street) {
    auto packages = repo.getParcels();
    Parcel target;
    bool found = false;

    for (const auto& p : packages) {
        if (p.getRecipient() == recipient && p.getStreet() == street) {
            target = p;
            found = true;
            break;
        }
    }

    if (!found) return;

    target.deliver();
    repo.updateParcel(target);
    notifyObservers();
}