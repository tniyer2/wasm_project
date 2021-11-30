
Module.onRuntimeInitialized = () => {
	let js_wrapped_fib = Module.cwrap("calc_fibonacci", "number", ["number"]);
	let result = js_wrapped_fib(7);
	console.log("FROM WASM FUNCTION CALL - The 7th Fibonacci number is " + result);

	let times = [];
	let num_times = 100;

	for (let i = 0; i < num_times; i++) {
		let t = Date.now();
		js_wrapped_fib(23);
		t = Date.now() - t;
		times.push(t);
	}
	console.log(times);
	let benchmark = times.reduce((a, b) => a + b, 0) / num_times;

	console.log("Calling WASM from javascript 100 times has an average benchmark of: " + benchmark + " milliseconds");
};
