SELECT
	category,
	SUM(sales) total_sales
FROM
	book
INNER JOIN book_sales
		USING (book_id)
WHERE
	DATE_FORMAT(sales_date,
	'%Y-%m') = '2022-01'
GROUP BY
	category
ORDER BY
	category