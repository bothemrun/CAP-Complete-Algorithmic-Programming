# Write your MySQL query statement below
/*
https://www.w3schools.com/mysql/func_mysql_date_format.asp
*/
SELECT
    DATE_FORMAT(day, "%W, %M %e, %Y") AS day
FROM
    Days;
