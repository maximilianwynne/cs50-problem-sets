SELECT DISTINCT(people.name) from directors
JOIN directors ON directors.id = directors.person_id
JOIN movies ON directors.movie_id = movies.id
JOIN ratings ON movies.id = ratings.movie_id
WHERE movies.score => 9.0
ORDER BY movies.score;
