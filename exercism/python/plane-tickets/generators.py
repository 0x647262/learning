"""Functions to automate Conda airlines ticketing system."""

from itertools import count, cycle
from typing import Iterable


def generate_seat_letters(number: int) -> Iterable[str]:
    """Generate a series of letters for airline seats.

    :param number: int - total number of seat letters to be generated.
    :return: generator - generator that yields seat letters.

    Seat letters are generated from A to D.
    After D it should start again with A.

    Example: A, B, C, D

    """

    cycled = cycle("ABCD")
    for _ in range(number):
        yield next(cycled)


def generate_seats(number: int) -> Iterable[str]:
    """Generate a series of identifiers for airline seats.

    :param number: int - total number of seats to be generated.
    :return: generator - generator that yields seat numbers.

    A seat number consists of the row number and the seat letter.

    There is no row 13.
    Each row has 4 seats.

    Seats should be sorted from low to high.

    Example: 3C, 3D, 4A, 4B

    """

    rows = (r for r in count(1) if r != 13 for _ in range(4))
    letters = generate_seat_letters(number)
    for row, letter in zip(rows, letters):
        yield f"{row}{letter}"


def assign_seats(passengers: list[str]) -> dict[str, str]:
    """Assign seats to passengers.

    :param passengers: list[str] - a list of strings containing names of
                                   passengers.
    :return: dict - with the names of the passengers as keys and seat numbers
                    as values.

    Example output: {"Adele": "1A", "Björk": "1B"}

    """

    return dict(zip(passengers, generate_seats(len(passengers))))


def generate_codes(seat_numbers: list[str], flight_id: str) -> Iterable[str]:
    """Generate codes for a ticket.

    :param seat_numbers: list[str] - list of seat numbers.
    :param flight_id: str - string containing the flight identifier.
    :return: generator - generator that yields 12 character long ticket codes.

    """

    for seat_number in seat_numbers:
        yield f"{seat_number}{flight_id}".ljust(12, "0")
