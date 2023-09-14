(select 
"Low Salary" as category,
(select count(*)  from Accounts where income < 20000) as accounts_count)
union all
(select 
"Average Salary" as category,
(select count(*) from Accounts where income >= 20000 and income <= 50000) as accounts_count)
union all 
(select 
"High Salary" as category,
(select count(*) from Accounts where income > 50000) as accounts_count)