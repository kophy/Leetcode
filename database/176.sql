# Write your MySQL query statement below
SELECT MAX(salary) AS SecondHighestSalary
FROM (
	SELECT e1.salary AS salary
	FROM Employee AS e1, Employee AS e2
	WHERE e1.salary < e2.salary
) temp;