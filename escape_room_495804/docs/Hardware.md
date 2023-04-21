# Hardware
Alle ground is met elkaar verbonden. De lijnen voor 5V (boven) en 3.3V (onder) zijn op de bovenste breadboard te vinden.
De knoppen voor Simon Says en Reaction Time zijn niet verbonden aan 3.3V om kabels te besparen.
De data kabels voor alle challenges behalve Simon Says hebben een extensie via de bovenste breadboard omdat ze anders te kort of krap zouden zijn.
Je hebt misschien gezien dat er bij Reaction Time wat extra kabels zijn. Het was de bedoeling dat er 5 LEDS zouden zijn. Helaas had ik niet genoeg 220 ohm resistors en heb ik tot nu toe nog geen kunnen vinden.

## Fotos
<img src="imgs/hardware/1.1%20Top.jpg" width="800px"></img><br>
<img src="imgs/hardware/1.2%20Front.jpg" width="800px"></img><br>
<img src="imgs/hardware/1.3%20Left.jpg" width="800px"></img><br>
<img src="imgs/hardware/1.4%20Right.jpg" width="800px"></img><br>
<img src="imgs/hardware/1.5%20Back.jpg" width="800px"></img><br>
<img src="imgs/hardware/2.1%20Arduino%20Left.jpg" width="800px"></img><br>
<img src="imgs/hardware/2.2%20Arduino%20Right.jpg" width="800px"></img><br>

## Pin Mapping
| Pins |      Beschrijving     |     Pins     |    Beschrijving    |
|:----:|:---------------------:|:------------:|:------------------:|
|      |                       |      SCL/D15 | I2C                |
|      |                       |      SDA/D14 | I2C                |
|      |                       |      SCK/D13 | Buzzer             |
|      |                       |     MISO/D12 | LEDKey strobe      |
|      |                       | PWM/MOSI/D11 | LEDKey clock       |
|      |                       |   PWM/CS/D10 | LEDKey dio         |
|      |                       |       PWM/D9 | Simon RGBLED blauw |
|      |                       |           D8 | Simon knop blauw   |
|      |                       |           D7 | Simon knop geel    |
|      |                       |       PWM/D6 | Simon RGBLED groen |
|   A0 | Potmeter              |       PWM/D5 | Simon RGBLED rood  |
|   A1 | React LED rood links  |           D4 | Simon knop rood    |
|   A2 | React LED groen       |       PWM/D3 | React knop         |
|   A3 | React LED rood rechts |           D2 | Simon knop groen   |
|   A4 |                       |        TX/D1 |                    |
|   A5 |                       |        RX/D0 |                    |
