#include "Day1.hpp"
#include "Day2.hpp"
#include "Day3.hpp"
#include "Day4.hpp"
#include "Day5.hpp"
#include "Day6.hpp"

#define RUN_DAY(day, res1, res2) Day##day d##day;\
    d##day.Run("Input/Day"#day"_Input.txt");\
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

    return 0;
}