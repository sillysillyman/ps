#include <cmath>
#include <iostream>

using namespace std;

double compute_e(double dewpoint) {
  return 6.11 * exp(5417.7530 * ((1 / 273.16) - (1 / (dewpoint + 273.16))));
}

double compute_humidex(double temperature, double e) {
  return temperature + 0.5555 * (e - 10.0);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  char type1, type2;
  double val1, val2;

  while (true) {
    cin >> type1;
    if (type1 == 'E') break;
    cin >> val1 >> type2 >> val2;

    double temperature, dewpoint, humidex;

    if (type1 == 'T' && type2 == 'D') {
      temperature = val1;
      dewpoint = val2;
      humidex = compute_humidex(temperature, compute_e(dewpoint));
    } else if (type1 == 'D' && type2 == 'T') {
      dewpoint = val1;
      temperature = val2;
      humidex = compute_humidex(temperature, compute_e(dewpoint));
    } else if (type1 == 'T' && type2 == 'H') {
      temperature = val1;
      humidex = val2;
      dewpoint = 1 / ((1 / 273.16) -
                      log(((humidex - temperature) / 0.5555 + 10.0) / 6.11) /
                          5417.7530) -
                 273.16;
    } else if (type1 == 'H' && type2 == 'T') {
      humidex = val1;
      temperature = val2;
      dewpoint = 1 / ((1 / 273.16) -
                      log(((humidex - temperature) / 0.5555 + 10.0) / 6.11) /
                          5417.7530) -
                 273.16;
    } else if (type1 == 'D' && type2 == 'H') {
      dewpoint = val1;
      humidex = val2;
      temperature = humidex - 0.5555 * (compute_e(dewpoint) - 10.0);
    } else if (type1 == 'H' && type2 == 'D') {
      humidex = val1;
      dewpoint = val2;
      temperature = humidex - 0.5555 * (compute_e(dewpoint) - 10.0);
    }

    cout << fixed;
    cout.precision(1);
    cout << "T " << temperature << " D " << dewpoint << " H " << humidex
         << '\n';
  }
}