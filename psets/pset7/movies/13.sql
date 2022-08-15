SELECT DISTINCT(name) FROM people
JOIN stars ON people.id = stars.person_id


JOIN movies ON stars.movie_id = movies.id

WHERE movies.title
IN (
SELECT distinct(title) FROM movies
JOIN stars ON movies.id = stars.movie_id
JOIN people ON people.id = stars.person_id
WHERE people.name = "Helena Bonham Carter"
)

