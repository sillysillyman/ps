WITH sorted_ecoli_data AS (
    SELECT 
		id,
        NTILE(4) OVER (ORDER BY size_of_colony DESC) colony_name
    FROM ecoli_data
)
SELECT
    id,
    CASE
        WHEN colony_name = 1 THEN 'CRITICAL'
        WHEN colony_name = 2 THEN 'HIGH'
        WHEN colony_name = 3 THEN 'MEDIUM'
        ELSE 'LOW'
    END colony_name
FROM sorted_ecoli_data
ORDER BY id