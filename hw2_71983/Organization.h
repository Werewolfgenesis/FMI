#pragma once
#include "Institution.h"
#include <vector>
#pragma warning(disable:4996)
#include <iostream>

using namespace std;
class Organization : public Institution
{
private:
	vector <Institution*> organization;

	Payer* AssignPayer(std::vector<Institution*>&);
	
public:
	Organization();
	Organization(vector<Institution*> organization, const char* name2);

	void AddInstitution(Institution* instit);

	//----------------------------------inherited functions
	Payer* MainPayer() override;
	bool IsValid() override;
	int GetType() override;
	bool HasMember(Person& p) override;
	size_t GetInstitId() const override	;
};

