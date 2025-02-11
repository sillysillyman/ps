WITH RECURSIVE generations AS (
    SELECT id, 1 generation
    FROM ecoli_data
    WHERE parent_id IS NULL
    
    UNION ALL
    
    SELECT ed.id, g.generation + 1
    FROM ecoli_data ed
    INNER JOIN generations g ON parent_id = g.id
)
SELECT COUNT(generation) count, generation
FROM generations g
LEFT JOIN ecoli_data ed ON g.id = ed.parent_id
WHERE ed.parent_id IS NULL
GROUP BY generation
ORDER BY generation