SELECT
	animal_id,
	ao.animal_type,
	ao.name
FROM
	animal_outs ao
INNER JOIN animal_ins ai
		USING (animal_id)
WHERE
	SUBSTRING_INDEX(ai.sex_upon_intake,
	' ',
	1) = 'Intact'
	AND SUBSTRING_INDEX(ao.sex_upon_outcome,
	' ',
	1) IN ('Neutered', 'Spayed')
ORDER BY
	animal_id