/*m1*/
# Write your MySQL query statement below
SELECT
    e1.employee_id
FROM
    Employees AS e1
INNER JOIN
    Employees AS e2
ON
    e1.manager_id = e2.employee_id
INNER JOIN
    Employees AS e3
ON
    e2.manager_id = e3.employee_id
WHERE
    e3.manager_id = 1 AND e1.employee_id != 1;
