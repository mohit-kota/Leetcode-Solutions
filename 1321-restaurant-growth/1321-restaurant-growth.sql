# Write your MySQL query statement below
# select a.visited_on as visited_on ,sum(b.day_sum) as amount , ROUND(avg(b.day_sum),2) as average_amount from (select visited_on , sum(amount) as day_sum from Customer group by visited_on) a , (select visited_on , sum(amount) as day_sum from Customer group by visited_on ) b where DATEDIFF(a.visited_on,b.visited_on) between 0 and 6 group by a.visited_on having count(b.visited_on) = 7;

SELECT
    visited_on,
    (
        SELECT SUM(amount)
        FROM customer
        WHERE visited_on BETWEEN DATE_SUB(c.visited_on, INTERVAL 6 DAY) AND c.visited_on
    ) AS amount,
    ROUND(
        (
            SELECT SUM(amount) / 7
            FROM customer
            WHERE visited_on BETWEEN DATE_SUB(c.visited_on, INTERVAL 6 DAY) AND c.visited_on
        ),
        2
    ) AS average_amount
FROM customer c
WHERE visited_on >= (
        SELECT DATE_ADD(MIN(visited_on), INTERVAL 6 DAY)
        FROM customer
    )
GROUP BY visited_on;
