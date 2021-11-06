#include "Payer.h"

Payer::Payer()
{
	this->SetName("Jojo");
	this->payerId = 0;
	this->PayerMemberRule = nullptr;
}

Payer::Payer(const char* name, std::function <bool(const int personId, const int groupId)> PayerMemberRule, int payerId)
{
	this->SetName(name);
	this->PayerMemberRule = PayerMemberRule;
	this->payerId = payerId;
}

Payer& Payer::operator=(const Payer& other)
{
	if (this != &other)
	{
		this->SetName(other.name);
		this->payerId = other.payerId;
	}
	return *this;
}

void Payer::SetName(const char* name)
{
	if (name != nullptr)
	{
		delete[] this->name;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
}

std::function<bool(const int personId, const int groupId)> Payer::GetPayerMemberRule()
{
	return this->PayerMemberRule;
}

char* Payer::GetName() const
{
	if (this != nullptr)
	{
		return this->name;
	}
	else
	{
		char* answer = new char[30];
		strcpy(answer, "No payer!");
		return answer;
	}
}

int Payer::GetId() const
{
	if (this != nullptr)
	{
		return this->payerId;
	}
	else
	{
		return -1;
	}
}
