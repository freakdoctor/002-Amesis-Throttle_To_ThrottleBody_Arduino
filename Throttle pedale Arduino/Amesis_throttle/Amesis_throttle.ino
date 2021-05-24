/* Amesis Project
    ^ ^
  =( '' )=
  (")_(")
  Youtube   : https://www.youtube.com/channel/UCCexVZN3UYSep2lsj2jVjdg?sub_confirmation=1
  GitHub    : https://github.com/AmesisProject
  Discord   : https://discord.gg/vRAybmd3hk
  FaceBook  : https://www.facebook.com/amesis.pro.5
  Instagram : https://www.instagram.com/?hl=fr

  licence OpenSource non comercialisable, modifiable en citant le propriétaire AmesisProject avec l'un des liens ci dessus
  Sur base de l'exmple arduino AnalogInOutSerial

  NomDuProjet : Amesis_throttle
  Version     : v1.0 18/05/2021
  ButDuProjet : Renvoyer la valeur de la pédale (du groupe VAG "VR5 AQN" de 0 à 100 % sur le port serie.
  ProjetDisponibleIciGitHub : https://github.com/AmesisProject/002-Amesis-Throttle_To_ThrottleBody_Arduino/tree/main/Throttle%20pedale%20Arduino
  Merci de faire suivre sur github toute modification ou amélioration du code.
  Branchement :
  Pedale   /  Calculateur   /   ArduinoMega
  1           72               5v
  2           -                -
  3           -                -
  4           -                -
  5           33               Gnd
  6           34               A0


  Papillon   /  Calculateur   /   ArduinoMega
  1             92                A1
  2             83                5v
  3             117               -
  4             84                -
  5             118               -
  6             34                Gnd

*/
//////////////////////////////
// Déclaration des variable //
//////////////////////////////

const int pedalePin = A0;             // Pin analogique d'enté (input) du potentiometre

const int papPin = A1;           // Pin capteur de position papillon 1

int pap = 0;                    // lire la valeur du potentiometre
int papValeur = 0;              // valeur entre 0 et 100%

int pedale = 0;                 // lire la valeur du potentiometre
int pedaleValeur = 0;           // valeur entre 0 et 100%



///////////////////////////////
//Initialisation du l'arduino//
///////////////////////////////

void setup() {
  // initialisation du port serie a 9600 bps:
  Serial.begin(9600);
}

///////////////////////////////////
//Programme en bloucle du projet //
///////////////////////////////////

void loop() {
  // Lectue de la valeur analogique:
  pedale = analogRead(pedalePin);
  pap = analogRead(papPin);

  // Fonction "map" de mise à l'echelle : le 70 et 474 sont les valeur de ma pédale, il se peut que d'autres pédales aient des valeurs differentes. Pour les trouver, remplacer les valeurs "pedaleValeur = map(pedale, X, Y, 0, 100);" X et Y par X = 0 et Y = 1023 et controlez votre debut/fin de course de votre pédale, vous trouverez votre propre X et Y
  pedaleValeur = map(pedale, 70, 470, 0, 100);
  papValeur = map(pap, 98, 963, 0, 100);

  // On renvoie les info sur le port serie pour la console arduino

  Serial.print("Position de la pedale est à = ");
  Serial.print(pedaleValeur);
  Serial.println("%");

  Serial.print("Position du capteur de papillon 1 est à = ");
  Serial.print(papValeur);
  Serial.println("%");

  // On attend 2 milisecondes pour que notre montage soit stable (Passé à 1 seconde pour une meilleure lecture)
  //delay(2);
  delay(1000);
}
