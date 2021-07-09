SELECT DISTINCT(name) from people
JOIN directors ON people.id = directors.person_id
JOIN movies ON directors.movie_id = movies.id
JOIN ratings ON movies.id = ratings.movie_id
WHERE ratings.movie => 9.0
ORDER BY ratings.movie;
