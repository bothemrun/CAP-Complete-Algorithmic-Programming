/**
 * @param {string} start
 * @param {string} end
 * @param {number} step
 * @yields {string}
 */
var dateRangeGenerator = function* (start, end, step) {
    const start_time = (new Date(start)).getTime();
    const end_time = (new Date(end)).getTime();

    //same as toISOString()
    function time2year_month_date(time){
        const d = new Date(time);
        const year = d.getFullYear();
        let month = d.getMonth() + 1;
        let date = d.getDate();

        function pad(num){
            if(num <= 9) return "0" + num;
            else return String(num);
        }

        month = pad(month);
        date = pad(date);

        return `${ year }-${ month }-${ date }`
    }

    let cur_time = start_time;
    const step_time = step * 24 * 60 * 60 * 1000;
    while(true){
        yield time2year_month_date(cur_time);

        cur_time += step_time;
        if(cur_time > end_time) return;
    }
};

/**
 * const g = dateRangeGenerator('2023-04-01', '2023-04-04', 1);
 * g.next().value; // '2023-04-01'
 * g.next().value; // '2023-04-02'
 * g.next().value; // '2023-04-03'
 * g.next().value; // '2023-04-04'
 * g.next().done; // true
 */
