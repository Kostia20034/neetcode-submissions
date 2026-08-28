-- Write your query below
Select employee_id,
Case
    when employee_id % 2 != 0 and name Not like 'M%' then salary
    else 0
    end as bonus
From employees
Order by employee_id;