SELECT name FROM people
JOIN movies ON movies.id = movie_id
JOIN stars ON people.id = person_id
WHERE movies.title LIKE "Toy Story%";