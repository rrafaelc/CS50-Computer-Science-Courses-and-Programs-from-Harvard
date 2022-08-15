SELECT name FROM people JOIN movies, stars
ON movies.id = stars.movie_id



AND stars.person_id = people.id





WHERE movies.title LIKE "Toy Story%";