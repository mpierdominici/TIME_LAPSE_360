class MStep{
  public:
  MStep(int a, int b, int c, int d);
  void MPaso(boolean dir);
  private:
  int A_;
  int B_;
  int C_;
  int D_;
  int PActual;
  int Paso [8][4] =
  {{1, 0, 0, 0},
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
  A_ = a;
  B_ = b;
  C_ = c;
  D_ = d;
  PActual = 0;

  pinMode(A_, OUTPUT);
  pinMode(B_, OUTPUT);
  pinMode(C_, OUTPUT);
  pinMode(D_, OUTPUT);

  digitalWrite(A_, Paso[PActual][0]);
  digitalWrite(B_, Paso[PActual][1]);
  digitalWrite(C_, Paso[PActual][2]);
  digitalWrite(D_, Paso[PActual][3]);
}

void MStep::MPaso(boolean dir){
  if(dir){
    PActual = (PActual + 1) % 8;
  }else{
    PActual = (PActual - 1 + 8) % 8;
  }
  digitalWrite(A_, Paso[PActual][0]);
  digitalWrite(B_, Paso[PActual][1]);
  digitalWrite(C_, Paso[PActual][2]);
  digitalWrite(D_, Paso[PActual][3]);
}
