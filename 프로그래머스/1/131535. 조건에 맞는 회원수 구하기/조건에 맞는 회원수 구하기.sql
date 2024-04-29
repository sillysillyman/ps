SELECT
	COUNT(user_id)
FROM
	user_info
WHERE
	DATE_FORMAT(joined, '%Y') = 2021
	AND age BETWEEN 20 AND 29;