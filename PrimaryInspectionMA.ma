[Top]
components : PrimaryInspection 
out : pass fail 
in : in 
Link : pass@PrimaryInspection pass
Link : fail@PrimaryInspection fail
Link : in in@PrimaryInspection

[PrimaryInspection]
components : VehicleQueryPerformer@VehicleQueryPerformerType PersonQueryPerformer@PersonQueryPerformerType QueryResultReviewer@QueryResultReviewerType 
out : pass fail 
in : in 
Link : in trafficIn@VehicleQueryPerformer
Link : in PQPtrafficIn@PersonQueryPerformer
Link : PQPResultOut@PersonQueryPerformer pqpin@QueryResultReviewer
Link : VQPOut@VehicleQueryPerformer vqpin@QueryResultReviewer
Link : QRRPassOut@QueryResultReviewer pass
Link : QRRFailOut@QueryResultReviewer fail

[VehicleQueryPerformer]

[PersonQueryPerformer]

[QueryResultReviewer]



