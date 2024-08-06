#include "Sinek.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"

Sinek SinekBul()
{
	Sinek this;
	this = (Sinek)malloc(sizeof(struct SINEK));
	this->doubleSuper = BocekBul();
	this->toString = &SinekToString;
	this->yoket = &SinekYokEt;
	return this;
}

char *SinekToString(const Sinek this)
{
	return "S";
}

void SinekYokEt(const Sinek this)
{
	if (this == NULL)
		return;
	BocekYokEt(this->doubleSuper);
	free(this);
}
