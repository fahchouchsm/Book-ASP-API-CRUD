/* calc.x */
struct two_ints {
  int a;
  int b;
};

program CALC_PROG {
  version CALC_V1 {
    int ADD(two_ints) = 1;
  } = 1;
} = 0x31234567;
