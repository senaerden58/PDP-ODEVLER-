#include "Bitki.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"
Bitki BitkiBul()
{
    Bitki this;
    this=(Bitki)malloc(sizeof(struct BITKI));
    this->super=CanliBul('B'); 
    this->yoket = &BitkiYokEt; 
    this->toString=&BitkiToString;
    return this;
}

char* BitkiToString(const Bitki this) {
    return "B";
}


void BitkiYokEt(const Bitki this) //yok etme fonksyonu
{
    if(this==NULL) return;
    
    this->super->yoket(this->super);
    free(this);
}