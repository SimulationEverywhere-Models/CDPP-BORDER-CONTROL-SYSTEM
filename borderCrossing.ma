[Top]
components : BorderCrossing 
out : Action 
in : in 
in : start 
Link : start start@BorderCrossing
Link : in in@BorderCrossing
Link : action@BorderCrossing Action


[BorderCrossing]
components : TrafficInputQueue@TrafficInputQueueType ActionTaker@ActionTakerType ProcessingModule 
out : action 
in : start in 
Link : start start@TrafficInputQueue
Link : in in@TrafficInputQueue
Link : carLeft@ActionTaker systemFree@TrafficInputQueue
Link : actionOut@ActionTaker action
Link : out@TrafficInputQueue trafficIn@ProcessingModule
Link : AdmEvalOut@ProcessingModule AdmEvalResultIn@ActionTaker


[TrafficInputQueue]

[ActionTaker]

[ProcessingModule]
components : AdmissibilityEvaluator@AdmissibilityEvaluatorType PrimaryInspection SecondaryInspection 
out : AdmEvalOut 
in : trafficIn 
Link : AdmEvalResultOut@AdmissibilityEvaluator AdmEvalOut
Link : trafficIn trafficIn@PrimaryInspection
Link : PIFail@PrimaryInspection SIInput@SecondaryInspection
Link : PIPass@PrimaryInspection PIPassIn@AdmissibilityEvaluator
Link : AdmIOut@SecondaryInspection AdmIIn@AdmissibilityEvaluator
Link : CIOut@SecondaryInspection CIIn@AdmissibilityEvaluator
Link : trafficIn trafficIn@PrimaryInspection

[AdmissibilityEvaluator]

[PrimaryInspection]
components : VehicleQueryPerformer@VehicleQueryPerformerType PersonQueryPerformer@PersonQueryPerformerType QueryResultReviewer@QueryResultReviewerType 
out : PIPass PIFail 
in : trafficIn 
Link : QRRPassOut@QueryResultReviewer PIPass
Link : QRRFailOut@QueryResultReviewer PIFail
Link : VQPOut@VehicleQueryPerformer vqpin@QueryResultReviewer
Link : PQPResultOut@PersonQueryPerformer pqpin@QueryResultReviewer
Link : trafficIn PQPtrafficIn@PersonQueryPerformer
Link : trafficIn trafficIn@VehicleQueryPerformer

[VehicleQueryPerformer]

[PersonQueryPerformer]

[QueryResultReviewer]


[SecondaryInspection]
components : AdmissibilityInspection@AdmissibilityInspectionType CustomsInspection@CustomsInspectionType 
out : AdmIOut CIOut 
in : SIInput 
Link : AdmIOut@AdmissibilityInspection AdmIOut
Link : CIOut@CustomsInspection CIOut
Link : SIInput PIFailIn@AdmissibilityInspection
Link : SIInput PIFailIn@CustomsInspection

[AdmissibilityInspection]

[CustomsInspection]





