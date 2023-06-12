/*******************************************************************
*
*  DESCRIPTION: Atomic Model Queue
*
*  AUTHOR: Amir Barylko & Jorge Beyoglonian 
*
*  EMAIL: mailto://amir@dc.uba.ar
*         mailto://jbeyoglo@dc.uba.ar
*
*  DATE: 27/6/1998
*
*******************************************************************/

/** include files **/
#include <string>

/** my include files **/
#include "queue.h"      // class Queue
#include "message.h"    // class ExternalMessage, InternalMessage
#include "mainsimu.h"   // MainSimulator::Instance().getParameter( ... )

/** public functions **/

/*******************************************************************
* Function Name: Queue
* Description: 
********************************************************************/
Queue::Queue( const string &name )
: Atomic( name )
, in( this->addInputPort( "in" ) )
, stop( this->addInputPort( "stop" ) )
, done( this->addInputPort( "done" ) )
, out( this->addOutputPort( "out" ) )
, preparationTime( 0, 0, 10, 0 )
{
	string time( MainSimulator::Instance().getParameter( this->description(), "preparation" ) ) ;

	if( time != "" )
		preparationTime = time ;
}



/*******************************************************************
* Function Name: initFunction
* Description: Resetea la lista
* Precondition: El tiempo del proximo evento interno es Infinito
********************************************************************/
Model &Queue::initFunction()
{
	elements.erase( elements.begin(), elements.end() ) ;
	return *this ;
}


/*******************************************************************
* Function Name: externalFunction
* Description: 
********************************************************************/
Model &Queue::externalFunction( const ExternalMessage &msg )
{
	if( msg.port() == in )
	{
		elements.push_back( msg.value() ) ;
		if( elements.size() == 1 )
			this->holdIn( active, preparationTime );
	}

	if( msg.port() == done )
	{
		elements.pop_front() ;
		if( !elements.empty() )
			this->holdIn( active, preparationTime );
	}

	if( msg.port() == stop )
		if( this->state() == active && msg.value() )
		{
			timeLeft = msg.time() - this->lastChange();
			this->passivate();
		} else
			if( this->state() == passive && !msg.value() )
			this->holdIn( active, timeLeft );

	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description: 
********************************************************************/
Model &Queue::internalFunction( const InternalMessage & )
{
	this->passivate();
	return *this ;
}


/*******************************************************************
* Function Name: outputFunction
* Description: 
********************************************************************/
Model &Queue::outputFunction( const InternalMessage &msg )
{
        if( !elements.empty() )
	this->sendOutput( msg.time(), out, elements.front() ) ;
	return *this ;
}
