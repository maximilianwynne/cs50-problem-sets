SELECT movies.title
FROM people
JOIN stars ON people.id = stars.person_id
JOIN movies ON stars.movie_id = movies.id
GROUP BY 'Kevin Bacon' IN '1958' IN movies.title
DELETE FROM people WHERE people = "Kevin Bacon";
