//m2
//merge sort, two pointers

//also use {...obj1, obj2} spread syntax with object {}, 
//it concats while handles duplicates
//(obj2 values replaces obj1 content if duplicate properties)

/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function(arr1, arr2) {

    function cmp_fn(a, b){
        return a.id - b.id;
    }
    arr1.sort(cmp_fn);
    arr2.sort(cmp_fn);
    
    const merged = [];
    let i = 0, j = 0;
    while(i<arr1.length && j<arr2.length){
        if(arr1[i].id < arr2[j].id){
            merged.push(arr1[i++]);
        }else if(arr1[i].id > arr2[j].id){
            merged.push(arr2[j++]);
        }else{
            merged.push( {...arr1[i++], ...arr2[j++] } );
        }
    }

    while(i<arr1.length){
        merged.push(arr1[i++]);
    }

    while(j<arr2.length){
        merged.push(arr2[j++]);
    }

    return merged;
};
