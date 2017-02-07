const TAX_RATE = 0.047;
const PHONE_PRICE = 99.99;
const PHONE_ACCESSORY = 15.99;

var mentalSpendingThreshold = Number(prompt("How much would you like to spend?"));
var bankAccount = Number(prompt("How much is in your bank account"));
var amount = 0;
var total = 0;
var finalPrice = 0;
var formattedPrice = 0;
var numberofPhones = 0;
var numberOfAccessories = 0;
var order;


//need to purchase phones until I run out of money
while( mentalSpendingThreshold > PHONE_PRICE) {
  //I'll buy accerories for eaxh phone as long as i have money for it
  if ( mentalSpendingThreshold > PHONE_PRICE + PHONE_ACCESSORY ) {
    //Find the purchase amount
    amount = PHONE_PRICE + PHONE_ACCESSORY;
    //keep track of order
    numberofPhones += 1;
    numberOfAccessories +=1;
  } else {
    amount = PHONE_PRICE;
    //keep track of order
    numberofPhones += 1;
  }
  //subtract the amount from the spending threshold
  mentalSpendingThreshold -= amount;

    //add the amount to the final total
  total += amount;
}

finalPrice = calculateFinalPrice(total);
formattedPrice = formatPrice(finalPrice);
order = formatOrder(numberofPhones, numberOfAccessories);


//Check to see if you can affor the ammount and print out to the console if the user can afford it
if ( finalPrice <= bankAccount ) {
  console.log( order + "Your total will be " + formattedPrice + " Which you can afford!");
} else {
  console.log( order + "your total will be " + formattedPrice + " Which you can not afford!" );
}

//A function to find the total with tax
function calculateFinalPrice(amt) {
  var final = amt + (amt * TAX_RATE);
  return final;
}

//A function to see the price as a dollar value with only 2 digits after the decimal
function formatPrice(amt){
  var formatedPrice = "$" + String(amt.toFixed(2));
  return formatedPrice;
}

//A function to add the number of phones and accesories into a sentence
function formatOrder( phns, accs) {
  var order = "You ordered " + phns + " phones and " + accs + " accessories.";
  return order;
}
