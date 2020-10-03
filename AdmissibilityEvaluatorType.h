/********************************************************************
*																	*
*      				 Auto Generated File                            *
*                     												*		
*********************************************************************/

#ifndef __AdmissibilityEvaluatorType_H
#define __AdmissibilityEvaluatorType_H

/** include files **/
#include "atomic.h"  // class Atomic

/** forward declarations **/
//TODO: add distribution class declaration here if needed
// Ej: class Distribution ;

/** declarations **/
class AdmissibilityEvaluatorType: public Atomic
{
public:
	AdmissibilityEvaluatorType( const string &name = "AdmissibilityEvaluatorType" ) ;	 // Default constructor
	~AdmissibilityEvaluatorType();					// Destructor
	virtual string className() const
		{return "AdmissibilityEvaluatorType";}

protected:
	Model &initFunction();	
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	// [(!) TODO: declare ports, distributions and other private varibles here]
	/***********      Example declarations   **********************************/
	const Port &PIPassIn;	// this is an input port named 'in'
	const Port &CIIn;	// this is an input port named 'in'
	const Port &AdmIIn;	// this is an input port named 'in'

	Port &AdmEvalResultOut ;   	// this is an output port named 'out'

	bool PIInPass;
	bool CIInPass;
	bool AdmIInPass;

	bool receivedCIIn;
	bool receivedAdmIIn;

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
};	// class AdmissibilityEvaluatorType


#endif   //__AdmissibilityEvaluatorType_H 
