/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array[]}
 */

function solve(arr,main,size){
    if(arr.length>=size){
        main.push(arr.splice(0,size));
        // console.log(arr,main)
        if(arr.length===0){
            return main;
        }else{
            solve(arr,main,size);
        }
    }else{
        main.push(arr);
    }
    return main;
}

var chunk = function(arr, size) {
    let res=[];
    if(!arr.length) return arr;
    return solve(arr,res,size);
};
