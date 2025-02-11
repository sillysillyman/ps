SELECT ed1.id, ed1.genotype, ed2.genotype parent_genotype
FROM ecoli_data ed1
INNER JOIN ecoli_data ed2 ON ed1.parent_id = ed2.id
WHERE ed1.genotype & ed2.genotype = ed2.genotype
ORDER BY id;