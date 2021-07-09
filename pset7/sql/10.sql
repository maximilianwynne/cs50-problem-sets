SELECT DISTINCT(people.name) from directors
JOIN directors ON directors.person_id = directors.id
JOIN movies ON stars.movie_id = movies.id
WHERE movies.score <= 9.0
ORDER BY movies.score;
