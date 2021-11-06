#include "Organization.h"

Payer* Organization::AssignPayer(std::vector<Institution*>& organization)
{
	vector<Payer*> payers;
	int maxIndex = 0, maxCnt = 0;

	if (organization.empty() == true)
	{
		return nullptr;
	}
	for (size_t i = 0; i < organization.size(); i++)
	{
		if (organization[i]->GetType() == 1 && organization[i]->IsValid() == true)
		{
			payers.push_back(organization[i]->MainPayer());
		}
	}

	int* cnt = new int[payers.size()];

	for (size_t i = 0; i < payers.size(); i++)
	{
		cnt[i] = 0;
	}

	for (size_t i = 0; i < payers.size(); i++)
	{
		for (size_t j = 0; j < payers.size(); j++)
		{
			if (payers[i] == payers[j])
			{
				cnt[i]++;
			}
		}
	}

	for (size_t i = 0; i < payers.size(); i++)
	{
		if (cnt[i] > maxCnt)
		{
			maxIndex = i;
			maxCnt = cnt[i];
		}
	}
	delete[] cnt;
	return payers[maxIndex];
}

Organization::Organization()
{
	delete[]institName;
	institName = new char[20];
	strcpy(institName, "NO NAME");
	institId = createdInstits;
	createdInstits++;
	institPayer = nullptr;
}

Organization::Organization(vector<Institution*> organization, const char* name2)
{
	
	delete[]institName;

	institName = new char[strlen(name2) + 1];
	strcpy(institName, name2);
	

	this->organization = organization;
	institId = createdInstits;
	createdInstits++;
	institPayer = AssignPayer(organization);
}

void Organization::AddInstitution(Institution* instit)
{
	if (instit->IsValid() == true)
	{
		this->organization.push_back(instit);
		institPayer = AssignPayer(organization);
		return;
	}
	else if (instit->GetType() == 2 && institPayer == instit->MainPayer())
	{
		organization.push_back(instit);
		return;
	}
	else
	{
		cout << "You recently tried to add an invalid institution. Please try again!" << endl;
	}
}

Payer* Organization::MainPayer()
{
	return institPayer;
}

bool Organization::IsValid()
{
	for (size_t i = 0; i < organization.size(); i++)
	{
		if (organization[i]->GetType() == 1)
		{
			return true;
		}
	}
	return false;
}

int Organization::GetType()
{
	return 2; //could be anything we want
}

bool Organization::HasMember(Person& person)
{
	if (person.GetId() == 0)
	{
		return false;
	}
	for (size_t i = 0; i < this-> organization.size(); i++)
	{
		if (organization[i]->HasMember(person) == true)
		{
			return true;
		}
	}
	return false;
}

size_t Organization::GetInstitId() const
{
	return institId;
}


	
