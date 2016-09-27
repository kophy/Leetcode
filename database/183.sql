# Write your MySQL query statement below
SELECT NAME AS Customers
FROM Customers
WHERE Id NOT IN (
    SELECT CustomerId
    FROM Orders
);