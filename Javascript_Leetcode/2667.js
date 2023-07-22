/**
 * @return {Function}
 */
var createHelloWorld = function() {
    //closure

    //rest parameter
    return function(...args) {
        return "Hello World";
    }
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */
