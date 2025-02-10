SELECT ed1.id, COUNT(ed2.id) child_count
FROM ecoli_data ed1
LEFT JOIN ecoli_data ed2 ON ed1.id = ed2.parent_id
GROUP BY ed1.id
ORDER BY ed1.id