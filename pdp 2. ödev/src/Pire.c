#include "Pire.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"

Pire PireBul()
{
	Pire this;
	this = (Pire)malloc(sizeof(struct PIRE));
	this->doubleSuper = BocekBul(); // onemli
	this->yoket = &PireYokEt;		// onemli
	this->toString = &PireToString;
	return this;
}

char *PireToString(const Pire this)
{
	return "P";
}

void PireYokEt(const Pire this)
{
	if (this == NULL)
		return;
	BocekYokEt(this->doubleSuper);
	free(this);
}
