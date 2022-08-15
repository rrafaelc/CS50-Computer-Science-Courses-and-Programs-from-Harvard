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

-- Read the interview
 SELECT name, transcript FROM interviews
 WHERE transcript LIKE "%bakery%"