//m1
//use reduce( callback(accumulator, current_value, current_index, arr), initial_accumulator )
//where accumulator is an object.

/**
 * @param {Function} fn
 * @return {Array}
 */
Array.prototype.groupBy = function(fn) {
    return this.reduce( function(obj_accumulator, cur_val){
        const s = fn(cur_val);

        //in editorial solution, can also use logicial or assignment on this obj.
        if(s in obj_accumulator) obj_accumulator[s].push(cur_val);
        else obj_accumulator[s] = [cur_val];

        return obj_accumulator;
    }, {} );
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */
