#ifndef YellowHuman_H
#ifndef YellowHuman_H

#include "ihuman.h"

class CYellowHuman:public IHuman{
public:
	CYellowHuman(void);
	~CYellowHuman(void);
	void Laugh();
	void Cry();
	void Talk();
};


#endif
