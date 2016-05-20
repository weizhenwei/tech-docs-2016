
console.log("before");
console.log(global);
global.test = "This is a global global string";
global.testFun = function() {
    console.log("This is a global function.");
};

console.log("after");
console.log(global);

// same as print global;
// console.log(GLOBAL);
// console.log(global.GLOBAL);

