SELECT
	ANIMAL_ID,
	NAME
FROM
	ANIMAL_OUTS ao
WHERE
	NOT EXISTS (
	SELECT
		*
	FROM
		ANIMAL_INS ai
	WHERE
		ai.ANIMAL_ID = ao.ANIMAL_ID
    )
ORDER BY
	ANIMAL_ID;