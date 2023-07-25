//will only contain alphanumeric characters.
/**
 * @param {string} str
 * @return {*}
 */
var jsonParse = function(str) {
    let index = 0;
    
    function json2object_recur(){
        const c = str[index];

        if(c === "{"){
            return parse_object();
        }else if(c === "["){
            return parse_array();
        }else if(c === "\""){
            return parse_string();
        }else if(c === "t"){
            return parse_true();
        }else if(c === "f"){
            return parse_false();
        }else if(c === "n"){
            return parse_null();
        }else if( isdigit(c) || c === "-" ){
            return parse_number();
        }else return undefined;
    }

    function parse_object(){
        const obj = {};

        index++;//skip opening brace "{"

        while(str[index] !== "}"){
            const key = parse_string();

            index++;//skip ":"

            obj[key] = json2object_recur();

            //index < str.length, due to closing brace "}"
            if(str[index] === ","){
                index++;
            }
        }

        index++;//skip closing brace "}"

        return obj;
    }

    function parse_string(){
        //str[end + 1] must exist due to closing "\""

        //NOTE: not include invisible characters and escape characters. 
        //only contain alphanumeric characters.
        
        index++;//skip opening "\""
        const start = index;
        //[start, end)
        const end = str.indexOf("\"", index);

        const s = str.slice(start, end);
        index = end + 1;
        return s;
    }

    function parse_array(){
        const arr = [];

        index++;//skip opening "["

        while(str[index] !== "]"){
            arr.push( json2object_recur() );

            //index < str.length, due to closing "]"
            if(str[index] === ","){
                index++;
            }
        }

        index++;//skip closing "]"

        return arr;
    }

    function parse_true(){
        index += 4;//skip true
        return true;
    }

    function parse_false(){
        index += 5;//skip false
        return false;
    }

    function parse_null(){
        index += 4;//skip null
        return null;
    }

    function isdigit(c){
        return "0" <= c && c <= "9";
    }

    function parse_number(){
        //includes negative, floating numbers.
        const start = index;//can include negative sign
        //[start, end] inclusive
        let end = index;

        //1. negative sign
        if(str[end] === "-") end++;//skip "-" negative sign

        //2. integer part
        while( end+1 < str.length && isdigit( str[end+1] ) ){
            end++;
        }

        //3. floating part
        if( end+1 < str.length && str[end+1] === "." ){
            end++;
        }

        while( end+1 < str.length && isdigit( str[end+1] ) ){
            end++;
        }

        index = end + 1;

        return Number( str.slice(start, end + 1) );
    }

    return json2object_recur();
};
