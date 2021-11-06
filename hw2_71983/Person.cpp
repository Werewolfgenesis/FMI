#include "Person.h"
#pragma warning (disable: 4996)

Person::Person()
{
	this->SetName("Mojo");
	this->SetId(0);
}

Person& Person::operator=(Person& other)
{
	if (this != &other)
	{
		this->SetName(other.name);
		this->SetId(other.id);
	}
	return *this;
}

Person::Person(const char* name, long int id)
{
	this->name = new char[strlen(name) + 1];
	this->SetName(name);
	this->SetId(id);
}

Person::Person(const char* name)
{
	this->SetName(name);
}

void Person::SetName(const char* name)
{
	if (name != nullptr)
	{
		delete[] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
}

char* Person::GetName() const
{
	return this->name;
}

void Person::SetId(long int id)
{
	this->id = id;
}

long int Person::GetId() const
{
	return this->id;	
}
