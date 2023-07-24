/**
 * @param {number} rowsCount
 * @param {number} colsCount
 * @return {Array<Array<number>>}
 */
Array.prototype.snail = function(rowsCount, colsCount) {

    function int_division(a, b){
        const q = a/b;//float
        return (q < 0)? Math.ceil(q):Math.floor(q);
    }

    if(rowsCount * colsCount !== this.length) return [];
    
    const arr = [];
    for(let r=0;r<rowsCount;r++)
        arr.push([]);
    
    for(let i=0;i<this.length;i++){
        //const col = i / rowsCount;
        const col = int_division(i, rowsCount);
        
        const row = i % rowsCount;

        if(col % 2 === 0){
            arr[ row ].push(this[i]);
        }else{
            arr[ rowsCount-1 - row ].push(this[i]);
        }
    }

    return arr;
}

/**
 * const arr = [1,2,3,4];
 * arr.snail(1,4); // [[1,2,3,4]]
 */
