-- Keep a log of any SQL queries you execute as you solve the mystery.
-- after checking .schema crime_scene_reports we need to know the details of crime
SELECT id, year, month, day, street, description
FROM crime_scene_reports
WHERE description LIKE "%CS50%";
-- id 295, year 2021, month 7, day 28, hour 10, minute 50, street Humphrey Street in bakery. Interviewed 3 witnesses same day
SELECT id, hour, minute, activity, license_plate
FROM bakery_security_logs
WHERE month = 7 AND day = 28 AND hour >= 10;
-- we got number of suspicious people so lets check interviews
SELECT id, name, transcript
FROM interviews
WHERE year = 2021 AND month = 7 AND day = 28;
-- Witnesses:
-- Ruth - around 10min thief get into a car in bakery parking,
-- Eugene - before she arrived at Emma's bakery saw thief withdrawing some money from ATM on Leggett Street,
-- Raymond - thief is going to fly 2021/07/28 earliest plane and asked other person to buy a ticket(talking while robbery 10:50am)
SELECT id, account_number, amount
FROM atm_transactions
WHERE year = 2021 AND month = 7 AND day = 28 AND transaction_type = "withdraw" AND atm_location = "Leggett Street";
-- We got 8 withdraws from this ATM for amounts 48, 20, 60, 50, 80, 20, 30, 35
SELECT caller, receiver FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60;
-- We got 9 calls
SELECT full_name FROM airports WHERE city = "Fiftyville";
-- FIftyville Regional Airport
SELECT destination_airport_id, hour FROM flights WHERE year = 2021 AND month = 7 AND day = 29;
-- The earliest flight is at 8AM and destination_airport_id is 4, Fiftyville id is 8
SELECT full_name, city FROM airports WHERE id = 4;
-- LaGuardia Airport, NYC
SELECT person_id FROM bank_accounts WHERE account_number IN(SELECT account_number FROM atm_transactions WHERE year=2021 AND month=7 AND day=28 AND transaction_type="withdraw" AND atm_location="Leggett Street");
-- We got 6 person id which references people id
SELECT name FROM people WHERE id IN(SELECT person_id FROM bank_accounts WHERE account_number IN(SELECT account_number FROM atm_transactions WHERE year=2021 AND month=7 AND day=28 AND transaction_type="withdraw" AND atm_location="Leggett Street"));
-- We got only Bruce mathing, Bruce number 367 555-5533