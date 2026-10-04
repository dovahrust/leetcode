CREATE OR REPLACE FUNCTION NthHighestSalary(N INT) RETURNS TABLE (Salary INT) AS $$
BEGIN
  IF N <= 0 THEN 
    RETURN;
  END IF;

  RETURN QUERY (
    -- Write your PostgreSQL query statement below.
    SELECT DISTINCT e.salary FROM Employee e
    ORDER BY salary DESC
    LIMIT 1 OFFSET N - 1 
      
  );
END;
$$ LANGUAGE plpgsql;
