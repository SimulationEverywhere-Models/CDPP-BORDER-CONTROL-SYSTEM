/********************************************************************
*																	*
*      				 Auto Generated File                            *
*                     												*		
*********************************************************************/

#ifndef __VehicleQueryPerformerType_H
#define __VehicleQueryPerformerType_H

/** include files **/
#include "atomic.h"  // class Atomic

/** forward declarations **/
//TODO: add distribution class declaration here if needed
// Ej: class Distribution ;

/** declarations **/
class VehicleQueryPerformerType: public Atomic
{
public:
	VehicleQueryPerformerType( const string &name = "VehicleQueryPerformerType" ) ;	 // Default constructor
	~VehicleQueryPerformerType();					// Destructor
	virtual string className() const
		{return "VehicleQueryPerformerType";}

protected:
	Model &initFunction();	
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	// [(!) TODO: declare ports, distributions and other private varibles here]
	/***********      Example declarations   **********************************/
	const Port &trafficIn;	// this is an input port named 'in'
	Port &VQPOut ;   	// this is an output port named 'out'
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
};	// class VehicleQueryPerformerType


#endif   //__VehicleQueryPerformerType_H 
