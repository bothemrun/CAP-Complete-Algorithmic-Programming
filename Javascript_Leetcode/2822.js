/**
 * @param {Object} obj
 * @return {Object}
 */
var invertObject = function(obj) {
    const inv = {};
    for(const [key, val] of Object.entries(obj) ){
        if(val in inv){
            if(typeof inv[val] === typeof []){
                //no duplicate keys for the original object
                inv[val].push(key);
            }else{
                inv[val] = [ inv[val], key ];
            }
        }else{
            inv[val] = key;
        }
    }

    return inv;
};
