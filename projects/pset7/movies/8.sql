--SELECT name
--FROM people
--WHERE id IN(SELECT person_id
    --FROM stars
    --WHERE movie_id IN(SELECT id
        --FROM movies WHERE title="Toy Story"));

SELECT name
FROM people AS p
JOIN stars AS s
ON s.person_id=p.id
JOIN movies AS m
ON s.movie_id=m.id
WHERE title="Toy Story";