/**
 * @param {any} object
 * @return {string}
 */
var jsonStringify = function(object) {
    if(object === null) return "null";

    if(Array.isArray(object) === true){
        const arr = object.map((element) => {
            return jsonStringify(element);
        });

        return `[${ arr.join(",") }]`
    }

    if(typeof object === typeof {}){
        const keys = Object.keys(object);

        const key_value_arr = keys.map(function(key){
            return `"${ key }":${ jsonStringify(object[key]) }`
        });

        return `{${ key_value_arr.join(",") }}`
    }

    if(typeof object === typeof "hi") return `"${ object }"`;

    return String(object);
};
