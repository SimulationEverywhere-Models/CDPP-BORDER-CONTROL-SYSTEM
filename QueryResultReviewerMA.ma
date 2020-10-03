[Top]
components : QueryResultReviewer@QueryResultReviewerType 
out : QRRPassOut QQRFailOut 
in : pqpin vqpin 
Link : pqpin pqpin@QueryResultReviewer
Link : QRRPassOut@QueryResultReviewer QRRPassOut
Link : QRRFailOut@QueryResultReviewer QQRFailOut
Link : vqpin vqpin@QueryResultReviewer

[QueryResultReviewer]


