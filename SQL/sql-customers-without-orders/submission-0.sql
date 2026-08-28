-- Write your query below
Select name
from customers
where id Not in (
    Select customer_id
    from orders
    --where customer_id is not null
)