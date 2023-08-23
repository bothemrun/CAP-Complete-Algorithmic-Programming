//m0
//without using Date.now() as in solutions.
//set timer for locking / unlocking waiting throttle.
//when unlocking, if there are still requests in queue, call batch processing function again.

/**
 * @param {Function} queryMultiple
 * @param {number} t
 */
var QueryBatcher = function(queryMultiple, t) {
    this.fn = queryMultiple;
    this.t = t;

    this.keys = [];
    this.resolves = [];

    this.wait = false;
};

/**
 * @param {string} key
 * @returns Promise<string>
 */
QueryBatcher.prototype.getValue = async function(key) {
    const batcher = this;
    return new Promise((resolve, reject) => {
        this.keys.push(key);
        this.resolves.push(resolve);

        if(this.wait === false) this.call_batch();
    });
};

QueryBatcher.prototype.set_throttle = function(){
    this.keys = [];
    this.resolves = [];
    this.wait = true;

    setTimeout(() => {
        this.wait = false;

        if(this.keys.length !== 0) this.call_batch();

    }, this.t);
};

QueryBatcher.prototype.call_batch = async function(){
    //NOTE: must copy, 
    //NOTE: since fn takes time, and new requests will come,
    //NOTE: we can't blend old & new batches.

    //NOTE: also, can't use keys = this.keys --> copy of reference
    //NOTE: use .slice() for deep copy
    const keys = this.keys.slice();
    const resolves = this.resolves.slice();

    this.set_throttle();

    const results = await this.fn(keys);
    for(let i=0;i<results.length;i++)
        resolves[i]( results[i] );
};

/**
 * async function queryMultiple(keys) { 
 *   return keys.map(key => key + '!');
 * }
 *
 * const batcher = new QueryBatcher(queryMultiple, 100);
 * batcher.getValue('a').then(console.log); // resolves "a!" at t=0ms 
 * batcher.getValue('b').then(console.log); // resolves "b!" at t=100ms 
 * batcher.getValue('c').then(console.log); // resolves "c!" at t=100ms 
 */
