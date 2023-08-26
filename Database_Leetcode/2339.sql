# Write your MySQL query statement below
SELECT
    home.team_name AS home_team,
    away.team_name AS away_team
FROM
    Teams AS home,
    Teams AS away
WHERE
    home.team_name != away.team_name;
