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


-----


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


-----


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


-----


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


-----


### Meerdere challenges tergelijk
##### Voorbereiding
Druk op de reset knop van de Arduino en wacht ongeveer 5 seconden. Kies bij de eerste 4 stappen zelf uit in welke volgorde je ze volgt.

##### Tabel
| # | Actie                                                                                      | Verwachte uitkomst                                       | Echte uitkomst                                           | Resultaat |
|---|--------------------------------------------------------------------------------------------|----------------------------------------------------------|----------------------------------------------------------|-----------|
| 1 | Draai aan de potmeter tot je de derde hoogste toon hoort. Wacht 2 seconden.                | Na 2 seconden gaat de toon uit                           | Na 2 seconden gaat de toon uit                           | Goed      |
| 1 | Druk bij de LED & Key twee keer op knop 5                                                  | De LEDs links boven gaan uit                             | De LEDs links boven gaan uit                             | Goed      |
| 1 | Voer test case Simon Says "Goede knoppen ingedrukt" uit. Sla hierbij de voorbereiding over | De LED is kort groen                                     | De LED is kort groen                                     | Goed      |
| 1 | Bij de challenge Reaction Time, Druk de knop als een van de de rode LEDs brand             | De rode LED knippert een paar keer                       | De rode LED knippert een paar keer                       | Goed      |
| 2 | Kijk naar het scherm                                                                       | De tijd loopt en alle status vakjes zijn nog leeg        | De tijd loopt en alle status vakjes zijn nog leeg        | Goed      |
| 3 | Druk bij de LED & Key vijf keer op knop 8                                                  | De LEDs rechts boven gaan uit en je hoort een korte piep | De LEDS rechts boven gaan uit en je hoort een korte piep | Goed      |

##### Uitleg
We testen hier of de challenges afzondelijk en asynchroon werken. Met de eerste 4 stappen worden de challenges op een half afgemaakte stand gezet. Stap 2 en 3 testen of alles nog werkt zoals verwacht.


-----


### Win
##### Voorbereiding
Haal alle challenges.

##### Tabel
| # | Actie                                                          | Verwachte uitkomst                                                        | Echte uitkomst                        | Resultaat |
|---|----------------------------------------------------------------|---------------------------------------------------------------------------|---------------------------------------|-----------|
| 1 | De buzzer speelt de win melodie af                             | Je hoort de melodie                                                       | Je hoort de melodie                   | Goed      |
| 2 | Het scherm laat een tekst zien                                 | Op het scherm staat: "YOU WIN!!!"                                         | Op het scherm staat: "YOU WIN!!!"     | Goed      |
| 3 | Het scherm laat de score zien                                  | Op het scherm staat: "SCORE: x/180" waarbij x de overgebleven seconden is | Op het scherm staat: "SCORE: 126/180" | Goed      |
| 4 | Druk op wat knoppen van de challenges en draai aan de potmeter | Er gebeurt niets                                                          | Er gebeurt niets                      | Goed      |

##### Uitleg
De melodie laat de gebruiker weten dat hij/zij heeft gewonnen. Voor de zekerheid worden alle challenges uit gezet bij het winnen. Stap 4 test dit.


-----


### Timeout
##### Voorbereiding
Wacht tot de timer op het scherm op 0 staat.

##### Tabel
| # | Actie                                                          | Verwachte uitkomst                 | Echte uitkomst                     | Resultaat |
|---|----------------------------------------------------------------|------------------------------------|------------------------------------|-----------|
| 1 | De buzzer speelt de timeout melodie af                         | Je hoort 5 piepen                  | Je hoort 5 piepen                  | Goed      |
| 2 | Het scherm laat een tekst zien                                 | Op het scherm staat: "YOU LOSE!!!" | Op het scherm staat: "YOU LOSE!!!" | Goed      |
| 3 | Druk op wat knoppen van de challenges en draai aan de potmeter | Er gebeurt niets                   | Er gebeurt niets                   | Goed      |

##### Uitleg
De piepen laten de gebruiker weten dat hij/zij heeft verloren. Voor de zekerheid worden alle challenges uit gezet bij een timeout. Stap 4 test dit.





## Test Rapport
Zoals te zien aan de test cases, is alles uit eindelijk gegaan zoals verwacht. Ik heb ook veel dingen buiten de test cases getest.
Het is niet mogelijk om vals te spelen zonder de draden aan te raken. Bij het 5+ keer halen en 3 keer verliesen van de laatste versie van de escape room heb ik geen problemen gevinden. Vrienden en familie hebben ook niets gevonden.
