struct facArgs {
  int x;
  int y;
};

program FAC_PROG {
  version FAC_VERS {
    int calcFac(int) = 1;
    int calcMult(facArgs) = 2;
  } = 1;
} = 0x23451111;