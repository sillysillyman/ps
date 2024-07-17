SELECT
	flavor
FROM
	first_half fh
INNER JOIN (
	SELECT
		flavor,
		SUM(total_order) total_order
	FROM
		july
	GROUP BY
		flavor
) j
		USING(flavor)
ORDER BY
	fh.total_order + j.total_order DESC
LIMIT 3