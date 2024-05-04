SELECT
	mcdp_cd `진료과코드`,
	COUNT(*) `5월예약건수`
FROM
	appointment
WHERE
	DATE_FORMAT(apnt_ymd, '%Y-%m') = '2022-05'
GROUP BY
	mcdp_cd
ORDER BY
	`5월예약건수`,
	mcdp_cd