-- destination airport id is 4, origin is 8
SELECT name
FROM poeple
WHERE passport_number IN(SELECT passport_number
    FROM passengers
    WHERE flight_id = (SELECT id
        FROM flights
        WHERE month=7 AND day=29 AND origin_airport_id=8 AND destination_airport_id=4));
-- 8 people are on flight from id 8 to id 4 AND one of them is thief:
-- Kenny, Sofia, Taylor, Luca, Kelsey, Edward, Bruce, Doris
-- lets check withdraws and match the names
SELECT name
FROM people
WHERE id IN(SELECT person_id
    FROM bank_accounts
    WHERE account_number IN(SELECT account_number
        FROM atm_transactions
        WHERE year=2021 AND month=7 AND day=28 AND transaction_type="withdraw" AND atm_location="Leggett Street"));
-- There is 8 people who withdrawed money:
-- Kenny, Iman, Benista, Taylor, Brooke, Luca, Diana, Bruce
-- Kenny, Taylor, Luca, Bruce matches
SELECT name
FROM poeple
WHERE license_plate IN(SELECT license_plate
    FROM bakery_security_logs
    WHERE year=2021 AND month=7 AND day=28 AND activity="entrance" AND hour<=11)
ORDER BY name;
-- We got names of people in bakery, now let's compare to our big four
