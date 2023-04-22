# Ontwerp

## Sequentie Diagrammen
<img src="imgs/ontwerp/Sequence%20Diagram%20-%20Safe.jpg" width="800px"></img><br>
Bij het draaien van de potmeter veranderd de analoge waarde die naar de arduino wordt gestuurd. Deze kan gelezen worden via de bijbehorende potmeter klas. De safe challenge klas leest daar de waarde en kijkt dan bij de huidige stage of het binnen het nodige bereik ligt. Zo ja, wordt de buzzer via de bijbehorende buzzer klas aangestuurd.