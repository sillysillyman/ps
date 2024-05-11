SELECT
	animal_id,
	ai.name
FROM
	animal_ins ai
INNER JOIN animal_outs ao
		USING (animal_id)
WHERE
	ao.datetime < ai.datetime
ORDER BY
	ai.datetime