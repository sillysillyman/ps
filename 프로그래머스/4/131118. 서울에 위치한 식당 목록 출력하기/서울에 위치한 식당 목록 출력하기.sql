SELECT
	rest_id,
	rest_name,
	food_type,
	favorites,
	address,
	ROUND(AVG(rr.review_score), 2) score
FROM
	rest_info ri
INNER JOIN rest_review rr
		USING (rest_id)
GROUP BY
	address
HAVING
	address LIKE "서울%"
ORDER BY
	score DESC,
	favorites DESC;