SELECT
	SUBSTR(product_code, 1, 2) category,
	COUNT(*) products
FROM
	product
GROUP BY
	category
ORDER BY
	category