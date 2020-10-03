/********************************************************************
*																	*
*      				 Auto Generated File                            *
*                     												*		
*********************************************************************/

/** include files **/
#include "ActionTakerType.h"           // base header
#include "message.h"       // InternalMessage ....
#include "distri.h"        // class Distribution
#include "mainsimu.h"      // class MainSimulator


/*******************************************************************
* Function Name: ActionTakerType
* Description: constructor
********************************************************************/
ActionTakerType::ActionTakerType( const string &name )
: Atomic( name )
// TODO: add ports here if needed (Remember to add them to the .h file also). Each in a new line.
// Ej:
, actionOut(addOutputPort( "actionOut" ))
, carLeft(addOutputPort( "carLeft" ))
, AdmEvalResultIn(addInputPort( "AdmEvalResultIn" ))
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
	pass=false;
}

/*******************************************************************
* Function Name: initFunction
********************************************************************/
Model &ActionTakerType::initFunction()
{
 	this->passivate();
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: This method executes when an external event is received.
********************************************************************/
Model &ActionTakerType::externalFunction( const ExternalMessage &msg )
{
	
	
	if (msg.port() == AdmEvalResultIn){
		if (msg.value() == 1) {
			pass = true;
		}
		else
		{
			pass = false;
		}
	}




	//calculate processing time
	int randMinute = int(rand() % 3 + 2); //range 2-8

	Time t(00,randMinute,00,00);
	holdIn(Atomic::active, t);

	return *this ;
}

/*******************************************************************
* Function Name: internalFunction
* Description: This method executes when the TA has expired, right after the outputFunction has finished.
* 			   The new state and TA should be set.
********************************************************************/
Model &ActionTakerType::internalFunction( const InternalMessage & )
{
	//reset flag:
	pass=false;

 	passivate();
	return *this;

}

/*******************************************************************
* Function Name: outputFunction
* Description: This method executes when the TA has expired. After this method the internalFunction is called.
*              Output values can be send through output ports
********************************************************************/
Model &ActionTakerType::outputFunction( const InternalMessage &msg )
{
	//check we if received both required inputs. If so then process
	if (pass==true){
		this->sendOutput( msg.time(), actionOut, 1 ) ;
	} else{
		this->sendOutput( msg.time(), actionOut, 0 ) ;
	}
	
	this->sendOutput( msg.time(), carLeft, 1 ) ;


	return *this;
}

ActionTakerType::~ActionTakerType()
{
	//TODO: add destruction code here. Free distribution memory, etc. 
}
