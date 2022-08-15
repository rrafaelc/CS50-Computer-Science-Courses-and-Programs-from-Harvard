-- Keep a log of any SQL queries you execute as you solve the mystery.
-- Theft took place on July 28 || 7/28
-- Theft took place on Humphrey Street

-- Get the description from crime scene
SELECT description FROM crime_scene_reports
WHERE month = 7 AND day = 28
AND street = "Humphrey Street"

-- Check the bakery security logs
SELECT * FROM bakery_security_logs
WHERE hour = 10 AND minute = 15

-- Check license plate
SELECT * FROM people WHERE license_plate = "11J91FW"

-- Read the interview looking for bakery in transcription
 SELECT name, transcript FROM interviews
 WHERE transcript LIKE "%bakery%"

-- Check the phone calls
SELECT * FROM phone_calls
WHERE day = 28 AND month = 7 AND duration <= 60

-- Check the atm transactions
SELECT * FROM atm_transactions
WHERE day = 28
AND month = 7
AND transaction_type = "withdraw"
AND atm_location = "Leggett Street";

-- Check the flight for the next day earliest
SELECT * FROM flights
WHERE day = 29 AND month = 7
ORDER BY hour LIMIT 1;

-- Check flight
select * from passengers where flight_id = 36;

-- Check people passport
SELECT * FROM people
WHERE passport_number
IN (
SELECT passport_number FROM passengers
WHERE flight_id = 36
)

-- Check the city flight
SELECT * FROM airports WHERE id = 4;
-- New York City

-- Check phone numbers
SELECT name FROM people
WHERE passport_number
IN (
SELECT passport_number FROM passengers
WHERE flight_id = 36
)
JOIN phone_call ON people.phone_number