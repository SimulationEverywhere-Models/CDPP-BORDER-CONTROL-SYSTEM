/********************************************************************
*																	*
*      				 Auto Generated File                            *
*                     												*		
*********************************************************************/

#ifndef __QueryResultReviewerType_H
#define __QueryResultReviewerType_H

/** include files **/
#include "atomic.h"  // class Atomic

/** forward declarations **/
//TODO: add distribution class declaration here if needed
// Ej: class Distribution ;

/** declarations **/
class QueryResultReviewerType: public Atomic
{
public:
	QueryResultReviewerType( const string &name = "QueryResultReviewerType" ) ;	 // Default constructor
	~QueryResultReviewerType();					// Destructor
	virtual string className() const
		{return "QueryResultReviewerType";}

protected:
	Model &initFunction();	
	Model &externalFunction( const ExternalMessage & );
	Model &internalFunction( const InternalMessage & );
	Model &outputFunction( const InternalMessage & );

private:
	// [(!) TODO: declare ports, distributions and other private varibles here]
	/***********      Example declarations   **********************************/
	const Port &vqpin;	// this is an input port named 'in'
	const Port &pqpin;	// this is an input port named 'in'
	Port &QRRPassOut;   	// this is an output port named 'out'
	Port &QRRFailOut;   	// this is an output port named 'out'

	bool personQueryPass;
	bool vehicleQueryPass;

	bool receivedpersonQuery;
	bool receivedvehicleQuery;
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
};	// class QueryResultReviewerType


#endif   //__QueryResultReviewerType_H 
