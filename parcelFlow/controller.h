#pragma once
#include "repository.h"
#include "observer.h"
class Controller : public Subject {
private:
	Repository& repo;
public:
	Controller(Repository& r);
	std::vector<Agent> getAgents() const;
	std::vector<Parcel> getParcels() const;

	void addPackage(const std::string& recipient, const std::string& street, int number, int x, int y);
	void deliverPackage(const std::string& recipient, const std::string& street);
};

