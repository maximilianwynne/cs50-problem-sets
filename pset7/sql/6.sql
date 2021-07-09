SELECT AVG(rating) FROM movies
JOIN movies ON ratings.movies_id = movies.id
WHERE year = 2012;
