# Write your MySQL query statement below
SELECT
    a.sale_date, a.sold_num - b.sold_num AS diff
FROM
    Sales AS a, Sales AS b
WHERE
    a.sale_date = b.sale_date AND a.fruit = "apples" AND b.fruit = "oranges"
ORDER BY
    a.sale_date ASC;
