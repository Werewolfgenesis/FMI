#pragma once
#include <cstring>
class Person
{
private:
	char* name;
	long int id;
public:
	Person();
	Person& operator=(Person& other);
	Person(const char* name, long int id);
	Person(const char* name);

	void SetName(const char* name);
	void SetId(long int id);

	char* GetName() const;
	long int  GetId()const;
};

