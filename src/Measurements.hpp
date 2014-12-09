#ifndef MEASUREMENTS_HPP
#define MEASUREMENTS_HPP

#include <ratio>
#include <ostream>

namespace measurements {

namespace factors {

    typedef std::ratio<1, 1> normal;
    typedef std::ratio<5, 1> tsp_gram;
    typedef std::ratio<15, 1> tbsp_gram;
    typedef std::ratio<5, 16> pinch_gram;
    typedef std::ratio<236588, 1000> cup_gram;

    typedef std::ratio<3696, 1000> dash_millilitre;
    typedef std::ratio<5, 1> tsp_millilitre;
    typedef std::ratio<15, 1> tbsp_millilitre;
    typedef std::ratio<29573, 1000> ounce_millilitre;
    typedef std::ratio<236588, 1000> cup_millilitre;
    typedef std::ratio<473176, 1000> pint_millilitre;
    typedef std::ratio<946325, 1000> quart_millilitre;
    typedef std::ratio<3785411, 1000> gallon_millilitre;

} // namespace factors

// Our Type system
template <int mL, int G, int P>
struct Unit {
    enum { ml = mL, g = G, p = P };
};

template <typename Unit, class Ratio>
struct Value {
    double val;

    constexpr double value() const
    {
        return Ratio::num * val / Ratio::den;
    }

    constexpr static Unit unit = {};

