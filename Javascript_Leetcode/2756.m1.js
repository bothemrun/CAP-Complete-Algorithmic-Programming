//m1
//object prototype to class

//without using Date.now() as in solutions.
//set timer for locking / unlocking waiting throttle.
//when unlocking, if there are still requests in queue, call batch processing function again.

class QueryBatcher{
/**
 * @param {Function} queryMultiple
 * @param {number} t
 */
    constructor(queryMultiple, t){
        this.fn = queryMultiple;
        this.t = t;

        this.keys = [];
        this.resolves = [];

        this.wait = false;
    }

    set_throttle(){
        this.keys = [];
        this.resolves = [];

        this.wait = true;

        //NOTE: this in default function is the global object, 
        //In arrow functions, this retains the value of the enclosing lexical context's this
https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/this

        //setTimeout(function(){
        setTimeout(() => {
            this.wait = false;

            if(this.keys.length !== 0) this.call_batch();
        }, this.t);
    }

    async call_batch(){
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
    }

/**
 * @param {string} key
 * @returns Promise<string>
 */
    getValue(key){
        const batcher = this;

        return new Promise((resolve, reject) => {
            batcher.keys.push(key);
            batcher.resolves.push(resolve);

            if(batcher.wait === false) batcher.call_batch();
        });
    }
};

/*
var QueryBatcher = function(queryMultiple, t) {
        
};

QueryBatcher.prototype.getValue = async function(key) {
        
};
*/


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
