#include "Days/Day1.hpp"
#include "Days/Day2.hpp"
#include "Days/Day3.hpp"
#include "Days/Day4.hpp"
#include "Days/Day5.hpp"
#include "Days/Day6.hpp"
#include "Days/Day7.hpp"
#include "Days/Day8.hpp"
#include "Days/Day9.hpp"
#include "Days/Day10.hpp"
#include "Days/Day11.hpp"
#include "Days/Day12.hpp"
#include "Days/Day13.hpp"
#include "Days/Day14.hpp"
#include "Days/Day15.hpp"
#include "Days/Day16.hpp"
#include "Days/Day17.hpp"
#include "Days/Day18.hpp"
#include "Days/Day19.hpp"
#include "Days/Day20.hpp"
#include "Days/Day21.hpp"
#include "Days/Day22.hpp"
#include "Days/Day23.hpp"
#include "Days/Day24.hpp"
#include "Days/Day25.hpp"

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
    RUN_DAY(8, "1816", "383520");

    return 0;
}