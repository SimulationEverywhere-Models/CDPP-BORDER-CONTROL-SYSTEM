/********************************************************************
*																	*
*      				 Auto Generated File                            *
*                     												*		
*********************************************************************/

#ifndef __CustomsInspectionType_H
#define __CustomsInspectionType_H

/** include files **/
#include "atomic.h"  // class Atomic

/** forward declarations **/
//TODO: add distribution class declaration here if needed
// Ej: class Distribution ;

/** declarations **/
class CustomsInspectionType: public Atomic
{
public:
	CustomsInspectionType( const string &name = "CustomsInspectionType" ) ;	 // Default constructor
	~CustomsInspectionType();					// Destructor
	virtual string className() const
		{return "CustomsInspectionType";}

protected:
	Model &initFunction();	
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	// [(!) TODO: declare ports, distributions and other private varibles here]
	/***********      Example declarations   **********************************/
	const Port &PIFailIn;	// this is an input port named 'in'
	Port &CIOut ;   	// this is an output port named 'out'
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
};	// class CustomsInspectionType


#endif   //__CustomsInspectionType_H 
