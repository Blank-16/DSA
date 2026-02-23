/**
 * @return {Generator<number>}
 */
var fibGenerator = function*() {
    let a = 0;
    let b = 1;
    while(true) {
        yield a;
        [a, b] = [b, a+b];
    }
};

/**
 * const gen = fibGenerator();
 * gen.next().value; // 0
 * gen.next().value; // 1
 */


// generate function is a special type of function that produces values one at a time 
// on demand, on demand instead of comuting and returning all values at once 
//
//
//
//The yield keyword is used inside a generator function to:

// Pause the function
// Return a value
// Resume later from the same place

// It’s what makes generator functions special.
