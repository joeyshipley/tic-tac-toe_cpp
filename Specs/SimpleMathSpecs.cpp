#include <igloo/igloo.h>
using namespace igloo;

#include "SimpleMath.h"

Context(WhenAdding8And12)
{
  Spec(ItReturns20)
  {
    SimpleMath math;
    int result = math.Add(8, 12);
    Assert::That(result, Is().EqualTo(20));
  } 
};