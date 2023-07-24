Date.prototype.nextDay = function() {
    const n = new Date(this.getTime() + 24*60*60*1000);

    let month = n.getMonth() + 1;
    if(month <= 9) month = "0" + month;

    let date = n.getDate();
    if(date <= 9) date = "0" + date;

    return `${ n.getFullYear() }-${ month }-${ date }`;
}

/**
 * const date = new Date("2014-06-20");
 * date.nextDay(); // "2014-06-21"
 */
