#include "yellohuman.h"

#include <iostream>

using std::cout;
using std::endl;

CWhiteHumanFactory::CWhiteHumanFactory(void){

}
CWhiteHumanFactory::CWhiteHumanFactory(void){

}

IHuman *CWhiteHumanFactory::CreateHuman(void){
	return new CWhiteHuman();
}

