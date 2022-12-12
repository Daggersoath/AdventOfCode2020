#include "Day1.hpp"
#include "Day2.hpp"
#include "Day3.hpp"
#include "Day4.hpp"
#include "Day5.hpp"
#include "Day6.hpp"
#include "Day7.hpp"
#include "Day8.hpp"
#include "Day9.hpp"
#include "Day10.hpp"
#include "Day11.hpp"
#include "Day12.hpp"
#include "Day13.hpp"
#include "Day14.hpp"
#include "Day15.hpp"
#include "Day16.hpp"
#include "Day17.hpp"
#include "Day18.hpp"
#include "Day19.hpp"
#include "Day20.hpp"
#include "Day21.hpp"
#include "Day22.hpp"
#include "Day23.hpp"
#include "Day24.hpp"
#include "Day25.hpp"

#define RUN_DAY(day, res1, res2) Day##day d##day;\
    d##day.Run("Input/Day"#day"_Input.txt");\
    std::string_view d##day##ExpectedResults[]{res1, res2};\
    d##day.Verify(d##day##ExpectedResults);

#define RUN_DAY_TEST(day, res1, res2) Day##day d##day;\
    d##day.Run("Input/TestInput.txt");\
    std::string_view d##day##ExpectedResults[]{res1, res2};\
    d##day.Verify(d##day##ExpectedResults);

int main()
{
    RUN_DAY(1, "69883", "207576");
    RUN_DAY(2, "12156", "10835");
    RUN_DAY(3, "7581", "2525");
    RUN_DAY(4, "453", "919");
    RUN_DAY(5, "ZWHVFWQWW", "HZFZCCWWV");
    RUN_DAY(6, "1140", "3495");
    RUN_DAY(7, "1770595", "2195372");
    RUN_DAY_TEST(8, "", "");

    return 0;
}