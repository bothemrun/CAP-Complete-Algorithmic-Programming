//m1
//use class instead of object.prototype.

class TimeLimitedCache{
    constructor(){
        //need timeout id for clearTimeout()
        this.memo = new Map();
    }

/** 
 * @param {number} key
 * @param {number} value
 * @param {number} duration time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
    set(key, value, duration){
        const has = this.memo.has(key);
        if(has === true){
            clearTimeout(this.memo.get(key).timeout_id);
        }

        //NOTE: for duration=0, although event queue won't execute setTimeout callback immediately,
        //NOTE: this is more clear.
        this.memo.set(key, {
            value: value,
            timeout_id: (-1)
        });
        const timeout_id = setTimeout(() => {
            this.memo.delete(key);
        }, duration);
        this.memo.set(key, {
            value: value,
            timeout_id: timeout_id
        });

        return has;
    }

/** 
 * @param {number} key
 * @return {number} value associated with key
 */
    get(key){
        if(this.memo.has(key) === true) return this.memo.get(key).value;
        else return (-1);
    }

/** 
 * @return {number} count of non-expired keys
 */
    count(){
        return this.memo.size;
    }
};

/**
 * Your TimeLimitedCache object will be instantiated and called as such:
 * var obj = new TimeLimitedCache()
 * obj.set(1, 42, 1000); // false
 * obj.get(1) // 42
 * obj.count() // 1
 */
