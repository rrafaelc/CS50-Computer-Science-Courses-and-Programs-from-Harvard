SELECT title FROM movies
JOIN ratings ON ratings.movie_id = movies.id


JOIN stars ON 
ORDER BY ratings.rating LIMIT 5