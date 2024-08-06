#include "Bocek.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"

Bocek BocekBul()
{
	Bocek this;
	this=(Bocek)malloc(sizeof(struct BOCEK));
	this->super=CanliBul('C');
	this->toString = &BocekToString; //onemli 
	this->yoket=&BocekYokEt;  //onemli

	return this;
}
char* BocekToString(const Bocek this) {
    return "C";
}

void BocekYokEt(const Bocek this){
	if(this==NULL) return;
    this->super->yoket(this->super); 
	free(this);
}

