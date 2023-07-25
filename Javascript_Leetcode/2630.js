//stupid problem description: 
//the input is always an array of objects or other types.
//and two inputs are considered the same if all their array elements satisfy === relationship.

//example: compare inputs like: 
//1. two [2, 2] inputs (considered === same inputs) & 
//2. two [2, [2, 2]] inputs (considered not ===, different inputs)

//so we can use Map()
//according to the key equality section of: 
// https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Map

//quoted, "This means NaN is considered the same as NaN (even though NaN !== NaN) and all other values are considered equal according to the semantics of the === operator.", unquoted

//so the problem rules out the input array element with NaN.


//so refer to user 981377660LMT:
// https://leetcode.com/problems/memoize-ii/solutions/3408324/assign-id-to-object-without-trie/

//(1) use Map() for array element checking, 
//(2) then the comparison result to an ID.
//(3) concat all the ID to a string by a delimiter.
//(4) and that's the key for the object map memo.

/**
 * @param {Function} fn
 */
function memoize(fn) {
    const memo = {};

    const delimiter = "$";

    const array_element_map = new Map();
    function array_element_map_get(element_obj){
        //so array elements like [2, 2] & {a: 3} will always not get.
        //since [2, 2] !== [2, 2] and the same for {a:3}
        if(array_element_map.has(element_obj) === true)
            return array_element_map.get(element_obj);
        
        array_element_map.set(element_obj, array_element_map.size);
        return array_element_map.size - 1;
    }

    function get_key(array_args){
        return array_args.map(function(element_obj){
            return array_element_map_get(element_obj);
        }).join(delimiter);
    }

    return function(...args) {
        const key = get_key(args);

        if(key in memo) return memo[key];
        else return memo[key] = fn(...args);//spread syntax
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */
