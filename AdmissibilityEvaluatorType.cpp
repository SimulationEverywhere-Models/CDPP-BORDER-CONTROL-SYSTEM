/********************************************************************
*																	*
*      				 Auto Generated File                            *
*                     												*		
*********************************************************************/

/** include files **/
#include "AdmissibilityEvaluatorType.h"           // base header
#include "message.h"       // InternalMessage ....
#include "distri.h"        // class Distribution
#include "mainsimu.h"      // class MainSimulator


/*******************************************************************
* Function Name: AdmissibilityEvaluatorType
* Description: constructor
********************************************************************/
AdmissibilityEvaluatorType::AdmissibilityEvaluatorType( const string &name )
: Atomic( name )
// TODO: add ports here if needed (Remember to add them to the .h file also). Each in a new line.
// Ej:
, AdmEvalResultOut(addOutputPort( "AdmEvalResultOut" ))
, PIPassIn(addInputPort( "PIPassIn" ))
, CIIn(addInputPort( "CIIn" ))
, AdmIIn(addInputPort( "AdmIIn" ))
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
	CIInPass = false;
	AdmIInPass = false;
	PIInPass = false;
}

/*******************************************************************
* Function Name: initFunction
********************************************************************/
Model &AdmissibilityEvaluatorType::initFunction()
{
 	this->passivate();
	return *this ;
}

/*******************************************************************
* Function Name: externalFunction
* Description: This method executes when an external event is received.
********************************************************************/
Model &AdmissibilityEvaluatorType::externalFunction( const ExternalMessage &msg )
{
	//[(!) update common variables]	
	//this->sigma = nextChange();
	//this->elapsed = msg.time()-lastChange();
 	//this->timeLeft = this->sigma - this->elapsed;
	
	//TODO: implement the external function here.
 	// Remember you can use the msg object (mgs.port(), msg.value()) and you should set the next TA (you might use the holdIn method).
 	// EJ:

	//bool receivedCIIn;
	//bool receivedAdmIIn;








	if (msg.port() == PIPassIn){
		PIInPass = true;
	 	// set next transition
		//calculate processing time
		int randMinute = int(rand() % 3 + 2); //range 2-5

		Time t(00,randMinute,00,00);
		holdIn(Atomic::active, t);
		return *this ;
	}


	if (msg.port() == CIIn){
		receivedCIIn = true;
		if (msg.value() == 1) {
			CIInPass = true;
		}
		else
		{
			CIInPass = false;

		}
	}


	if (msg.port() == AdmIIn){
		receivedAdmIIn=true;
		if (msg.value() == 1) {
			AdmIInPass = true;
		}
		else
		{
			AdmIInPass = false;
		}
	}







	if (receivedCIIn==true && receivedAdmIIn==true){
		//calculate processing time
		int randMinute = int(rand() % 3 + 2); //range 2-5

		Time t(00,randMinute,00,00);
		holdIn(Atomic::active, t);

	} else {
		//don't yet have both inputs, wait for next input
		holdIn(Atomic::active, Time::Zero);
	}



	return *this ;
}

/*******************************************************************
* Function Name: internalFunction
* Description: This method executes when the TA has expired, right after the outputFunction has finished.
* 			   The new state and TA should be set.
********************************************************************/
Model &AdmissibilityEvaluatorType::internalFunction( const InternalMessage & )
{
	//reset flags:
	if (receivedCIIn==true && receivedAdmIIn==true){
		receivedAdmIIn=false;
		receivedCIIn=false;
		AdmIInPass=false;
		CIInPass=false;
	}

	PIInPass = false;

 	passivate();
	return *this;
}

/*******************************************************************
* Function Name: outputFunction
* Description: This method executes when the TA has expired. After this method the internalFunction is called.
*              Output values can be send through output ports
********************************************************************/
Model &AdmissibilityEvaluatorType::outputFunction( const InternalMessage &msg )
{
	//TODO: implement the output function here
	// remember you can use sendOutput(time, outputPort, value) function.
	// sendOutput( msg.time(), out, 1) ;
	


	if (PIInPass==true){
		this->sendOutput( msg.time(), AdmEvalResultOut, 1 ) ;
		return *this;
	}


	//check we if received both required inputs. If so then process
	if (receivedCIIn==true && receivedAdmIIn==true){


		if (AdmIInPass==true && CIInPass==true){
			this->sendOutput( msg.time(), AdmEvalResultOut, 1 ) ;
		}
		else
		{
			this->sendOutput( msg.time(), AdmEvalResultOut, 0 ) ;
		}

	}
	return *this;

}

AdmissibilityEvaluatorType::~AdmissibilityEvaluatorType()
{
	//TODO: add destruction code here. Free distribution memory, etc. 
}
