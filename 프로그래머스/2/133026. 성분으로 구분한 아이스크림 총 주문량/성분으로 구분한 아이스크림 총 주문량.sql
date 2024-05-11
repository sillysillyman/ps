SELECT
	ingredient_type,
	SUM(total_order) TOTAL_ORDER
FROM
	first_half
INNER JOIN icecream_info
		USING (flavor)
GROUP BY
	ingredient_type
ORDER BY
	TOTAL_ORDER