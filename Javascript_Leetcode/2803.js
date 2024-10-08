/**
 * @param {number} n
 * @yields {number}
 */
function* factorial(n) {
    if(n==0) return 1;
    
    let fac = 1;
    for(let i=1;i<=n;i++){
        fac *= i;
        yield fac;
    }
};


/**
 * const gen = factorial(2);
 * gen.next().value; // 1
 * gen.next().value; // 2
 */
