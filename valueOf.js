/**
 * @param {number[]} nums
 */
let val=[];
var ArrayWrapper = function(nums) {
    val.push(nums);
};

ArrayWrapper.prototype.valueOf = function() {
    let sum=0;
    console.log(val)
    for(let i=0;i<val.length;i++){
        if(val[i]!==undefined) val[i].forEach(num=>sum+=num);
    }
    val=[];
    return sum;
}

ArrayWrapper.prototype.toString = function() {
    let res=JSON.stringify(val[0]);
    val=[];
    return res;
}

/**
 * const obj1 = new ArrayWrapper([1,2]);
 * const obj2 = new ArrayWrapper([3,4]);
 * obj1 + obj2; // 10
 * String(obj1); // "[1,2]"
 * String(obj2); // "[3,4]"
 */
