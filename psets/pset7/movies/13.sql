SELECT name FROM people
-- JOIN stars ON people.id = stars.person_id




WHERE name = "Kevin Bacon"
IN (
SELECT id FROM movies
JOIN stars ON movies.id = stars.movie_id
JOIN people ON people.id = stars.person_id
WHERE people.name = "Helena Bonham Carter"
)

