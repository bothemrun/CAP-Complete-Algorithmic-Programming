/**
 * @return {Object}
 */
var createInfiniteObject = function() {
    //Proxy. closure.
    const handler = {
        get: function(obj, prop){
            return function(){
                return prop;
            };
        },
    };
    return new Proxy({}, handler);
};

/**
 * const obj = createInfiniteObject();
 * obj['abc123'](); // "abc123"
 */
