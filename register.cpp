/*******************************************************************
*
*  Auto Generated File
*
*  DESCRIPTION: Simulator::registerNewAtomics()
*
*  This registration file is used to describe the atomic models that can be used to compose coupled models.
*
*
*******************************************************************/

#include "modeladm.h" 
#include "mainsimu.h"
#include "queue.h"      // class Queue
#include "generat.h"    // class Generator
#include "cpu.h"        // class CPU
#include "transduc.h"   // class Transducer
#include "trafico.h"    // class Trafico
#include "ggad.h"       // DEVS-Graphs interpreter
#include "TrafficInputQueueType.h"        // class TrafficInputQueueType
#include "ActionTakerType.h"	// class ActionTakerType
#include "VehicleQueryPerformerType.h"	// class VehicleQueryPerformerType
#include "PersonQueryPerformerType.h"	// class PersonQueryPerformerType
#include "QueryResultReviewerType.h"	// class QueryResultReviewerType
#include "AdmissibilityEvaluatorType.h"	// class AdmissibilityEvaluatorType
#include "AdmissibilityInspectionType.h"	// class AdmissibilityInspectionType
#include "CustomsInspectionType.h"	// class CustomsInspectionType

void MainSimulator::registerNewAtomics()
{
	// Register Built-in models
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Queue>() , "Queue" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Generator>() , "Generator" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<CPU>() , "CPU" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Transducer>() , "Transducer" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Trafico>() , "Trafico" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<Ggad>() , "Ggad" ) ; // DEVS-GRAPHS interpreter

	// Register custom models
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<TrafficInputQueueType>(), "TrafficInputQueueType" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<ActionTakerType>() , "ActionTakerType" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<VehicleQueryPerformerType>() , "VehicleQueryPerformerType" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<PersonQueryPerformerType>() , "PersonQueryPerformerType" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<QueryResultReviewerType>() , "QueryResultReviewerType" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<AdmissibilityEvaluatorType>() , "AdmissibilityEvaluatorType" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<AdmissibilityInspectionType>() , "AdmissibilityInspectionType" ) ;
	SingleModelAdm::Instance().registerAtomic( NewAtomicFunction<CustomsInspectionType>() , "CustomsInspectionType" ) ;
}
