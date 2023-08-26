# Write your MySQL query statement below
/*
usually, GROUP BY group_column != SUM( aggregate_column ).
and group_column values are unqiue in the result table
*/
SELECT
    s1.gender,
    s1.day,
    SUM( s2.score_points ) AS total
FROM
    Scores AS s1,
    Scores AS s2
WHERE
    s1.gender = s2.gender AND
    s1.day >= s2.day
GROUP BY
    s1.gender, s1.day /* not s2 */
ORDER BY
    s1.gender ASC, s1.day ASC;
