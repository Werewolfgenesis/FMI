// hw2_71983.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "Institution.h"
#include "Organization.h"
#include "Group.h"
#include "Payer.h"
#include "Person.h"

vector<Institution*> ClearInstitutions(vector<Institution*>& v)
{
	vector<Institution*> onlyValid;
	for (size_t i = 0; i < v.size(); i++)
	{
		if (v[i]->IsValid())
		{
			onlyValid.push_back(v[i]);
		}
	}
	return onlyValid;
}
Institution* FindMostPopular(vector<Institution*> institutions, vector<Person> people)
{
	int* count = new int[institutions.size()];
	for (size_t i = 0; i < institutions.size(); i++)
	{
		for (size_t j = 0; j < people.size(); j++)
		{
			if (institutions[i]->HasMember(people[j]))
			{
				count[i]++;
			}
		}
	}
	int maxIndex = 0, maxCnt = 0;
	for (size_t i = 0; i < institutions.size(); i++)
	{
		if (count[i] > maxCnt)
		{
			maxIndex = i;
			maxCnt = count[i];
		}
	}
	delete[] count;
	return institutions[maxIndex];
}
bool BulstratMemberRule(int personId, int id)
{
	return id / 10000 == personId / 10000;
}
bool AllianzMemberRule(int personId, int id)
{
	return id == personId;
}
int main()
{
	Payer p1("Bulstrad", BulstratMemberRule, 24);
	Payer p2("Allianz",AllianzMemberRule, 22);


	Group g1("Group1");
	Group g2("Group2", p1);
	Group g3("Group3");
	Group g4 ("Group4",p2);
	vector<Institution*> institution = { &g1, &g2 };

	cout << "Group specs:" << endl;
	cout << "Is valid: " << boolalpha << g1.IsValid() << endl; //false - because there is no associated payer
	cout << "Main payer: " << g1.MainPayer()->GetName() << endl; //"No payer"
	cout << "Is valid: " << boolalpha << g2.IsValid() << endl; //true - because payer is p1
	cout << "Main payer: " << g2.MainPayer()->GetName() << endl; //"Bulstrad"
	cout << "Is valid: " << boolalpha << g3.IsValid() << endl; //false - because there is no associated payer
	cout << "Main payer: " << g3.MainPayer()->GetName() << endl; //"No payer"
	cout << "Is valid: " << boolalpha << g4.IsValid() << endl; //true - because payer is p2
	cout << "Main payer: " << g4.MainPayer()->GetName() << endl; //"Allianz"
	cout << endl;

	Organization o2(institution, "another address");
	Organization o1(institution, "no address");

	cout << "Organization specs:" << endl;

	cout << "Is valid: " << boolalpha << o1.IsValid() << endl; //true - because payer is p1
	cout << "Main payer: " << o1.MainPayer()->GetName() << endl; //"Bulstrad"
	institution.clear();
	cout << "Is valid: " << boolalpha << o2.IsValid() << endl; //false - because there is no associated payer
	cout << "Main payer: " << o2.MainPayer()->GetName() << endl; //"No payer"

	Person person1("Ivan Ivanov", 24512);
	Person person2("Traicho Kosev", 24516);
	Person person3("Vanko Edno", 24520);

	cout << "Person specs:" << endl;

	cout << "Has member: " << boolalpha << g2.HasMember(person1) << endl; //True
	cout << "Has member: " << boolalpha << g2.HasMember(person2) << endl; //True
	cout << "Has member: " << boolalpha << g2.HasMember(person3) << endl; //True

	cout << "Has member: " << boolalpha << g4.HasMember(person1) << endl; //False
	cout << "Has member: " << boolalpha << g4.HasMember(person2) << endl; //False
	cout << "Has member: " << boolalpha << g4.HasMember(person3) << endl; //False

	vector<Institution*> organization = { &g2,&g4 };
	vector<Person> people = { person1,person2,person3 };
	vector<Institution*> clearInstitution = { &o1,&o2,&g2,&g4 };

	cout << "Most popular organization: " << FindMostPopular(organization, people)->GetId() << endl; //2 because g2 has most person
	cout << ClearInstitutions(clearInstitution).size() << endl;
}
