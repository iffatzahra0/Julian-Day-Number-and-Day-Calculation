# Julian-Day-Number-and-Day-Calculation

This repository contains two C++ programs designed to calculate the **Julian Day Number (JDN)** and determine:
1. The **day of the week** for a given date.
2. The **difference in days** between two dates.

These programs are especially useful for students, programmers, or anyone interested in understanding calendar systems and basic date algorithms using the Julian/Gregorian calendars.

---

## Program 1: Day of the Week Finder

### Description
Given a date in the format `DD MM YYYY`, this program:
- Determines whether the date falls under the **Julian** or **Gregorian** calendar.
- Calculates the **Julian Day Number (JDN)**.
- Computes the **day of the week** (e.g., Monday, Tuesday, etc.).

### Key Concepts:
- Calendar transition logic (pre/post October 15, 1582)
- JDN calculation using integer math
- Mapping JDN to weekday names
