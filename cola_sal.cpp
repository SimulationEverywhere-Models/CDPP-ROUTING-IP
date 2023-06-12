
/** include files **/
#include <string>

/** my include files **/
#include "cola_sal.h"      // class cola_sal
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: cola_sal
* Description: 
********************************************************************/
cola_sal::cola_sal( const string &name )
: Atomic( name )
, in( this->addInputPort( "in" ) )
, out( this->addOutputPort( "out" ) )
, preparationTime( 0, 0, 0, 0 )
{
}



/*******************************************************************
* Function Name: initFunction

* Precondition: El tiempo del proximo evento interno es Infinito
********************************************************************/
Model &cola_sal::initFunction()
{
       
        elements.erase( elements.begin(), elements.end() ) ;
	return *this ;
}


/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model &cola_sal::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == in )
	{
                elements.push_back( msg.value() ) ;
                                this->holdIn( active, preparationTime);
        }


	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description:
********************************************************************/
Model &cola_sal::internalFunction( const InternalMessage & )
{
        this->passivate();
	return *this ;
}


/*******************************************************************
* Function Name: outputFunction
* Description:
********************************************************************/
Model &cola_sal::outputFunction( const InternalMessage &msg )
{

                if( elements.size() > 0 )
		  { this->sendOutput( msg.time(), out, elements.front() ) ;
			elements.pop_front() ;
       
		  }
        return *this ;
}
