#include <iostream>
#include "Measurements.hpp"

using namespace std;

int main()
{
    {
        using namespace measurements::dry;
        Teaspoon required_sugar = 2._tsp;

        cout << "Required sugar (g) " << required_sugar.value() << " " << required_sugar.unit << endl
         << "      or     (tsp) " << required_sugar << endl;
    }

    {
        using namespace measurements::wet;
        Teaspoon required_honey = 6._tsp;
        cout << "Required honey (mL) " << required_honey.value() << " " << required_honey.unit << endl
         << "      or      (tsp) " << required_honey << endl;
    }

    return 0;
}
