SELECT
	animal_id,
	name,
	IF(SUBSTRING_INDEX(sex_upon_intake, ' ', 1) IN ('Neutered', 'Spayed'), 'O', 'X') `중성화`
FROM
	animal_ins
ORDER BY
	animal_id