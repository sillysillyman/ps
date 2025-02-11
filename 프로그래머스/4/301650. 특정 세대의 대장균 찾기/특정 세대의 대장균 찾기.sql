SELECT ed1.id
FROM
    ecoli_data ed1
    INNER JOIN ecoli_data ed2 ON ed1.parent_id = ed2.id
    INNER JOIN ecoli_data ed3 ON ed2.parent_id = ed3.id
WHERE ed3.parent_id IS NULL
ORDER BY ed1.id