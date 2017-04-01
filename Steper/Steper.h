class MStep{
  public:
  MStep(int a, int b, int c, int d);
  void MPaso(boolean dir);
  private:
  int A;
  int B;
  int C;
  int D;
  int PActual;
  int Paso [8][4] =
  {  {1, 0, 0, 0},
     {1, 1, 0, 0},
     {0, 1, 0, 0},
     {0, 1, 1, 0},
     {0, 0, 1, 0},
     {0, 0, 1, 1},
     {0, 0, 0, 1},
     {1, 0, 0, 1}
  };
};

MStep::MStep(int a, int b, int c, int d){
  A = a;
  B = b;
  C = c;
  D = d;
  PActual = 0;
  
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);

  digitalWrite(A, Paso[PActual][0]);
  digitalWrite(B, Paso[PActual][1]);
  digitalWrite(C, Paso[PActual][2]);
  digitalWrite(D, Paso[PActual][3]);
}

void MStep::MPaso(boolean dir){
  if(dir){
    PActual = (PActual + 1) % 8;
  }else{
    PActual = (PActual - 1 + 8) % 8;
  }
  digitalWrite(A, Paso[PActual][0]);
  digitalWrite(B, Paso[PActual][1]);
  digitalWrite(C, Paso[PActual][2]);
  digitalWrite(D, Paso[PActual][3]);
}
