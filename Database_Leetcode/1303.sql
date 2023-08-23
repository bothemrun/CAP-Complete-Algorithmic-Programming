# Write your MySQL query statement below
SELECT e.employee_id, ( SELECT COUNT(*) FROM Employee WHERE team_id = e.team_id ) as team_size FROM Employee AS e;
