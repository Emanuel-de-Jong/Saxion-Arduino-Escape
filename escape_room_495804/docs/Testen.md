# Testen

## Test Cases
### Simon Says
#### Geen knop ingedrukt
##### Voorbereiding
Druk op de reset knop van de Arduino en wacht ongeveer 5 seconden.

##### Tabel
| # | Actie (automaties)                                                    | Verwachte uitkomst                           | Echte uitkomst                               | Resultaat |
|---|-----------------------------------------------------------------------|----------------------------------------------|----------------------------------------------|-----------|
| 1 | Begin bij eerste kleur van sequentie                                  | Eerste kleur brand                           | Eerste kleur brand                           | Goed      |
| 2 | Wacht COLOR_TIME + BLANK_TIME milliseconden                           | LED blijft even branden en gaat dan even uit | LED blijft even branden en gaat dan even uit | Goed      |
| 3 | Ga naar volgende kleur in sequentie (herhaal tot einde van sequentie) | Volgende kleur brand                         | Volgende kleur brand                         | Goed      |
| 4 | Wacht COLOR_SEQUENCE_RESTART_TIME milliseconden                       | LED blijft even uit                          | LED blijft even uit                          | Goed      |
| 5 | Ga terug naar stap 1                                                  | Eerste kleur brand weer                      | Eerste kleur brand weer                      | Goed      |

##### Uitleg
Als er nog geen knop is gedrukt, of dit al een paar seconden niet is gebeurt, wordt automaties de kleuren sequentie in een oneindige loop laten zien. Tussen de kleuren is een korte pauze. Na de sequentie is een langere pauze.





#### Goede knoppen ingedrukt
##### Voorbereiding
Druk op de reset knop van de Arduino en wacht ongeveer 5 seconden.

##### Tabel
| # | Actie                                                   | Verwachte uitkomst                                                                                           | Echte uitkomst                                                                                              | Resultaat |
|---|---------------------------------------------------------|--------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------|-----------|
| 1 | Kijk naar de kleuren van de LED                         | De zelfde 3 kleuren worden steeds opnieuw een voor een laten zien                                            | De zelfde kleuren worden steeds opnieuw een voor een laten zien                                             | Goed      |
| 2 | Druk de bijbehorende knoppen in. In de zelfde volgorde. | De LED heeft kort een groen licht. Daarna begint de zelfde kleuren sequentie met 1 kleur meer aan het einde. | De LED heeft kort een groen licht. Daarna begint de zelfde kleren sequentie met 1 kleur meer aan het einde. | Goed      |

##### Uitleg
Als alle knoppen in de goede volgorde zijn gedrukt, begint de volgende fase. Deze heeft 1 extra kleur aan het einde.

#### Foute knop ingedrukt
##### Voorbereiding
Voer eerst test case `Goede knoppen ingedrukt` uit.

##### Tabel
| # | Actie                                                                                           | Verwachte uitkomst                                                                | Echte uitkomst                                                                    | Resultaat |
|---|-------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------|-----------------------------------------------------------------------------------|-----------|
| 1 | Kijk naar de kleuren van de LED                                                                 | De zelfde 4 kleuren worden steeds opnieuw een voor een laten zien                 | De zelfde 4 kleuren worden steeds opnieuw een voor een laten zien                 | Goed      |
| 2 | Druk een van de 3 knoppen die geen relatie hebben met het eerste licht van de kleuren sequentie | De LED heeft kort een rood licht. Daarna worden er nog maar 3 kleuren laten zien. | De LED heeft kort een rood licht. Daarna worden er nog maar 3 kleuren laten zien. | Goed      |

##### Uitleg
Als er een foute knop wordt gedrukt begint de challenge opnieuw.





#### Gehaald
##### Voorbereiding
Voer eerst test case `Goede knoppen ingedrukt` 4 keer uit.

##### Tabel
| # | Actie (automaties)                                         | Verwachte uitkomst                                                                                     | Echte uitkomst                                                                                         | Resultaat |
|---|------------------------------------------------------------|--------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------|-----------|
| 1 | Na het drukken van de laatste knop is de challenge gehaald | De LED wordt nog 1 keer groen                                                                          |                                                                                                        | Goed      |
| 2 | Het programma ziet dat de status nu op gehaald staat       | De buzzer geeft een korte piep en op het status scherm naast het Simon Says icoon staat een zwart blok | De buzzer geeft een korte piep en op het status scherm naast het Simon Says icoon staat een zwart blok | Goed      |

##### Uitleg
Het zwarte blok laat de gebruiker weten dat de challenge definitief klaar is.





### Win

### Timeout


## Test Raport