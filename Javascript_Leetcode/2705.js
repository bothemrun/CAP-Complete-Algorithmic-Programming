//m0
//recursion

//NOTE: for in array would skip some undefined fo arrays with holes.

/**
 * @param {Object} obj
 * @return {Object}
 */
var compactObject = function(obj) {
    
    function recur(obj){
        //NOTE: typeof null is object
        //NOTE: empty arrays and empty objects are not falsy
        //NOTE: their Boolean() not false.
        if( Boolean(obj) === false) return false;
        //typeof array is object
        if( (typeof obj) !== (typeof {}) ) return obj;

        /*if((typeof obj) !== (typeof {})){
            //NOTE: typeof array === object
            return ( Boolean(obj) === false)? false:obj;
        }*/

        if( Array.isArray(obj) === true){
            const compact = [];
            
            for(const e of obj){
                const sub_compact = recur(e);

                if(sub_compact !== false)
                    compact.push(sub_compact);
            }

            //ok for empty arrays or array of all falsy
            return compact;
        }


        const compact = {};
        for(const prop in obj){
            const sub_compact = recur( obj[prop] );

            if(sub_compact !== false)
                compact[prop] = sub_compact;
        }

        //ok for empty objects or object of all falsy
        return compact;
    }

    return recur(obj);
};
