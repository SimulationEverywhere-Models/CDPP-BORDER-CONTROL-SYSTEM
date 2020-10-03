/********************************************************************
*																	*
*      				 Auto Generated File                            *
*                     												*		
*********************************************************************/

/** include files **/
#include "TrafficInputQueueType.h"           // base header
#include "message.h"       // InternalMessage ....
#include "distri.h"        // class Distribution
#include "mainsimu.h"      // class MainSimulator


/*******************************************************************
* Function Name: TrafficInputQueueType
* Description: constructor
********************************************************************/
TrafficInputQueueType::TrafficInputQueueType( const string &name )
: Atomic( name )
// TODO: add ports here if needed (Remember to add them to the .h file also). Each in a new line.
// Ej:
, in (addInputPort ("in"))
, systemFree (addInputPort ("systemFree"))
, start (addInputPort ("start"))
, out (addOutputPort ("out"))
{
	// TODO: add initialization code here. (reading parameters, initializing private vars, etc)
	// Code templates for reading parameters:
	// read string parameter:
	// 		stringVar = MainSimulator::Instance().getParameter( description(), "paramName" );
	// read int parameter:
	// 		intVar = str2Int( MainSimulator::Instance().getParameter( description(), "initial" ) );
	// read time parameter:
	//		timeVar = string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;
	// read distribution parameters:
	//		dist = Distribution::create( MainSimulator::Instance().getParameter( description(), "distribution" ) );
	//		MASSERT( dist ) ;
	//		for ( register int i = 0; i < dist->varCount(); i++ )
	//		{
	//			string parameter( MainSimulator::Instance().getParameter( description(), dist->getVar( i ) ) ) ;
	//			dist->setVar( i, str2Value( parameter ) ) ;
	//		}

	if (MainSimulator::Instance ().existsParameter (description (), "preparation")) {
		preparationTime = MainSimulator::Instance ().getParameter (description (), "preparation");
	} else {
		//default, 10 seconds.
		preparationTime = Time (0, 0, 10, 0);
	}

	systemIsFree=true;
}

/*******************************************************************
* Function Name: initFunction
********************************************************************/
Model &TrafficInputQueueType::initFunction()
{
	elements.erase (elements.begin (), elements.end ());
	passivate ();
	return *this;
}

/*******************************************************************
* Function Name: externalFunction
* Description: This method executes when an external event is received.
********************************************************************/
Model &TrafficInputQueueType::externalFunction( const ExternalMessage &msg )
{

	if (msg.port () == systemFree && msg.value ()==1) 	{
		systemIsFree=true;

		if (elements.size () >= 1) {
			holdIn (active, Time::Zero);
		}
		else
		{
			//last car left system, therefore sleep
			passivate ();
		}
	}


	if (msg.port () == in) 	{
		elements.push_back (msg.value ());
		if (state () == active && elements.size () == 1) {
			holdIn (active, Time::Zero);
		}
	}

	if (msg.port () == start) {
		if (state () == passive && msg.value ()) {
			holdIn (active, Time::Zero);
		} else {
			if (state () == active && !msg.value ()) {
				passivate ();
			}
		}
	}
	return *this;
}

/*******************************************************************
* Function Name: internalFunction
* Description: This method executes when the TA has expired, right after the outputFunction has finished.
* 			   The new state and TA should be set.
********************************************************************/
Model &TrafficInputQueueType::internalFunction( const InternalMessage & )
{
	//holdIn (active, Time::Zero);
	//return *this ;

 	passivate();
	return *this;

}

/*******************************************************************
* Function Name: outputFunction
* Description: This method executes when the TA has expired. After this method the internalFunction is called.
*              Output values can be send through output ports
********************************************************************/
Model &TrafficInputQueueType::outputFunction( const InternalMessage &msg )
{
	if (systemIsFree==true){
		if (!elements.empty ()) {
			//send next car into system
			sendOutput (msg.time(), out, elements.front ());
			elements.pop_front ();
			systemIsFree=false;
		}
	}
	return *this ;

}

TrafficInputQueueType::~TrafficInputQueueType()
{
	//TODO: add destruction code here. Free distribution memory, etc. 
}
