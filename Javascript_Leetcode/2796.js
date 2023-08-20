String.prototype.replicate = function(times) {
    let repeat = "";
    for(let i=0;i<times;i++){
        repeat += this;
    }
    return repeat;
}
