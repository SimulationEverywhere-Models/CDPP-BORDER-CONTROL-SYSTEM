/********************************************************************
*																	*
*      				 Auto Generated File                            *
*                     												*		
*********************************************************************/

#ifndef __PersonQueryPerformerType_H
#define __PersonQueryPerformerType_H

/** include files **/
#include "atomic.h"  // class Atomic

/** forward declarations **/
//TODO: add distribution class declaration here if needed
// Ej: class Distribution ;

/** declarations **/
class PersonQueryPerformerType: public Atomic
{
public:
	PersonQueryPerformerType( const string &name = "PersonQueryPerformerType" ) ;	 // Default constructor
	~PersonQueryPerformerType();					// Destructor
	virtual string className() const
		{return "PersonQueryPerformerType";}

protected:
	Model &initFunction();	
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	// [(!) TODO: declare ports, distributions and other private varibles here]
	/***********      Example declarations   **********************************/
	const Port &PQPtrafficIn;	// this is an input port named 'in'
	Port &PQPResultOut;   	// this is an output port named 'out'
	//Time preparationTime;

	// Distribution *dist ;
	// Distribution &distribution()	{ return *dist; }
	/**************************************************************************/

	// [(!) declare common variables]
	// Lifetime programmed since the last state transition to the next planned internal transition.
	Time sigma;
	
	// Time elapsed since the last state transition until now
	Time elapsed;
	
	// Time remaining to complete the last programmed Lifetime
	Time timeLeft;	
};	// class PersonQueryPerformerType


#endif   //__PersonQueryPerformerType_H 
