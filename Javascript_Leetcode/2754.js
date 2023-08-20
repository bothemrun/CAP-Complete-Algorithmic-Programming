//m0
/**
 * @param {Object} obj
 * @return {Function}
 */
Function.prototype.bindPolyfill = function(obj) {
    //object method this.
    const object_method_this = this;
    return function(...args){
        //default funciton (not object method) this refers to the global object(eg., the window).
        return object_method_this.call(obj, ...args);
    };
}
