const io = require('console-read-write');

function factor(number){
  const factors = [];
  let i=2;
  while(number>=2){ //&& i < Math.floor(number/2)){
    if(number % i === 0){
      factors.push(i);
      number /= i;
      i = 2;
      continue;
    }
    i++;
  }
  return factors;
}

function print_factors(num){
  const factors = factor(num);
  console.log("The prime factors of " + num + " are: " + factors.toString())
}

async function main(){
  while(true){
	  console.log("Enter a number to factor:");
	  let inp = await io.read();
	  if(inp==="exit"){
		  console.log("Goodbye.");
		  break;
	  }
	  print_factors(inp);
	  console.log("Enter \"exit\" to exit.\n");
  }
}

main();
