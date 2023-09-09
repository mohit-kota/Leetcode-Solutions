SELECT product_id, year as first_year, quantity, price
from Sales 
WHERE (product_id, year) IN (SELECT product_id, min(year) as year
FROM Sales 
group by product_id)