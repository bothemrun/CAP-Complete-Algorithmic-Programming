# Write your MySQL query statement below
/* https://www.w3schools.com/sql/sql_in.asp */
SELECT id, name FROM Students WHERE department_id NOT IN (SELECT id FROM Departments);
