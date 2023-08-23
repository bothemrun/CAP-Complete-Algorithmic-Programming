/**
 * @param {Function} fn
 * @param {Array} args
 * @return {Function}
 */
var partial = function(fn, args) {
    
    return function(...restArgs) {
        let i_rest = 0;
        for(let i=0;i<args.length;i++)if(args[i] === "_"){
            args[i] = restArgs[ i_rest++ ];
        }

        return fn(...args, ...restArgs.slice(i_rest) );
    }
};
