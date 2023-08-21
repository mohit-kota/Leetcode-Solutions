# Write your MySQL query statement below

select e1.student_id , e1.student_name , e2.subject_name , count(e3.student_id) as attended_exams from Students e1 join Subjects e2 left join Examinations e3 on e1.student_id = e3.student_id and e2.subject_name = e3.subject_name group by e1.student_id,e2.subject_name  order by e1.student_id,e2.subject_name;
