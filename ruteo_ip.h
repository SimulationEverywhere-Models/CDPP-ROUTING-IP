#ifndef __ruteo_ip_H
#define __ruteo_ip_H


#include "atomic.h"     // class Atomic

class ruteo_ip : public Atomic
{
public:
        ruteo_ip( const string &name = "ruteo_ip" );                                  //Default constructor
	virtual string className() const ;

protected:
	Model &initFunction();
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
        const Port &in; // Port de entrada de avion
        Port &out1;    // Port de Salida 
        Port &out2;    //  Port de Salida 
        Port &out3;    //  Port de Salida 

        float id; 
        Time Demora;

};      // class ruteo_ip

// ** inline ** // 
inline
string ruteo_ip::className() const
{
        return "ruteo_ip" ;
}


#endif   //__ruteo_ip_H
