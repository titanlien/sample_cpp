#include <math.h>
#include <stdio.h>
 
// Function taking a function pointer as an argument
double compute_sum(double (*funcp)(double), double lo, double hi)
{
    double  sum = 0.0;
 
    // Add values returned by the pointed-to function '*funcp'
    for (int i = 0;  i <= 100;  i++)
    {
        double  x, y;
 
        // Use the function pointer 'funcp' to invoke the function
        x = i/100.0 * (hi - lo) + lo;
        y = (*funcp)(x);
        sum += y;
    }
    return (sum/100.0);
}
 
int main(void)
{
    double  (*fp)(double);      // Function pointer
    double  sum;
 
    // Use 'sin()' as the pointed-to function
    fp = sin;
    sum = compute_sum(fp, 0.0, 1.0);
    printf("sum(sin): %f\n", sum);
 
    // Use 'cos()' as the pointed-to function
    fp = cos;
    sum = compute_sum(fp, 0.0, 1.0);
    printf("sum(cos): %f\n", sum);
    return 0;
}

// Solution using a typedef: Define a pointer to a function which is taking
// two floats and returns a float
typedef float(*pt2Func)(float, float);

// Function takes a char and returns a function pointer which is defined
// with the typedef above. <opCode> specifies which function to return
pt2Func GetPtr2(const char opCode)
{
   if(opCode == '+')
      return &Plus;
   else
      return &Minus; // default if invalid operator was passed
}


// Execute example code
void Return_A_Function_Pointer()
{
   cout << endl << "Executing 'Return_A_Function_Pointer'" << endl;

   // define a function pointer and initialize it to NULL
   float (*pt2Function)(float, float) = NULL;

   pt2Function=GetPtr1('+');   // get function pointer from function 'GetPtr1'
   cout << (*pt2Function)(2, 4) << endl;   // call function using the pointer


   pt2Function=GetPtr2('-');   // get function pointer from function 'GetPtr2'
   cout << (*pt2Function)(2, 4) << endl;   // call function using the pointer
}

// 2.8 How to Use Arrays of Function Pointers

// C ---------------------------------------------------------------------------------

// type-definition: 'pt2Function' now can be used as type
typedef int (*pt2Function)(float, char, char);

// illustrate how to work with an array of function pointers
void Array_Of_Function_Pointers()
{
   printf("\nExecuting 'Array_Of_Function_Pointers'\n");

   // define arrays and ini each element to NULL, <funcArr1> and <funcArr2> are arrays
   // with 10 pointers to functions which return an int and take a float and two char

   // first way using the typedef
   pt2Function funcArr1[10] = {NULL};

   // 2nd way directly defining the array
   int (*funcArr2[10])(float, char, char) = {NULL};


   // assign the function's address - 'DoIt' and 'DoMore' are suitable functions
   // like defined above in 2.1-4
   funcArr1[0] = funcArr2[1] = &DoIt;
   funcArr1[1] = funcArr2[0] = &DoMore;

   /* more assignments */

   // calling a function using an index to address the function pointer
   printf("%d\n", funcArr1[1](12, 'a', 'b'));         //  short form
   printf("%d\n", (*funcArr1[0])(12, 'a', 'b'));      // "correct" way of calling
   printf("%d\n", (*funcArr2[1])(56, 'a', 'b'));
   printf("%d\n", (*funcArr2[0])(34, 'a', 'b'));
}


