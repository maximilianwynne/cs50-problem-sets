SELECT DISTINCT(movies.title) from people
JOIN stars ON people.id = stars.person_id
JOIN movies ON stars.movie_id = movies.id
JOIN ratings ON movie.id = ratings.movie_id
WHERE people.name = "Chadwick Boseman"
ORDER BY rating DESC;
