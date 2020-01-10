const { Arithmetic } = require("./build/Release/testaddon.node");

const calc = new Arithmetic();

calc.add(1);
calc.sub(2);
console.log(calc.getTotal());

module.exports = Arithmetic;
