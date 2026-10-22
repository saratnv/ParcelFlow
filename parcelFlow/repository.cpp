#include "repository.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

Repository::Repository(const std::string& cFile, const std::string& pFile)
    : agentsFile(cFile), parcelsFile(pFile) {
    loadAgents();
    loadParcels();
}

void Repository::loadAgents() {
    std::ifstream file(agentsFile);
    if (!file.is_open()) throw std::runtime_error("Agents error for file "+agentsFile);

    std::string line, name, streetsStr, xStr, yStr, rStr, streetToken;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::getline(ss, name, ',');
        std::getline(ss, streetsStr, ',');
        std::getline(ss, xStr, ',');
        std::getline(ss, yStr, ',');
        std::getline(ss, rStr, ',');

        if (!name.empty()) {
            std::vector<std::string> streets;
            std::stringstream streetStream(streetsStr);
            while (std::getline(streetStream, streetToken, '|')) {
                streets.push_back(streetToken);
            }

            agents.push_back(Agent(name, streets, std::stoi(xStr), std::stoi(yStr), std::stoi(rStr)));
        }
    }
}

void Repository::loadParcels() {
    std::ifstream file(parcelsFile);
    if (!file.is_open()) throw std::runtime_error("Cannot find parcels at their file");

    std::string line, rec, str, num, xStr, yStr, statStr;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::getline(ss, rec, ',');
        std::getline(ss, str, ',');
        std::getline(ss, num, ',');
        std::getline(ss, xStr, ',');
        std::getline(ss, yStr, ',');
        std::getline(ss, statStr, ',');

        if (!rec.empty()) {
            bool status = (statStr == "1");
            parcels.push_back(Parcel(rec, str, std::stoi(num), std::stoi(xStr), std::stoi(yStr), status));
        }
    }
}


void Repository::saveParcels() {
    std::ofstream file(parcelsFile);
    for (const auto& p : parcels) {
        file << p.toString() << "\n";
    }
}

std::vector<Agent> Repository::getAgents() const { return agents; }
std::vector<Parcel> Repository::getParcels() const { return parcels; }

void Repository::addParcel(const Parcel& p) {
    parcels.push_back(p);
    saveParcels();
}

void Repository::updateParcel(const Parcel& updatedP) {
    for (auto& p : parcels) {
        if (p.getRecipient() == updatedP.getRecipient() && p.getStreet() == updatedP.getStreet()) {
            p = updatedP;
            break;
        }
    }
    saveParcels();
}