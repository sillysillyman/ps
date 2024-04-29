SELECT
	ROUND(AVG(daily_fee)) avrage_fee
FROM
	car_rental_company_car
GROUP BY
	car_type
HAVING
	car_type = 'SUV'