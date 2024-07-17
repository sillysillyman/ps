SELECT
	id,
	name,
	host_id
FROM
	places
INNER JOIN (
	SELECT
		host_id
	FROM
		places
	GROUP BY
		host_id
	HAVING
		COUNT(host_id) >= 2
) hu
		USING(host_id)
ORDER BY
	id