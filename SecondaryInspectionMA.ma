[Top]
components : SecondaryInsection 
out : AdmIOut CIOut 
in : in 
Link : in in@SecondaryInsection
Link : AdmIOut@SecondaryInsection AdmIOut
Link : CIOut@SecondaryInsection CIOut

[SecondaryInsection]
components : AdmissibilityInspection@AdmissibilityInspectionType CustomsInspection@CustomsInspectionType 
out : AdmIOut CIOut 
in : in 
Link : in PIFailIn@CustomsInspection
Link : in PIFailIn@AdmissibilityInspection
Link : AdmIOut@AdmissibilityInspection AdmIOut
Link : CIOut@CustomsInspection CIOut

[AdmissibilityInspection]

[CustomsInspection]



