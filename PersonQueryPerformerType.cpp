/********************************************************************
*																	*
*      				 Auto Generated File                            *
*                     												*		
*********************************************************************/

/** include files **/
#include "PersonQueryPerformerType.h"           // base header
#include "message.h"       // InternalMessage ....
#include "distri.h"        // class Distribution
#include "mainsimu.h"      // class MainSimulator


/*******************************************************************
* Function Name: PersonQueryPerformerType
* Description: constructor
********************************************************************/
PersonQueryPerformerType::PersonQueryPerformerType( const string &name )
: Atomic( name )
// TODO: add ports here if needed (Remember to add them to the .h file also). Each in a new line.
// Ej:
, PQPResultOut(addOutputPort( "PQPResultOut" ))
, PQPtrafficIn(addInputPort( "PQPtrafficIn" ))
//, preparationTime( 0, 0, 10, 0 )
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

	//string time( MainSimulator::Instance().getParameter( description(), "preparation" ) ) ;

	//if( time != "" )
	//	preparationTime = time ;
}

/*******************************************************************
* Function Name: initFunction
********************************************************************/
Model &PersonQueryPerformerType::initFunction()
{
	this->passivate();
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: This method executes when an external event is received.
********************************************************************/
Model &PersonQueryPerformerType::externalFunction( const ExternalMessage &msg )
{
	int randMinute = int(rand() % 2 + 3); //range 3-5

	Time t(00,randMinute,00,00);
	holdIn(Atomic::active, t);


	return *this ;
}

/*******************************************************************
* Function Name: internalFunction
* Description: This method executes when the TA has expired, right after the outputFunction has finished.
* 			   The new state and TA should be set.
********************************************************************/
Model &PersonQueryPerformerType::internalFunction( const InternalMessage & )
{
 	passivate();
	return *this;
}

/*******************************************************************
* Function Name: outputFunction
* Description: This method executes when the TA has expired. After this method the internalFunction is called.
*              Output values can be send through output ports
********************************************************************/
Model &PersonQueryPerformerType::outputFunction( const InternalMessage &msg )
{
	//TODO: implement the output function here
	// remember you can use sendOutput(time, outputPort, value) function.
	// sendOutput( msg.time(), out, 1) ;
	
	//output 'pass' 95% of the time:
	if ((double)rand() / (double) RAND_MAX  < 0.95)
	{
		this->sendOutput( msg.time(), PQPResultOut, 1 ) ;
	}
	else
	{
		this->sendOutput( msg.time(), PQPResultOut, 0 ) ;
	}



	return *this;

}

PersonQueryPerformerType::~PersonQueryPerformerType()
{
	//TODO: add destruction code here. Free distribution memory, etc. 
}
