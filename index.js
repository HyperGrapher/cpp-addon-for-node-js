const calculate = require("./build/Release/calculate");

const calc = () => {
	let x = 100.32462344;
	const y = 200.333456533452;

	for (let i = 0; i < 1000000000; i++) {
		x += y;
	}

	return x;
};

console.time("js");
calc();
console.timeEnd("js");

console.time("c++");
calculate.calc();
console.timeEnd("c++");
