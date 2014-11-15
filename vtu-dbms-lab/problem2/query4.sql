-- For all aircraft with cruisingrange over 1000 Kms,. Find the name of the aircraft and the average salary of all 
-- pilots certified for this aircraft.

SELECT TEMP.NAME, TEMP.AVGSALARY
FROM (
	SELECT A.aid, A.aname AS NAME, AVG (E.SALARY) AS AVGSALARY
	FROM Aircraft A, Certified C, Employees E
	WHERE 
		A.aid = C.aid AND
		C.eid = E.eid AND 
		A.cruisingrange > 1000

	GROUP BY A.aid, A.aname

) AS TEMP

;
