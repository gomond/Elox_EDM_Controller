# Servo Relay Test Matrix (ELOX 8-2012-DR)

Use this sheet to identify the remaining relay functions with **Relay 4 (green) held active**.

## Known Mapping
- Relay 4 = Green = **Servo Enable** (confirmed)
- Relay 1 = Red = Unknown
- Relay 2 = Orange = Unknown
- Relay 3 = Yellow = Unknown

## Test Setup
- Keep machine in a safe state (no tool/work contact)
- Hold **R4 = ON** during all tests below
- Toggle only the listed relay states for R1/R2/R3
- Record observed motion and behavior

## 8-State Matrix (R4 fixed ON)

| Test | R1 (Red) | R2 (Orange) | R3 (Yellow) | R4 (Green) | Motion (Up/Down/None) | Speed/Mode Change | Other Effects (Pump/Power/Polarity/etc.) | Notes |
|------|----------|-------------|-------------|------------|------------------------|-------------------|-------------------------------------------|-------|
| T0   | 0        | 0           | 0           | 1          |                        |                   |                                           |       |
| T1   | 1        | 0           | 0           | 1          |                        |                   |                                           |       |
| T2   | 0        | 1           | 0           | 1          |                        |                   |                                           |       |
| T3   | 0        | 0           | 1           | 1          |                        |                   |                                           |       |
| T4   | 1        | 1           | 0           | 1          |                        |                   |                                           |       |
| T5   | 1        | 0           | 1           | 1          |                        |                   |                                           |       |
| T6   | 0        | 1           | 1           | 1          |                        |                   |                                           |       |
| T7   | 1        | 1           | 1           | 1          |                        |                   |                                           |       |

## Fast Identification Rules
1. The relay that reliably flips **Up ↔ Down** is the **Direction** line.
2. A relay that changes travel aggressiveness but not sign is likely **Rate/Mode**.
3. A relay that enables/disables motion only under specific states is likely **Interlock/Permission**.
4. Any relay that affects pump/power/polarity without direction change is a **non-servo auxiliary function**.

## Suggested Confirmation Pass
After identifying a probable direction relay:
- Hold R4 ON
- Hold the other two unknown relays constant
- Toggle only the probable direction relay 5–10 times
- Confirm motion sign changes consistently each time

## Result Summary (fill after testing)
- Direction relay: __________
- Secondary mode relay: __________
- Interlock/aux relay: __________
- Non-servo observations: __________________________________________
