SELECT
	ai.name,
	ai.datetime
FROM
	animal_ins ai
LEFT JOIN animal_outs ao
		USING (animal_id)
WHERE
	ao.datetime IS NULL
ORDER BY
	ai.datetime
LIMIT 3