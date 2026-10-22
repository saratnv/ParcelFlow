#pragma once
#include <vector>
#include "domain.h"
class Repository
{
private:
	std::vector<Agent> agents;
	std::vector<Parcel> parcels;
	std::string agentsFile;
	std::string parcelsFile;

	void loadAgents();
	void loadParcels();
	void saveParcels();

public:
	Repository(const std::string& cFile, const std::string& pFile);

	std::vector<Agent> getAgents() const;
	std::vector<Parcel> getParcels() const;

	void addParcel(const Parcel& p);
	void updateParcel(const Parcel& updatedP);
};

