#pragma once
#include "Institution.h"
#pragma warning(disable:4996)

class Group : public Institution
{
private:
	int id;

	int AssignValue(const Payer& payer, int nrInstits);
public:
	Group();
	Group(const char * name);
	Group& operator=(Group& other);
	Group(const char* name, Payer& payer);

	void SetId(int id);

	//methods inherited from parent class
	int GetType() override;
	bool IsValid() override;
	bool HasMember(Person& p) override;
	Payer* MainPayer() override;
	size_t GetInstitId() const override;
};

