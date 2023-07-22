//m0
//naive merge, then sort
/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function(arr1, arr2) {
    const merged = {};
    for(const obj of arr1)
        merged[obj.id] = obj;
    
    for(const obj of arr2){
        if(obj.id in merged){
            for(const prop in obj){
                merged[obj.id][prop] = obj[prop];
                //NOTE: it looks for the property name called "prop",
                //NOTE: not the string content in the variable prop.
                //merged[obj.id].prop = obj[prop];
            }
        }else{
            merged[obj.id] = obj;
        }
    }

    const arr = Array(merged.length);
    let i = 0;
    for(const prop in merged)
        arr[i++] = merged[prop];
    
    arr.sort(function(a, b){
        return a.id - b.id;
    });

    return arr;
};
