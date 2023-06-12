
#ifndef __cola_sal_H
#define __cola_sal_H

#include <list>

#include "atomic.h"     // class Atomic

class cola_sal : public Atomic
{
public:
        cola_sal( const string &name = "cola_sal" );                                  //Default constructor

	virtual string className() const ;
protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	const Port &in;
      	Port &out;
	Time preparationTime;
	typedef list<Value> ElementList ;
	ElementList elements ;
        
      
      
};      // class cola_sal

// ** inline ** // 
inline
string cola_sal::className() const
{
        return "cola_sal" ;
}


#endif   //__cola_sal_H
