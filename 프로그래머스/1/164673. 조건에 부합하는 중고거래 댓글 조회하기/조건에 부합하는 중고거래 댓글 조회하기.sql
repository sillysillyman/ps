SELECT
	title,
	board_id,
	reply_id,
	ugr.writer_id,
	ugr.contents,
	DATE_FORMAT(ugr.created_date, '%Y-%m-%d') created_date
FROM
	used_goods_board ugb
INNER JOIN used_goods_reply ugr
		USING (board_id)
WHERE
	DATE_FORMAT(ugb.created_date, '%Y-%m') = '2022-10'
ORDER BY
	ugr.created_date,
	title