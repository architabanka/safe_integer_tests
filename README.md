# Safe Integer Test Suite

## Brief description
Each case has 4 fields : type1, type2, result, operation.
Cases are grouped based on type1/2 and operation into a *suite*.
The files mult/add/div/cast.cc fetch all cases with the corresponding operation and run them.

## How to add test cases
1. add your test cases in `safe_numerics_test/cases.h`. 
2. If you add a case with new types make sure to do the following:
    - define the `TestSuite` constructor if you are testing for a new combination of types.
    - Add your cases in the corresponding operation type file(mult.cc/add.cc/div.cc/cast.cc).
    - Refer to these files for the exact details.
3. If you add a case with a new operator make sure to run the cases in `main.cc`.
