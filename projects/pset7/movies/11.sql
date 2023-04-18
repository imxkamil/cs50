--write a SQL query to list the titles of the five highest rated movies
--(in order) that Chadwick Boseman starred in,
--starting with the highest rated

--SELECT title
--FROM movies
--WHERE id IN(SELECT movie_id
--FROM stars WHERE person_id IN(SELECT id
--FROM people WHERE name = "Chadwick Boseman"))
--AND id IN(SELECT movie_id
--FROM ratings ORDER BY rating DESC) LIMIT 5;

SELECT title
FROM movies
JOIN stars ON stars.movie_id = movies.id
JOIN people ON people.id = stars.person_id
JOIN ratings ON ratings.movie_id=movies.id

WHERE name = "Chadwick Boseman"
ORDER BY rating DESC
LIMIT 5;