//a module that converts celsius to fahrenheit and vice versa

function convertTemp() {

    //takes a degree in fahrenheit and converts it to celsius
    function fahrenheitToCelsius(f) {
      var celsius = ( f - 32 ) * ( 9 / 5) ;
      return celsius;
    }

    //takes a degree in celsius and converts it to fahrenheit
    function celsiusToFahrenheit (c) {
      var fahrenheit = ( c * ( 9 / 5) ) + 32;
      return fahrenheit;
    }

    //returns inner functions which have closure over private scope
    return {
      fahrenheitToCelsius: fahrenheitToCelsius,
      celsiusToFahrenheit: celsiusToFahrenheit
    };

}


var temp = convertTemp();

console.log(temp.fahrenheitToCelsius(32));
console.log(temp.celsiusToFahrenheit(0));