    explicit constexpr Value(double d) : val(d) {}
};

template <int mL, int G, int P>
std::ostream &operator << (std::ostream &os, Unit<mL, G, P>) {
    return os << "mL^" << mL << " g^" << G << " ea.^" << P;
}

// Dimensions/Units
using Grams = Unit<0, 1, 0>;
using Millilitres = Unit<1,0,0>;
using Each = Unit<0,0,1>;

namespace dry {

using Weight = Value<Grams, factors::normal>;
using Teaspoon = Value<Grams, factors::tsp_gram>;
using Tablespoon = Value<Grams, factors::tbsp_gram>;
using Pinch = Value<Grams, factors::pinch_gram>;
using Cup = Value<Grams, factors::cup_gram>;

/**
 * Literal for gram (g)
 *
 * @param long double d
 * @return Weight
 */
constexpr Weight operator "" _g(long double d)
{
    return Weight(d);
}

/**
 * Literal for teaspoon (tsp)
 *
 * @param long double d
 * @return Teaspoon
 */
constexpr Teaspoon operator "" _tsp(long double d)
{
    return Teaspoon(d);
}

/**
 * Literal for tablespoon (tbsp)
 *
 * @param long double d
 * @return Tablespoon
 */
constexpr Tablespoon operator "" _tbsp(long double d)
{
    return Tablespoon(d);
}

/**
 * Literal for pinch (pinch/pinches)
 *
 * @param long double d
 * @return Pinch
 */
constexpr Pinch operator "" _pinch(long double d)
{
    return Pinch(d);
}

/**
 * Literal for cup (cup/cups)
 *
 * @param long double d
 * @return Cup
 */
constexpr Cup operator "" _cup(long double d)
{
    return Cup(d);
}

/**
 * Inserts Weight to ostream object
 *
 * @param std::ostream& os
 * @param Weight& weight
 * @return std::ostream&
 */
std::ostream &operator << (std::ostream &os, const Weight &weight)
{
    return os << weight.val << "g";
}

/**
 * Inserts Teaspoon to ostream object
 *
 * @param std::ostream& os
 * @param Teaspoon tsp
 * @return std::ostream&
 */
std::ostream &operator << (std::ostream &os, const Teaspoon &tsp)
{
    return os << tsp.val << "tsp";
}

/**
 * Inserts Tablespoon to ostream object
 *
 * @param std::ostream& os
 * @param Tablespoon tbsp
 * @return std::ostream&
 */
std::ostream &operator << (std::ostream &os, const Tablespoon &tbsp)
{
    return os << tbsp.val << "tbsp";
}

/**
 * Inserts Pinch to ostream object
 *
 * @param std::ostream& os
 * @param Pinch tbsp
 * @return std::ostream&
 */
std::ostream &operator << (std::ostream &os, const Pinch &pinch)
{
    return os << pinch.val << (pinch.val > 1 ? "pinch" : "pinches");
}

/**
 * Inserts Cup to ostream object
 *
 * @param std::ostream& os
 * @param Cup cup
 * @return std::ostream&
 */
std::ostream &operator << (std::ostream &os, const Cup &cup)
{
    return os << cup.val << (cup.val > 1 ? "cup" : "cups");
}

} // namespace dry

namespace wet {

using Dash = Value<Millilitres, factors::dash_millilitre>;
using Teaspoon = Value<Millilitres, factors::tsp_millilitre>;
using Tablespoon = Value<Millilitres, factors::tbsp_millilitre>;
using Ounce = Value<Millilitres, factors::ounce_millilitre>; 
using Cup = Value<Millilitres, factors::cup_millilitre>;
using Pint = Value<Millilitres, factors::pint_millilitre>;
using Quart = Value<Millilitres, factors::quart_millilitre>;
using Gallon = Value<Millilitres, factors::gallon_millilitre>;

/**
 * Literal for dash (dash/dashes)
 *
 * @param long double d
 * @return Dash
 */
constexpr Dash operator "" _dash(long double d)
{
    return Dash(d);
}

/**
 * Literal for teaspoon (tsp)
 *
 * @param long double d
 * @return Teaspoon
 */
constexpr Teaspoon operator "" _tsp(long double d)
{
    return Teaspoon(d);
}

/**
 * Literal for tablespoon (tbsp)
 *
 * @param long double d
 * @return Tablespoon
 */
constexpr Tablespoon operator "" _tbsp(long double d)
{
    return Tablespoon(d);
}

/**
 * Literal for ounce (ounce/ounces)
 *
 * @param long double d
 * @return Ounce
 */
constexpr Ounce operator "" _ounce(long double d)
{
    return Ounce(d);
}

/**
 * Literal for cup (cup/cups)
 *
 * @param long double d
 * @return Cup
 */
constexpr Cup operator "" _cup(long double d)
{
    return Cup(d);
}

/**
 * Literal for Pint (pint)
 *
 * @param long double d
 * @return Pint
 */
constexpr Pint operator "" _pint(long double d)
{
    return Pint(d);
}

/**
 * Literal for Quart (quart)
 *
 * @param long double d
 * @return Quart
 */
constexpr Quart operator "" _quart(long double d)
{
    return Quart(d);
}

/**
 * Literal for Gallon (gallon)
 *
 * @param long double d
 * @return Gallon
 */
constexpr Gallon operator "" _gallon(long double d)
{
    return Gallon(d);
}

/**
 * Inserts Dash to ostream object
 *
 * @param std::ostream& os
 * @param Dash dash
 * @return std::ostream&
 */
std::ostream &operator << (std::ostream &os, const Dash &dash)
{
    return os << dash.val << (dash.val > 1 ? "dash" : "dashes");
}

/**
 * Inserts Teaspoon to ostream object
 *
 * @param std::ostream& os
 * @param Teaspoon tsp
 * @return std::ostream&
 */
std::ostream &operator << (std::ostream &os, const Teaspoon &tsp)
{
    return os << tsp.val << "tsp";
}

/**
 * Inserts Tablespoon to ostream object
 *
 * @param std::ostream& os
 * @param Tablespoon tbsp
 * @return std::ostream&
 */
std::ostream &operator << (std::ostream &os, const Tablespoon &tbsp)
{
    return os << tbsp.val << "tbsp";
}

/**
 * Inserts Ounce to ostream object
 *
 * @param std::ostream& os
 * @param Ounce ounce
 * @return std::ostream&
 */
std::ostream &operator << (std::ostream &os, const Ounce &ounce)
{
    return os << ounce.val << (ounce.val > 1 ? "ounce" : "ounces");
}

/**
 * Inserts Cup to ostream object
 *
 * @param std::ostream& os
 * @param Cup cup
 * @return std::ostream&
 */
std::ostream &operator << (std::ostream &os, const Cup &cup)
{
    return os << cup.val << (cup.val > 1 ? "cup" : "cups");
}

/**
 * Inserts Pint to ostream object
 *
 * @param std::ostream& os
 * @param Pint pint
 * @return std::ostream&
 */
std::ostream &operator << (std::ostream &os, const Pint &pint)
{
    return os << pint.val << (pint.val > 1 ? "pint" : "pints");
}

/**
 * Inserts Quart to ostream object
 *
 * @param std::ostream& os
 * @param Quart quart
 * @return std::ostream&
 */
std::ostream &operator << (std::ostream &os, const Quart &quart)
{
    return os << quart.val << (quart.val > 1 ? "quart" : "quarts");
}

/**
 * Inserts Gallon to ostream object
 *
 * @param std::ostream& os
 * @param Gallon gallon
 * @return std::ostream&
 */
std::ostream &operator << (std::ostream &os, const Gallon &gallon)
{
    return os << gallon.val << (gallon.val > 1 ? "gallon" : "gallons");
}

} // namespace wet

} // namespace measurments

#endif /* MEASUREMENTS_HPP */
