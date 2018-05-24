#ifndef SINGLETON_H
#define SINGLETON_H

class Singleton{
public:
	Singleton *GetInstance();
private:
	static Singleton *m_pSingleton;
};



#endif

