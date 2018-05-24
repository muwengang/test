#include "yellohuman.h"

#include <iostream>

using std::cout;
using std::endl;

CYellowHumanFactory::CYellowHumanFactory(void){

}
CYellowHumanFactory::CYellowHumanFactory(void){

}

IHuman *CYellowHumanFactory::CreateHuman(void){
	return new CyewlloHuman();
}

