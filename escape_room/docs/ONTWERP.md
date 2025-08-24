# Ontwerp

## Dependencies
- `TM1638plus` 1.9.0 van Gavin Lyons: Om de LED & Key makkelijker te kunnen gebruiken
- `LiquidCrystal_I2C` van Frank de Brabander: Om de LCD makkelijker via een I2C verbinding te kunnen gebruiken

## Klassen Diagram
<img src="imgs/ontwerp/Class%20Diagram.jpg" width="800px"></img><br>
In `escape_room` worden de challenges, `FStatus` en een globale `Buzzer` aangemaakt. `Globals` heeft definities voor alle pinnen.

Alle challenges erven van `Challenge` die de `CHALLENGE_ID` en `IsDone` variabelen en de `setup` en `loop` methoden heeft. De challenges maken hun bijbehorende hardware klassen aan en geven deze de pin die in `globals` staat.
Sommige challenges hebben een sub klas om de code en data wat te verdelen. Zo heeft `CSafe` meerdere `CSafeStages` waarin de start en eind waardes staan van het bereik staan. Ook heeft de klas een methode `isInRange()` om te kijken of de potmeter goed staat.

`FStatus` heeft een referentie van de challenges om hun `IsDone` op te vragen, en bij een win of verlies, positief te zetten.

In `escape_room` staan de hoofd `setup` en `loop` functies. Hier worden de `setup` en `loop` methoden van de challenges en `FStatus` geroepen.

`RGB` is een data klas met een rood, groen en blauw waarde tussen de 0 en 255. `RGBLED` gebruikt deze om zijn 3 `LED`'s makkelijk aan te passen. Hier staan ook wat presets van veel gebruikte kleuren.

## Sequentie Diagram
<img src="imgs/ontwerp/Sequence%20Diagram%20-%20Safe.jpg" width="800px"></img><br>
Bij het draaien van de potmeter veranderd de analoge waarde die naar de Arduino wordt gestuurd. Deze kan gelezen worden via de bijbehorende `Potmeter` klas. De safe challenge klas (`CSafe`) leest daar de waarde en kijkt dan bij de huidige stage (`CSafeStage`) of het binnen het nodige bereik ligt. Zo ja, wordt de buzzer via de bijbehorende `Buzzer` klas aangestuurd.