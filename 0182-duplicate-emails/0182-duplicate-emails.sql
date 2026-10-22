# Write your MySQL query statement below
Select Email from Person Group By email having COUNT(*) > 1;