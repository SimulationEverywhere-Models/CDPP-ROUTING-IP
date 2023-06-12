/** include files **/
#include <string>

/** my include files **/
#include "ruteo_ip.h"      // class ruteo_ip
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: ruteo_ip
* Description: 
********************************************************************/

ruteo_ip::ruteo_ip( const string &name )
: Atomic( name )
, in( this->addInputPort( "in" ) )
, out1( this->addOutputPort( "out1" ) )
, out2( this->addOutputPort( "out2" ) )
, out3( this->addOutputPort( "out3" ) )

{
}



/*******************************************************************
* Function Name: initFunction
********************************************************************/
Model &ruteo_ip::initFunction()
{
           Demora = "00:00:00:10" ;
           return *this ;
}


/*******************************************************************
* Function Name: externalFunction
* Description:
********************************************************************/
Model &ruteo_ip::externalFunction( const ExternalMessage &msg )
{
                if( msg.port() == in )
	{

                                id = msg.value()  ;

                                this->holdIn( active, Demora );
	}


	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description:
********************************************************************/
Model &ruteo_ip::internalFunction( const InternalMessage & )
{
	this->passivate();
        return *this ;
}


/*******************************************************************
* Function Name: outputFunction
* Description:
********************************************************************/
Model &ruteo_ip::outputFunction( const InternalMessage &msg )

{
	  if (id == 1)
		this->sendOutput( msg.time(), out1 , id);

	  if (id == 2)
		this->sendOutput( msg.time(), out2 , id) ;

	  if (id == 3)
		this->sendOutput( msg.time(), out3 , id) ;

		return *this ;

}
