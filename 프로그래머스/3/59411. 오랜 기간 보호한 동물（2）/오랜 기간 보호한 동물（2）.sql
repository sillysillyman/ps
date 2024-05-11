SELECT
	animal_id,
	ao.name
FROM
	animal_outs ao
INNER JOIN animal_ins ai
		USING (animal_id)
ORDER BY
	ao.datetime - ai.datetime DESC
LIMIT 2