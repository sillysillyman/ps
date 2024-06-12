SELECT
	user_id,
	nickname,
	CONCAT(city, ' ', street_address1, ' ', street_address2) `전체주소`,
	CONCAT(substring(tlno, 1, 3), '-', substring(tlno, 4, 4), '-', substring(tlno, 8)) `전화번호`
FROM
	used_goods_user
INNER JOIN used_goods_board ON
	user_id = writer_id
GROUP BY
	user_id
HAVING
	COUNT(*) >= 3
ORDER BY
	user_id DESC