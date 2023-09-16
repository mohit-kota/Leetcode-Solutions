# Write your MySQL query statement below

select username as results from (
select t1.name as username  from MovieRating t2 inner join Users t1 on t1.user_id = t2.user_id group by t1.user_id having count(t2.user_id) order by count(t2.user_id) desc , t1.name ASC limit 1) firstquery union all
select movie_name as results from (
   SELECT d.title as movie_name,AVG(c.rating) as grade FROM MovieRating as c
    JOIN Movies as d
    ON c.movie_id=d.movie_id
    WHERE SUBSTR(c.created_at,1,7)="2020-02"
    GROUP BY c.movie_id
    ORDER BY grade DESC,movie_name ASC LIMIT 1
) secondquery;
