# Write your MySQL query statement below
/* GROUP BY + JOIN:
https://www.programiz.com/sql/group-by
 */
SELECT
    w.name AS warehouse_name,
    SUM( w.units * p.Width * p.Length * p.Height ) AS volume
FROM
    Warehouse as w
INNER JOIN
    Products as p
ON
    w.product_id = p.product_id
GROUP BY
    w.name;
