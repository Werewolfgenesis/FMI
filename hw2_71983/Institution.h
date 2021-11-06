#pragma once
#include "Payer.h"
#pragma warning(disable:4996)

static int createdInstits = 0;

class Institution
{
protected:
	long int institId;
	char* institName;
	Payer* institPayer;

public:
	int GetId() const;

	//virtual methods to be implemented in the child classes
	virtual bool HasMember(Person& p) = 0;
	virtual Payer* MainPayer() = 0;
	virtual bool IsValid() = 0;
	virtual int GetType() = 0;
	virtual size_t GetInstitId() const = 0;
};

