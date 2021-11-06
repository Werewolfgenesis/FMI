#include "Group.h"

int Group::AssignValue(const Payer& payer, int nrInstits)
{
	return payer.GetId() * 1000 + nrInstits;
}

Group::Group()
{
	this->SetId(createdInstits);
	strcpy(institName, "NO NAME");
	institPayer = nullptr;
	createdInstits += 1;
}

Group::Group(const char* name)
{
	delete[]institName;
	institName = new char[strlen(name) + 1];
	strcpy(institName,name);

	this->id = createdInstits;
	institId = createdInstits;
	createdInstits+=1;
	institPayer = nullptr;
}


Group& Group::operator=(Group& other)
{
	if (this != &other)
	{
		this->SetId(other.id);
	}
	return *this;
}

Group::Group(const char* name, Payer& payer)
{
	delete[] this->institName;
	this->institName = new char[strlen(name) + 1];
	strcpy(this->institName, name);
	institPayer = &payer;

	this->id = payer.GetId() * 1000 + createdInstits;
	institId = createdInstits;
	createdInstits++;
}

void Group::SetId(int id)
{
	this->id = id;
}

int Group::GetType()
{
	return 1;
}

bool Group::IsValid()
{
	return this->MainPayer() != nullptr;
}

Payer* Group::MainPayer()
{
	return institPayer;
}
size_t Group::GetInstitId() const
{
	return institId;
}
bool Group::HasMember(Person& person)
{
	if (person.GetId() == 0)
	{
		return 0;
	}
	std::function <bool(const int personId, const int groupId)> func = institPayer->GetPayerMemberRule();
	return func(person.GetId(), this->id);
}

