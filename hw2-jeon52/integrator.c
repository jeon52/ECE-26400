#include "hw2.h"
double integrate1(Range rng)
{
    //local variables
    double answer;
    int count;

    //Statements
    for (count = 0; count < rng.intervals; count++)
    {
        if (count == 0)
        {
            answer = func(rng.lowerlimit);
        }
        else
        {
            answer += func(rng.lowerlimit + count * (rng.upperlimit - rng.lowerlimit) / rng.intervals);
        }
    }
    answer *= ((rng.upperlimit - rng.lowerlimit) / rng.intervals);
    return(answer);
}

void integrate2(RangeAnswer * rngans)
{
    //local variables
    
    //Statements
    rngans -> answer = integrate1((* rngans).rng);
}
