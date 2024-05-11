SELECT
	animal_id,
	name,
	sex_upon_intake
FROM
	animal_ins
WHERE
	name IN ('Ella', 'Lucy', 'Mitty', 'Pickle', 'Rogan', 'Sabrina')
ORDER BY
	animal_id