//Dynamic Type


var amount = 9.99;
amount = amount *2;   //199.98

/**
Convert 'amount' to a string
and add $ to the beginning
*/
amount = '$' + String(amount);
console.log( amount );


//Constants

var TAX_RATE = 0.08;    //8% TAX_RATE

//as of es6 you can declare Constants
//const TAX_RATE = 0.09;

var amount = 9.99;

amount = amount * 2;
amount = amount + (amount * TAX_RATE);

console.log(amount);
console.log(amount.toFixed(2));   //toFixed lets you declare the decimal points


//loops

for (var i =0; i < 10; i++) {
  console.log( i );
}


//functions

function printAmount(amt) {
  console.log(amt.toFixed(2));
}

function formatAmount() {
  return "$" + amount.toFixed(2);
}

var amount = 99.99;

printAmount(amount * 2);

amount = formatAmount();
console.log(amount);
