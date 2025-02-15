SELECT
    SUM(price) total_price
FROM
    item_info
WHERE
    rarity = 'LEGEND'