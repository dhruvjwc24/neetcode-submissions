-- Write your query below
SELECT customer_id 
FROM customers
WHERE 
    customers.revenue > 0 AND
    customers.year IN(2020);