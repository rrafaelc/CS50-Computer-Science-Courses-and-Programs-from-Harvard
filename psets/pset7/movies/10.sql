SELECT DISTINCT(name) FROM people
JOIN directors ON directors.person_id = people.id
JOIN 