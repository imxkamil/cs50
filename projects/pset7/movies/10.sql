--SELECT name
--FROM people
--WHERE id IN(SELECT person_id
    --FROM directors WHERE movie_id IN(SELECT movie_id
        --FROM ratings WHERE rating>=9.0));
SELECT DISTINCT(name)
FROM people AS p
JOIN directors AS d
ON p.id=d.person_id
JOIN ratings AS r
ON r.movie_id=d.movie_id
WHERE rating>=9.0;