//my Full-Stack Notes:

//Js this / call(thisArg, arg1, /*...*/ , argN) vs bind(thisArg, arg1, /*...*/ , argN)

//lender_object.function_property.call / bind(  borrower object  )

//The this in lender_object function refers to the borrower object.

//https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Function/bind

//call() returns the result / bind() returns the function.

//const boundFn = fn.bind(thisArg, arg1, arg2) as being equivalent to const boundFn = (...restArgs) => fn.call(thisArg, arg1, arg2, ...restArgs)

//This keyword:

//Usually refers to the object itself.
//https://www.w3schools.com/js/js_this.asp

//Js call(thisArg, arg1, /*...*/ , argN) vs apply(thisArg, argsArray)
https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Function/apply


/**
 * @param {Object} context
 * @param {any[]} args
 * @return {any}
 */
Function.prototype.callPolyfill = function(context, ...args) {
    //"this" is the lender function, and pass in a borrower_object_this
    //https://www.w3schools.com/js/js_function_call.asp

    return this.call(context, ...args);//spread syntax
}

/**
 * function increment() { this.count++; return this.count; }
 * increment.callPolyfill({count: 1}); // 2
 */
