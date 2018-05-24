#ifndef YellowHuman_H
#ifndef YellowHuman_H

#include "ihuman.h"

class CYellowHumanFactory:public IHumanFactory{
public:
	CYellowHumanFactory(void);
	~CYellowHumanFactory(void);
	virtual IHuman *CreateHuman(void);
};


#endif
