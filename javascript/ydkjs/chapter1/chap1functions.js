const TAX_RATE = 0.08;

function calculateFinalPruchaseAmount(amt) {
  //calculate amount plus TAX
  amt = amt + (amt * TAX_RATE);

  //return final amount
  return amt;

}

var amount = 80.99;

amount = calculateFinalPruchaseAmount(amount);
console.log(amount.toFixed(2));
