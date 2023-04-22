# Testen

## Test Cases
### Simon Says
#### Geen knop ingedrukt
| # | Actie (automaties)                                                    | Verwachte uitkomst                           | Echte uitkomst                               | Resultaat |
|---|-----------------------------------------------------------------------|----------------------------------------------|----------------------------------------------|-----------|
| 1 | Begin bij eerste kleur van sequentie                                  | Eerste kleur brand                           | Eerste kleur brand                           | Goed      |
| 2 | Wacht COLOR_TIME + BLANK_TIME milliseconden                           | LED blijft even branden en gaat dan even uit | LED blijft even branden en gaat dan even uit | Goed      |
| 3 | Ga naar volgende kleur in sequentie (herhaal tot einde van sequentie) | Volgende kleur brand                         | Volgende kleur brand                         | Goed      |
| 4 | Wacht COLOR_SEQUENCE_RESTART_TIME milliseconden                       | LED blijft even uit                          | LED blijft even uit                          | Goed      |
| 5 | Ga terug naar stap 1                                                  | Eerste kleur brand weer                      | Eerste kleur brand weer                      | Goed      |

#### Goede knop ingedrukt
#### Foute knop ingedrukt
#### Gehaald

### Win

### Timeout


## Test Raport