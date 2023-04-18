--write a SQL query to list the names of all people
--who starred in a movie in which Kevin Bacon also starred

SELECT name
FROM people
WHERE id IN(SELECT person_id
FROM stars WHERE movie_id IN(SELECT id
FROM movies WHERE id IN(SELECT movie_id
FROM stars WHERE person_id IN(SELECT id
FROM people WHERE name="Kevin Bacon" AND birth=1958))))
AND name != "Kevin Bacon";

--from internet:
--SELECT name
--FROM people AS p
--JOIN stars AS s
--ON p.id=s.person_id
--WHERE movie_id IN(SELECT movie_id
--FROM people AS p JOIN stars AS s
--ON p.id=s.person_id
--WHERE name="Kevin Bacon" AND birth=1958)
--ORDER BY name
--LIMIT 10;