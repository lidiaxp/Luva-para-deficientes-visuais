long distancia;                                                                                                                                                                                                                                               long tempo;
int maiord = 40;
int menord = 0;
int bot = 5;
int estbot = 0;
int buz = 4;
 
void setup() {
  pinMode(9, OUTPUT);                   //9 é onde liga o trlg do sensor ultrassônico
  pinMode(8, INPUT);                    //8 é onde liga o echo do sensor ultrassônico
  pinMode(buz, OUTPUT);
  pinMode(bot,INPUT);
}
 
void loop() {
  enxergar();
  checadistancia();
  alterardistancia();
}
 
void enxergar() {
  digitalWrite(9, LOW);
  delayMicroseconds(5);
  digitalWrite(9, HIGH);
  delayMicroseconds(10);
}
 
void checadistancia() {
  distancia = int(0.017 * tempo);
  if (distancia < maiord && distancia > menord) {
    digitalWrite(buz,HIGH);
  } else {
    digitalWrite(buz,LOW);
  }
}
 
void alterardistancia() {
  estbot = digitalRead(bot);
  if(estbot == HIGH){
    maiord += 50;
    menord +=50;
    if(maiord >= 191){
      maiord = 40;
      menord = 0;
    }
  }
}
