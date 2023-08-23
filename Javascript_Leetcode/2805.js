/**
 * @param {Function} fn
 * @param {number} delay
 * @param {number} period
 * @return {number} id
 */

const fake2setTimeout = [];

function customInterval(fn, delay, period){
    //closure
    const fake_id = fake2setTimeout.length;

    let timeout = delay;

    function exec_timer(){
        fn();

        timeout += period;

        fake2setTimeout[fake_id] = setTimeout(exec_timer, timeout);
    }

    fake2setTimeout.push( setTimeout(exec_timer, timeout) );
    return fake_id;
}

/**
 * @param {number} id
 */
function customClearInterval(id) {
    const fake_id = id;
    clearTimeout( fake2setTimeout[fake_id] );
}
