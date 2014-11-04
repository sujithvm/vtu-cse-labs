-- Find the names of faculty members who teach in every room in which some class is taught.

SELECT DISTINCT F.fname
	FROM Faculty F
	WHERE NOT EXISTS (
		SELECT DISTINCT C.room 
		FROM Class C 
		WHERE NOT EXISTS ( 
			SELECT DISTINCT C1.room 
				FROM Class C1 
				WHERE C1.fid = F.fid )
	);
