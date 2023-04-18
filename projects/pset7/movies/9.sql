--SELECT COUNT(name)
--FROM people
--WHERE id IN(SELECT movie_id
--    FROM stars
--    WHERE movie_id IN(SELECT id
--        FROM movies
--        WHERE year=2004))
--ORDER BY birth;

SELECT COUNT(name)
FROM people
JOIN stars
ON stars.person_id=people.id
JOIN movies
ON movies.id = stars.movie_id
WHERE year = 2004
GROUP BY name, person_id;