#include <iostream>

#include <cmath>


class Underprimes {
public:
  int howMany(int A, int B);

private:
  int factorize(int n);

private:
  bool is_prime_[100000 + 1];
};

int Underprimes::howMany(int A, int B)
{
  is_prime_[0] = is_prime_[1] = false;
  is_prime_[2] = is_prime_[3] = true;

  for (int i = 4; i < 100000 + 1; i ++)
    if (i % 2 == 0) {
      is_prime_[i] = false;
    }
    else {
      is_prime_[i] = true;

      for (int j = 3; j <= sqrt(i) + 0.5; j ++)
	if (i % j == 0) {
	  is_prime_[i] = false;
	  break;
	}
    }

  int c = 0;

  for (int i = A; i <= B; i ++) {
    int factors = factorize(i);

    if (is_prime_[factors])
      c ++;
  }

  return c;
}

int Underprimes::factorize(int n)
{
  int c = 0;

  for (int i = 2; n > 1, n <= i, i <= 100000; )
    if (n % i == 0) {
      n /= i;
      c ++;
      continue;
    }
    else {
      i ++;
    }

  return c;
}


int main(int argc, char** argv)
{
  int A, B;

  std::cin >> A >> B;

  std::cout << Underprimes().howMany(A, B) << std::endl;
}
