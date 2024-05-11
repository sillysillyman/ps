SELECT
	product_code,
	SUM(price * sales_amount) sales
FROM
	product
INNER JOIN offline_sale
		USING (product_id)
GROUP BY
	product_code
ORDER BY
	sales DESC,
	product_code