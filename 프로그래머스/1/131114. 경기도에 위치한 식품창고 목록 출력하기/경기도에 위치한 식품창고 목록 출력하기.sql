SELECT
	warehouse_id,
	warehouse_name,
	address,
	IFNULL(freezer_yn, 'N') freezer_yn
FROM
	food_warehouse
WHERE
	SUBSTRING_INDEX(address, ' ', 1) = '경기도'
ORDER BY
	warehouse_id