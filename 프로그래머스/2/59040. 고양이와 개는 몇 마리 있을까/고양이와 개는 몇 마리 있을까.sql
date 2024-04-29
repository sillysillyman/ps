SELECT
	animal_type,
	COUNT(*) count
FROM
	animal_ins
GROUP BY
	animal_type
HAVING
	animal_type IN ('Cat', 'Dog')
ORDER BY
	CASE
		WHEN animal_type = 'Cat' THEN 1
		WHEN animal_type = 'Dog' THEN 2
	END