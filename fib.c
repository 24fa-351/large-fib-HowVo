#include <stdio.h>
#include <stdlib.h>

unsigned long long recursiveFib(int val);
unsigned long long iterativeFib(int val);
unsigned long long overflowCheck(unsigned long long firstVal, unsigned long long secondVal);

unsigned long long overflowCheck(unsigned long long firstVal, unsigned long long secondVal)
{
   return firstVal <= ULLONG_MAX - secondVal;
}

unsigned long long recursiveFib(int val)
{
   if (val <= 1)
   {
      return 0;
   }

   else if (val == 2)
   {
      return 1;
   }

   unsigned long long prevNum = recursiveFib(val - 1);
   unsigned long long prevPrevNum = recursiveFib(val - 2);

   if (overflowCheck(prevPrevNum, prevNum))
   {
      return prevPrevNum + prevNum;
   }
   else
   {
      printf("Overflow at the %dth term: ", val - 1);
      return 0;
   }
}

unsigned long long iterativeFib(int val)
{
   unsigned long long prevPrevNum = 0;
   unsigned long long prevNum = 0;
   unsigned long long currentNum = 1;

   for (int i = 2; i < val; i++)
   {
      prevPrevNum = prevNum;
      prevNum = currentNum;
      if (overflowCheck(prevPrevNum, prevNum))
      {
         currentNum = prevPrevNum + prevNum;
      }
      else
      {
         printf("Overflow at the %dth term: ", i);
         break;
      }
   }

   return currentNum;
}

int main(int argc, char **argv)
{
   int input = atoi(argv[1]);
   unsigned long long output = 0;

   if (argv[2][0] == 'r')
   {
      output = recursiveFib(input);
   }

   else if (argv[2][0] == 'i')
   {
      output = iterativeFib(input);
   }
   printf("%llu\n", output);
   return 0;
}