#pragma once
#include <cstring>
#include "Person.h"
#include <functional>
#pragma warning(disable:4996)
class Payer
{
private:
	char * name;
	std::function <bool(const int personId, const int groupId)> PayerMemberRule;
	int payerId;
public:
	Payer();
	Payer(const char* name, std::function <bool(const int personId, const int groupId)> PayerMemberRule, int payerId);
	Payer& operator=(const Payer& other);

	void SetName(const char* name);
	std::function <bool(const int personId, const int groupId)> GetPayerMemberRule();
	char* GetName() const;
	int GetId() const;

};

