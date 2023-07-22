//m2
//use await

//no return. or return undefined precisely.
//then async automatically wraps it with a Promise
/**
 * @param {number} millis
 */
async function sleep(millis) {
    //await setTimeout(resolve, millis);
    await new Promise((resolve, reject) => {
        setTimeout(resolve, millis);
    });
}

/** 
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */
