/**
 * @param {Array} keysArr
 * @param {Array} valuesArr
 * @return {Object}
 */
var createObject = function(keysArr, valuesArr) {
    const obj = {};
    const n = keysArr.length;
    for(let i=0;i<n;i++){
        const key = String(keysArr[i]);
        if( (key in obj) === false){
            obj[ key ] = valuesArr[i];
        }
    }

    return obj;
};
