//m1
//{...old, ...new} spread syntax in object {},
//it concats and handles duplicates.

/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function(arr1, arr2) {
    //spread syntax with array
    const concat = [...arr1, ...arr2];

    //spread syntax with object, it handles duplicates
    const merged = {};
    for(const obj of concat){
        if(obj.id in merged){
            //spread syntax with object, concat while handling duplicates.
            merged[obj.id] = {...merged[obj.id], ...obj};
        }else{
            merged[obj.id] = obj;
        }
    }


    //NOTE: not new Array(length)
    const arr = Array(merged.length);
    let i = 0;
    for(const prop in merged){
        arr[i++] = merged[prop];
        //NOTE: not merged.prop.
        //since it will look for property names called "prop",
        //not the string / expression content in the variable prop.
    }

    arr.sort(function(a, b){
        return a.id - b.id;
    });

    return arr;
};
