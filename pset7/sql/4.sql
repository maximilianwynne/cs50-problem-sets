SELECT COUNT(title)
FROM movies
JOIN ratings WHERE movies.id = ratings.movie_id
WHERE rating = 10.0;
